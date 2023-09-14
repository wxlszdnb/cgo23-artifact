import numpy as np
from scipy.optimize import minimize


def poly(powers, x, coeffs, termSize):
    return sum([coeffs[i]*x**powers[i] for i in range(termSize)])   # naive impl. of poly evaluation


# Define the cost function
def cost(coeffs, powers, x, lb, ub, termSize):
    y = poly(powers, x, coeffs, termSize)
    return ((y - lb)**2).sum() + ((y - ub)**2).sum()


# solve the coefficients of poly with termSize terms
def solve_polynomial(x, powers, termSize, lb, ub):
    # Initial guess for coefficients
    coeffs0 = np.ones(termSize)

    # Bounds for the coefficients
    bounds = [(None, None)] * len(coeffs0)

    # Minimize the cost function
    result = minimize(cost, coeffs0, args=(powers, x, lb, ub, termSize), bounds=bounds)

    return result.x
