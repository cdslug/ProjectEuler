/*
 *  Levels_1-25.h
 *  Level 1
 *
 *  Created by Ryan Mercer on 6/13/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */
# include <iostream>
# include <string>
# include <stdio.h>
# include <stdlib.h>
using namespace std;

int min(int x, int y);

long problem_1(const int & numMax);

long problem_1_extra_odd(const int& num,const int& numMax, int & multiples, int & top);

long problem_2(const int & numMax);

long problem_3(const long & numMax);

int problem_4();

long long problem_5(const int &numMax);

bool problem_5_helper(int primes[3][8], const int& index, int &iChg);

long problem_6(const int& numMax);
/*The sum of the squares of the first ten natural numbers is,
1^2 + 2^2 + ... + 10^2 = 385
The square of the sum of the first ten natural numbers is,
(1 + 2 + ... + 10)^2 = 55^2 = 3025
Hence the difference between the sum of the squares of the 
 first ten natural numbers and the square of the sum is 
 3025 - 385 = 2640.
Find the difference between the sum of the squares of the 
 first one hundred natural numbers and the square of the sum.
*/

long problem_8(const string& numString);

long problem_9(const int& numMax);

long problem_11(char * numCString);

int problem_12(const int& numDivisors); //NEED TO FINISH

long long problem_13(const string numString);