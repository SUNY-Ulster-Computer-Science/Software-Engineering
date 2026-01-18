# ============================================================================
# Example of poorly self-documenting code
# ============================================================================


def calc(x, y, z):
    # Calculate result
    if z == 1:
        return x + y
    elif z == 2:
        return x - y
    elif z == 3:
        return x * y
    else:
        raise ValueError("Invalid operation")

# Problems:
# - Meaningless variable names
# - Magic numbers (what do 1, 2 mean?)
# - Function name doesn't indicate what it calculates


# ============================================================================
# Example of improved self-documenting code
# ============================================================================

from enum import Enum

class CalculationType(Enum):
    """Enumeration for types of calculations."""

    ADD = 1
    SUBTRACT = 2
    MULTIPLY = 3

def perform_calculation(operand_a: float, operand_b: float, operation_type: CalculationType) -> float:
    """Perform basic arithmetic operation on two numbers.
    
    Args:
        operand_a: First number
        operand_b: Second number
        operation_type: CalculationType constant (ADD, SUBTRACT, or MULTIPLY)
        
    Returns:
        Result of the arithmetic operation
    """

    if operation_type == CalculationType.ADD:
        return operand_a + operand_b
    elif operation_type == CalculationType.SUBTRACT:
        return operand_a - operand_b
    elif operation_type == CalculationType.MULTIPLY:
        return operand_a * operand_b
    else:
        raise ValueError("Invalid calculation type provided.")

# Improvements:
# - Clear and descriptive names for function, variables, and enum
# - Use of Enum to avoid magic numbers and clarify operation types
# - Docstring explains function purpose and parameters

# Note that we do not need inline comments to understand the code here; the names and structure are clear enough.
# The docstring provides additional context where necessary.
