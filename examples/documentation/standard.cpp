// An example standard C++ documenting.
// C++ comments use Doxygen style.

// C++ is a strongly and statically typed language.
// It has syntactical type definitions.

#include <string>
#include <vector>
#include <memory>

// Forward declaration of Connection class and PoolStats struct
struct PoolStats;
class Connection;

/**
 * @brief Manages database connection pooling for improved performance.
 *
 * This class maintains a pool of reusable database connections to avoid
 * the overhead of creating new connections for each query. Connections
 * are thread-safe and automatically returned to the pool when released.
 *
 * The pool uses a fixed size with blocking behavior when all connections
 * are in use. Idle connections are kept alive with periodic heartbeat queries.
 *
 * @note This class is thread-safe for concurrent access.
 * @warning Connections must be explicitly released back to the pool via
 *          release() or using RAII wrapper. Leaked connections will exhaust
 *          the pool and cause deadlocks.
 *
 * Example usage:
 * @code
 * ConnectionPool pool("localhost", 5432, "mydb", 10);
 * auto conn = pool.acquire();
 * conn->execute("SELECT * FROM users");
 * pool.release(conn);
 * @endcode
 *
 * @see Connection
 * @author Database Team
 * @version 1.2.0
 * @since 1.0.0
 */
class ConnectionPool
{
public:
    /**
     * @brief Constructs a new connection pool.
     *
     * Initializes the specified number of database connections. This
     * constructor blocks until all initial connections are established
     * or the timeout is reached.
     *
     * @param host Database server hostname or IP address
     * @param port Database server port (typically 5432 for PostgreSQL)
     * @param database Name of the database to connect to
     * @param poolSize Number of connections to maintain (recommended: 10-50)
     * @param timeoutMs Connection timeout in milliseconds (default: 5000)
     *
     * @throws ConnectionException if unable to establish initial connections
     * @throws std::invalid_argument if poolSize < 1 or port is invalid
     *
     * @pre host and database must be non-empty strings
     * @post Pool contains exactly poolSize ready connections
     */
    ConnectionPool(const std::string &host,
                   int port,
                   const std::string &database,
                   size_t poolSize,
                   int timeoutMs = 5000);

    /**
     * @brief Acquires a connection from the pool.
     *
     * Returns an available connection from the pool. If no connections are
     * available, this method blocks until one is released or the timeout
     * expires. The caller is responsible for returning the connection via
     * release() when finished.
     *
     * @param timeoutMs Maximum time to wait for a connection in milliseconds.
     *                  Use 0 for non-blocking (fails immediately if none available).
     *                  Use -1 for infinite wait. Default: 30000 (30 seconds).
     *
     * @return Shared pointer to an active database connection, or nullptr if
     *         timeout expires without acquiring a connection
     *
     * @throws PoolClosedException if pool has been shut down
     *
     * @warning The returned connection remains "checked out" until released.
     *          Failing to release connections will exhaust the pool.
     *
     * @see release()
     */
    std::shared_ptr<Connection> acquire(int timeoutMs = 30000);

    /**
     * @brief Returns a connection to the pool for reuse.
     *
     * Marks the connection as available for other callers. If the connection
     * is in an error state or has been idle too long, it may be recycled
     * (closed and replaced with a new connection).
     *
     * @param conn The connection to return (must have been acquired from this pool)
     *
     * @pre conn must be a valid connection previously obtained from acquire()
     * @post conn is marked as available and may be returned by future acquire() calls
     *
     * @note Releasing the same connection multiple times is safe (no-op after first)
     * @note Passing nullptr is safe (no-op)
     */
    void release(std::shared_ptr<Connection> conn);

    /**
     * @brief Gets current pool statistics.
     *
     * @return PoolStats structure containing:
     *         - totalConnections: Pool size
     *         - availableConnections: Connections ready for use
     *         - activeConnections: Connections currently in use
     *         - waitingClients: Number of threads waiting for a connection
     *
     * @note This is a snapshot and may change immediately after return
     */
    PoolStats getStats() const;

private:
    std::vector<std::shared_ptr<Connection>> connections_;
};

/**
 * @brief Executes a database transaction with automatic rollback.
 *
 * This function template provides RAII-style transaction management. The
 * transaction is automatically committed if the callback completes without
 * throwing an exception, or rolled back if an exception occurs.
 *
 * @tparam Func Callable type (function, lambda, functor)
 * @tparam Args Argument types to pass to the callable
 *
 * @param conn Database connection to use for the transaction
 * @param callback Function to execute within the transaction
 * @param args Arguments to forward to the callback
 *
 * @return The return value from the callback function
 *
 * @throws Any exception thrown by the callback (transaction is rolled back)
 * @throws TransactionException if BEGIN/COMMIT/ROLLBACK fails
 *
 * Example usage:
 * @code
 * auto result = executeTransaction(conn, [](Connection* c, int userId) {
 *     c->execute("UPDATE accounts SET balance = balance - 100 WHERE id = ?", userId);
 *     c->execute("INSERT INTO transactions (user_id, amount) VALUES (?, -100)", userId);
 *     return c->lastInsertId();
 * }, 42);
 * @endcode
 *
 * @note Nested transactions are not supported. Calling this with a connection
 *       already in a transaction will throw an exception.
 */
template <typename Func, typename... Args>
auto executeTransaction(std::shared_ptr<Connection> conn,
                        Func callback,
                        Args &&...args) -> decltype(callback(conn.get(), std::forward<Args>(args)...));
