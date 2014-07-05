# Prime factors of 1 through 20:
# 	1: 1
#	2: 2
#	3: 3
#	4: 2, 2
#	5: 5
#	6: 2, 3
#	7: 7
#	8: 2, 2, 2
#	9: 3, 3

#	10: 2, 5
#	11: 11
#	12: 2, 2, 3
#	13: 13
#	14: 2, 7
#	15: 3, 5
#	16: 2, 2, 2, 2
#	17: 17
#	18: 2, 3, 3
#	19: 19
#	20: 2, 2, 5

# So answer needs to have the following prime factors:
#	4 2s, 2 3s, a 5, a 7, an 11, a 13, a 17, and a 19

ans = (2 * 2 * 2 * 2) * (3 * 3) * 5 * 7 * 11 * 13 * 17 * 19
print ans

# That's not really too interesting :(
# So let's generalize the problem to number from 1 to N

def gcd(a, b):
	while (b):
		a, b = b, a % b
	return a

def lcm(a, b):
	return (a * b) / gcd(a, b)

# Apply the lcm method over all numbers from 1 to N
N = 20
print reduce(lcm, range(1,N))