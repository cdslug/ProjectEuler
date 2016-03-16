f = open('primes.txt', 'r')
primeFile = list()
for line in f:
	primeFile.append(int(line))

f.close()

tri = 0


for t in range(1,10000005):
	tri = tri + t
	primeList = list()
	tempTri = tri
	for p in primeFile:
		if p > tempTri:
			break
		while tempTri%p == 0:
			primeList.append(p)
			tempTri = tempTri/p
	primeCounter = dict((i,primeList.count(i)) for i in primeList)
	factors = 1;
	# print(primeCounter)
	for p in primeCounter:
		factors = factors*(primeCounter[p] + 1)
	if factors >= 500:
		print(str(tri) + " has " + str(factors) + " factors")
		print("WINNER^")
		print('\a')
		break

