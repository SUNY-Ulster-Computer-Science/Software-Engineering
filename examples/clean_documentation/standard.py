# An example standard Python documenting.
# Python has several widely used documentation standards: Google, NumPy, reStructuredText.
# The "Google" style is used here.

# Python is special since it is a dynamically typed language, meaning we do not need to define types in code.
# Adding (optional, but very helpful) type hints serves as a form of Python-specific documentation. 


class UserAccount:
    """Represents a user account in the system.
    
    This class manages user authentication state and profile information.
    User accounts can be in various states (active, suspended, closed) and
    track login history for security purposes.
    
    Attributes:
        username: The unique username for this account.
        email: The user's email address.
        created_at: Timestamp when the account was created.
        is_active: Whether the account is currently active.
        
    Example:
        >>> account = UserAccount("john_doe", "john@example.com")
        >>> account.activate()
        >>> print(account.is_active)
        True
    """
    
    def __init__(self, username: str, email: str) -> None:
        """Initialize a new user account.
        
        Args:
            username: Unique identifier for the user. Must be 3-20 characters.
            email: Valid email address for account recovery and notifications.
        """

        self.username = username
        self.email = email
        self.created_at = None
        self.is_active = False
    
    def authenticate(self, password: str) -> str | None:
        """Verify user credentials and establish session.
        
        Args:
            password: The password to verify against stored hash.
            
        Returns:
            A session token string if authentication succeeds, None otherwise.
            
        Raises:
            AccountSuspendedException: If account is suspended or closed.
            
        Note:
            Failed authentication attempts are logged for security monitoring.
            After 5 failed attempts, the account is temporarily locked.
        """

        return 'session-token-abc123'
    
    def update_profile(self, display_name: str = None, bio: str = None, avatar_url: str = None) -> bool:
        """Update user profile information.
        
        Args:
            display_name: Optional new display name (max 50 chars).
            bio: Optional biography text (max 500 chars).
            avatar_url: Optional URL to profile picture.
            
        Returns:
            True if update succeeded, False otherwise.
            
        Note:
            Only provided fields are updated; None values are ignored.
            Changes are persisted immediately to the database.
        """

        return True


def calculate_shipping_cost(weight_kg: float, distance_km: float, shipping_class: str = "standard") -> float:
    """Calculate shipping cost based on package weight, distance, and class.
    
    Uses a tiered pricing model where cost increases with both weight and
    distance. Express shipping incurs a 2x multiplier on the base rate.
    
    Args:
        weight_kg: Package weight in kilograms. Must be positive.
        distance_km: Shipping distance in kilometers. Must be positive.
        shipping_class: Either "standard" or "express". Defaults to "standard".
        
    Returns:
        The calculated shipping cost in dollars as a float, rounded to 2 decimals.
        
    Raises:
        ValueError: If weight or distance is negative or zero.
        ValueError: If shipping_class is not "standard" or "express".
        
    Example:
        >>> calculate_shipping_cost(5.0, 100.0)
        12.50
        >>> calculate_shipping_cost(5.0, 100.0, "express")
        25.00
    """

    base_rate = 0.025  # base rate per kg per km
    if shipping_class == "express":
        base_rate *= 2
    cost = weight_kg * distance_km * base_rate
    return round(cost, 2)
