#837799 has 525 links
upperBound = 1000000

numChildrenList = list()

maxLinks = 0
maxNum = 0

for n in range(1,upperBound+1):
	links = 1
	number = n
	while number != 1:
		# print(number)
		if number %2 == 0:
			number = number/2
		else:
			number = number*3+1
		links = links+1
	numChildrenList.append(links)
	if links > maxLinks:
		maxLinks = links
		maxNum = n

print(str(maxNum) + " has " + str(maxLinks) + " links")