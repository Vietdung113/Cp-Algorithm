
import numpy as np

# Set a random seed for reproducibility
np.random.seed(0)

# Define the desired correlation coefficient
desired_corr = 0.5

# Generate random values for x and y
n = 1000  # Number of data points
mean = [0, 0]  # Mean values for x and y
cov_matrix = [[1, desired_corr], [desired_corr, 1]]  # Covariance matrix

x, y = np.random.multivariate_normal(mean, cov_matrix, n).T
print(x,y)
# Check the actual correlation between x and y
actual_corr = np.corrcoef(x, y)[0, 1]

print("Actual Correlation:", actual_corr)
