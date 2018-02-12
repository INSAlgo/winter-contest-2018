def diversity(M, C, i, j):
	"""Gives the size of the path beginning from coordinates (i, j) in map M
	of size C*C.
	"""
	directions = {"<": (0, -1), ">": (0, 1), "^": (-1, 0), "v": (1, 0)}
	visited = [[False]*C for _ in range(C)]
	length = 0
	while i >= 0 and j >= 0 and i < C and j < C and not visited[i][j]:
		length += 1
		visited[i][j] = True
		i, j = i + directions[M[i][j]][0], j + directions[M[i][j]][1]
	return length

C = int(input())
M = [input() for _ in range(C)]
print(max(diversity(M, C, i, j) for i in range(C) for j in range(C)))