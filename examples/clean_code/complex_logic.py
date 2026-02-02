# ============================================================================
# Example of complex logic without explanation
# ============================================================================

def validate_user(u):
    # Validation
    if u['age'] >= 18 and u['age'] <= 65 and u['country'] == 'US' and \
       u.get('verified', False) and u['status'] != 'banned':
        return True
    return False

# Problems:
# - No explanation of business rules
# - Complex condition is hard to understand
# - Magic numbers without context
# - Doesn't explain why these specific rules exist
# - Even with comments, the logic is hard to follow


# ============================================================================
# Example of improved clarity with explanations
# ============================================================================

def is_eligible_for_premium(user: dict) -> bool:
    """Check if user meets all eligibility requirements for premium service.
    
    Eligibility requirements (as of Jan 2026):
    - Age 18-65 (insurance policy restriction)
    - US-based (regulatory compliance - service not licensed elsewhere)
    - Verified account (fraud prevention)
    - Not banned (terms of service enforcement)
    
    Args:
        user: Dict with keys 'age', 'country', 'verified', 'status'
        
    Returns:
        True if user meets all requirements, False otherwise
    """

    MIN_AGE = 18  # Legal adult age
    MAX_AGE = 65  # Insurance policy upper limit
    
    is_eligible_age = MIN_AGE <= user['age'] <= MAX_AGE
    is_us_based = user['country'] == 'US'
    is_verified = user.get('verified', False)
    is_not_banned = user['status'] != 'banned'
    
    return is_eligible_age and is_us_based and is_verified and is_not_banned

# Improvements:
# - Function name clearly indicates purpose
# - Docstring explains business rules and reasoning
# - Constants for magic numbers with explanations
# - Breaking down complex condition into readable parts
# - Overall clarity on why each check exists
