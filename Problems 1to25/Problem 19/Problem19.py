NUMBER_OF_DAYS_IN_MONTH = [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]

def check_leap_year(year):
	if year%4 == 0:
		if year%100 == 0:
			if year%400 == 0:
				return True
			else:
				return False
		else:
			return True
	else:
		return False

def check_leap_year_test():
	leap_year_positive = [2000, 1980, 1640, 1200, 1776]
	leap_year_negative = [1900, 1800, 1700, 1999, 1775, 1777]

	for year in leap_year_positive:
		if check_leap_year(year) == False:
			print("check_leap_year positive failed " + str(year))
			return False

	for year in leap_year_negative:
		if check_leap_year(year) == True:
			print("check_leap_year negative failed " + str(year))
			return False
	print("Passed check_leap_year_test")
	return True

def check_date_greater_than(month1, year1, month2, year2):
	
	if year1 > year2:
		return True
	else:
		if month1 > month2:
			return True
		else:
			return False

def check_date_greater_than_test():
	dates = [(1,1901, 1,1901,False), (1,2001,12,2000, True), (1, 1901, 12, 2000, False)]
	for date in dates:
		assert(check_date_greater_than(date[0], date[1], date[2], date[3]) == date[4])

	print("Passed check_date_greater_than_test")

def all_tests():
	check_leap_year_test()
	check_date_greater_than_test()
	print("Passed =>all_tests<=")
########################
#####     MAIN     #####
########################
def main():
	#all_tests()

	MONTH_START = 1
	YEAR_START = 1901

	MONTH_END = 12
	YEAR_END = 2000

	day_total_aging = 1
	month_current = MONTH_START
	year_current = YEAR_START

	number_sundays = 0
	number_sundays_this_year = 0
	#assume this function will always be using 1st day of month
	while check_date_greater_than(month_current, year_current, MONTH_END, YEAR_END) == False:
		if day_total_aging%7 == 6:
			number_sundays += 1
			number_sundays_this_year += 1
		#print("Month " + str(month_current) + "(" + str(NUMBER_OF_DAYS_IN_MONTH[month_current-1]) + "): " + str(number_sundays_this_year))
		day_total_aging += NUMBER_OF_DAYS_IN_MONTH[month_current-1]
		if month_current == 2 and check_leap_year(year_current):
			day_total_aging +=1
		month_current += 1
		if month_current == 13:
			#print(str(year_current) + ": " + str(number_sundays_this_year))
			number_sundays_this_year = 0
			year_current += 1
			month_current = month_current%13 + 1 # to keep it 1 indexed

	print("Sundays on 1st of month between 1 Jan 1901 and 31 Dec 2000:\n" + str(number_sundays))

main()