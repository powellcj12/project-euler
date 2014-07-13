primes = [2, 3]
candidate = primes[-1]

while (len(primes) < 10001):
	candidate += 2
	limit = candidate**0.5
	isPrime = True

	for i in primes:
		if i > limit:
			break

		if candidate % i == 0:
			isPrime = False
			break

	if isPrime:
		primes.append(candidate)

print primes[-1]