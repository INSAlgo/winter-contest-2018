def tidy_up(recipe):
	"""Take a word and give a symmetric version with the same letters, or "-".
	"""
	alphabet = "abcdefghijklmnopqrstuvwxyz"
	occurences = {letter: 0 for letter in alphabet}
	for letter in recipe:
		occurences[letter] += 1

	odd = ""
	left = ""
	for letter in alphabet:
		if occurences[letter] % 2:
			if odd:
				return "-" # there can be at most one letter in odd number
			else:
				odd = letter
		left += letter * (occurences[letter] // 2)

	return left + odd + left[::-1]


N = int(input())
recipes = [input() for _ in range(N)]

for recipe in recipes:
	print(tidy_up(recipe))