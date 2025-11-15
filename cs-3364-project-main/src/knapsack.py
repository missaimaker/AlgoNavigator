import numpy as np

if __name__ == "__main__":
    # Initialize Data
    w = 20
    n = 5
    weights = [8, 7, 6, 5, 4]
    values = [1500, 1600, 1700, 1800, 3000]

    dp = np.zeros(shape=(n + 1, w + 1))

    # Calculations for the dp table
    for i in range(1, n + 1):
        for j in range(1, w + 1):
            if weights[i - 1] > j:
                dp[i][j] = dp[i-1][j]
            else:
                dp[i][j] = max(dp[i-1][j], values[i - 1] + dp[i-1][j - weights[i-1]])
    
    # Print out the dp table
    for i in range(len(dp)):
        for j in range(len(dp[0])):
            print(dp[i][j], end='\t')
        print()
