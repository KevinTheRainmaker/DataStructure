def knapsack01(i, W, w, p):
		if (i <= 0 or W <= 0):
				return 0
		if (w[i] > W):
				return knapsack01(i - 1, W, w, p)
		else:    # w[i] <= W
				left = knapsack(i-1, W, w, p)
				right = knapsack(i-1, W-w[i], w, p)
			 return max(left, p[i] + right)