sum = 2 # 2 is the first even Fibonacci number

prevFib = 2
currentFib = 3

while (currentFib < 4000000):
	if currentFib % 2 == 0:
		sum += currentFib

	currentFib += prevFib

	# We need to store what the currentFib *used* to be in order to calculate
	# what the next Fibonacci number will be on the subsequent iteration
	prevFib = currentFib - prevFib

print sum