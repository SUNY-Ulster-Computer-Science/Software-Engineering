// clang-format off

// Fast inverse square root
// Original code by Greg Walsh (often attributed to John Carmack), popularized by Quake III Arena

// This function computes an approximation to the inverse square root of a float number (1/sqrt(x)).
// It is known for its speed and was widely used in graphics programming.

// ===========================================================================

float Q_rsqrt( float number )
{
	long i;
	float x2, y;
	const float threehalfs = 1.5F;

	x2 = number * 0.5F;
	y  = number;
	i  = * ( long * ) &y;                       // evil floating point bit level hacking
	i  = 0x5f3759df - ( i >> 1 );               // WTF?
	y  = * ( float * ) &i;
	y  = y * ( threehalfs - ( x2 * y * y ) );   // 1st iteration
//	y  = y * ( threehalfs - ( x2 * y * y ) );   // 2nd iteration, this can be removed

	return y;
}

// ===========================================================================

// Explanation:
// * i is used for force-cast y (an alias for the float value) to manipulate its bit representation directly.
// * The magic number 0x5f3759df is the floating point representation of sqrt(2^127).
// * The subtraction and right shift approximate 1/sqrt(x) with some error.
// * The number is then force-cast back to a float.
// * The final line applies one iteration of Newton's method to refine the approximation.
// * Newton's method follows the slope of a function to better approximate the root (here, the true value of 1/sqrt(x)).
// * A second iteration can be added for more accuracy, but at the cost of speed.

// All of this information is missing from the original code, making it hard to understand without prior knowledge.
