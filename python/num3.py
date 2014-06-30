from math import sqrt

def isPrime( num ):
	"Determines if num is a prime number"

	if num < 4:
		return True

	limit = int(sqrt(num))

	for i in range (2, limit):
		if num % i == 0:
			return False

	return True

num = 600851475143

# There can't be any prime numbers larger than sqrt(num)
limit = int(sqrt(num))

# Start at the smallest possible prime factor. Since we'll be calculating 
# primality of the possible factors, we'll start at the bottom where we know 
# the prime numbers aren't very big meaning its cheap to determine their primality
factor = 1

# If we end up with an answer of 1, our number itself is prime
ans = factor

# Don't check beyond the limit of possible primes
while (factor < limit and \
	# As we divide num by the prime factors we find, we'll eventually end up at 
	# the point where num is 1, meaning we've found the largest prime number. At 
	# this point we can stop looking, even if he haven't hit the original limit
	num > 1):

	# Check if we found a factor *before* determining its primality so that we 
	# can avoid determining primality of unnecessary numbers (meaning ones that 
	# aren't factors) - checking for primality is more expensive that checking 
	# if something is a factor
	if (num % factor == 0 and isPrime(factor)):
		if (factor > ans):
			ans = factor

		# If we found a prime factor, factor num by that amount in 
		# order to avoid calculating primality of extremely large values because
		# that's really expensive
		num /= factor

	factor += 1

if (ans == 1):
	print "%i is prime!" % num
else:
	print ans