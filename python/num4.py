ans = 0 # Start at the smallest possible palindrome product of 2 3-digit numbers

for i in range(999, 99, -1):
	for j in range(999, i-1, -1):
		num = i * j

		if (num > ans):
			s = str(num) # Generating this is expensive, so only do it if we have a valid candidate
			if (s == s[::-1]):
				ans = num

print ans