#a dictionary of numbers and the number of levels
upperBound = 27

numberFound = 0 #used to keep track of how many numbers still need to be linked
lastFound = 0
numChildrenList = {}

parents = {1: 1}

while numberFound < upperBound and len(parents) > 0:
	#does this for loop only use keys from the first call? Hopefully yes
	# if numChildrenList[lastFound] >= 35:
		# print("parents" + str(parents))
		# print(numChildrenList)
	for key in parents.keys():
		#store the # of links to a given number
		#only store links for keys under the bound and link not already stored
		
		if key not in numChildrenList:
			numChildrenList[key] = parents[key]
			if key <= upperBound:
				numberFound = numberFound + 1
				lastFound = key
				print("number " + str(key)  + " has "  + str(parents[key]) + " links and was found at iterator: " + str(numberFound))

				parents[key*2] = (parents[key] + 1)
				if key > 4 and (key-1)%3 == 0 and ((key-1)/3)%2 == 1:
					parents[(key-1)/3] = (abs(parents[key]) + 1)

			#I found that if it's divisible by 3, it will just keep doubling
			#it will never come back into range
			elif key%3 != 0:
				parents[key*2] = (parents[key] + 1)
				if key > 4 and (key-1)%3 == 0 and ((key-1)/3)%2 == 1:
					parents[(key-1)/3] = (parents[key] + 1)
		del parents[key]



# print(numChildrenList)
print(lastFound)