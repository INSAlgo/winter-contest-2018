from collections import defaultdict
import string

def tidy_up(recipe):
	"""Take a word and give a symmetric version with the same letters, or "-".
	"""
	occurences = defaultdict(int)
	for letter in recipe:
		occurences[letter] += 1

	odd = ""
	left = ""
	for letter in string.ascii_lowercase:
		if occurences[letter] % 2:
			if odd:
				return "-" # there can be at most one letter in odd number
			else:
				odd = letter
		left += letter * (occurences[letter] // 2)

	return left + odd + left[::-1]


N = int(input())
for recipe in range(N):
	print(tidy_up(input()))
