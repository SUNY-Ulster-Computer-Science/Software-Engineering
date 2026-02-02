# ============================================================================
# Example of unhelpful inline comments and lack of naming clarity
# ============================================================================

def process(data):
    # Process the data
    result = []
    # Loop through data
    for item in data:
        # Check if item is valid
        if item > 0:
            # Add to result
            result.append(item * 0.5)
    # Return result
    return result

# Problems:
# - Comments just repeat what the code already says
# - No explanation of WHY we're doing this
# - Doesn't explain the business logic (why multiply by 0.5? why only positive?)


# ============================================================================
# Example of improved inline comments and naming clarity
# ============================================================================

def calculate_discounted_prices(prices: list[int]) -> list[int]:
    """Apply standard retail discount to valid prices.
    
    Args:
        prices: List of original prices in cents
        
    Returns:
        List of discounted prices (50% off for positive values only).
        Invalid prices (zero or negative) are filtered out.
    """

    # A list of valid prices with discounts applied 
    discounted = []
    for price in prices:
        # Skip invalid prices rather than raising error to handle
        # legacy data that may contain placeholder zeros
        if price > 0:
            # Apply 50% discount per Q4 2024 promotion policy
            discounted.append(round(price * 0.5))
    
    return discounted

# Improvements:
# - Function and variable names clearly indicate purpose
# - Docstring explains the business logic and reasoning behind decisions
# - Comments clarify specific implementation choices without stating the obvious
