while 1:
	number = numberBkp = input("Type a number to find number of links\n")
	links = 1
	while number != 1:
		print(number)
		if number %2 == 0:
			number = number/2
		else:
			number = number*3+1
		links = links+1
	print(str(numberBkp) + " has " + str(links) + " links")