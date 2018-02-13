# For the knapsack we want to work with integers, so we will multiply floats
# by 100 (cf precision in the problem statement), and divide output by 100.

B = int(100 * float(input()))
N = int(input())
prices = set()
for i in range(N):
	prices.add(int(100 * float(input().split()[1])))

possible = [True] + [False] * B

maxp = 0
for i in range(1, B+1):
	for price in prices:
		if price <= i and possible[i-price]:
			possible[i] = True
			break
	if possible[i]:
		maxp = i

print("%0.2f" % (maxp/100))