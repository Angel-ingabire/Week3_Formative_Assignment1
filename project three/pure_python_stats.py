def compute_statistics(values):
    total = 0.0
    sumsq = 0.0
    for value in values:
        total += value
        sumsq += value * value
    mean = total / len(values)
    variance = (sumsq / len(values)) - (mean * mean)
    return total, mean, variance
