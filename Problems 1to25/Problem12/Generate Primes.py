f = open("primes.txt", 'w')

f.write(str(2) + '\n')
primeList = [2]

for num in range(2,100000000):
	notPrime = 0
	for prime in primeList:
		if num%prime == 0:
			notPrime = 1
			break
	if notPrime == 0:
		f.write(str(num) + '\n')
		primeList.append(num)

f.close()