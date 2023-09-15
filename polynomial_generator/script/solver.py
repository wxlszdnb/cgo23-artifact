import numpy as np
from scipy.optimize import minimize


def poly(powers, x, coeffs, termSize):
    res=[]
    for j in range(len(x)):
        res.append(sum([coeffs[i] * x[j] ** powers[i] for i in range(termSize)]))
    return res   # naive impl. of poly evaluation


# Define the cost function
def cost(coeffs, powers, x, lb, ub, termSize):
    y = poly(powers, x, coeffs, termSize)
    ret=0.0
    for i in range(len(y)):
        ret+=((y[i] - lb[i]) ** 2 + (y[i] - ub[i]) ** 2)
    return ret


# solve the coefficients of poly with termSize terms
def solve_polynomial(x, powers, termSize, lb, ub):
    # Initial guess for coefficients
    coeffs0 = np.ones(termSize)

    # Bounds for the coefficients
    bounds = [(None, None)] * len(coeffs0)

    # Minimize the cost function
    result = minimize(cost, coeffs0, args=(powers, x, lb, ub, termSize), bounds=bounds)

    return result.x
