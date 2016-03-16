/*
 *  Levels_1-25.cpp
 *  Level 1
 *
 *  Created by Ryan Mercer on 6/13/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include "Level_1.h"
#include <cmath>
long problem_1_extra_odd(const int& num, const int &numMax, int & multiples, int & top)
//decreases number of multiples
//adjusts the greatest multiple for later calculation
//returns the largest number that is a multiple
{
	multiples = numMax/num;
	if (multiples % 2 != 0){
	multiples--;
	top = num*multiples;
		return top + num;
	}
	top = num*multiples;
	return 0;
}

long problem_1(const int & numMax)
{
	int top5 = 0, 
		top3 = 0, 
		top15 = 0,
		multiples5 = 0,
		multiples3 = 0,
		multiples15 = 0,
		extra5 = 0,
		extra3 = 0,
		extra15 = 0;
	long sum = 0;
	/*
	while ((topTemp % top5) != 0) {
		topTemp--;
	}
	*/
	extra5 = problem_1_extra_odd(5,numMax-1, multiples5, top5);
	extra3 = problem_1_extra_odd(3,numMax-1, multiples3, top3);
	extra15 = problem_1_extra_odd(15, numMax-1, multiples15, top15);
	
	sum += ((5+top5) * (multiples5/2)) + extra5;
	sum += ((3+top3) * (multiples3/2)) + extra3;
	sum -= ((15+top15) * (multiples15/2))-extra15;
	
	return sum;
}

long problem_2(const int &numMax)
{
	long sum = 0;
	int currentTerm = 2, 
		oldTerm = 1,
		tempTerm = 0;
	for(; currentTerm < numMax; 
		tempTerm = currentTerm, currentTerm +=oldTerm, oldTerm = tempTerm)
	{
		if (currentTerm%2 == 0) {
			sum += currentTerm;
		}
	}
	return sum;
}

long problem_3(const long &numMax)
{
	long	largestPrime;
	for (long i = 3; i < numMax; i+=2) {
		bool isPrime = true;
		for (long j = 3; j < (int)sqrt(i)+1; j+=2) {
			if (i % j == 0){
				isPrime = false;
				break;
			}
		}
		if (isPrime) {
			if (numMax % i == 0){
				largestPrime = i;
				cout << largestPrime << endl;
			}
		}
	}
	return largestPrime;
}

int problem_4()
/*
 A palindromic number reads the same both ways. 
 The largest palindrome made from the product 
 of two 2-digit numbers is 9009 = 91  99.
 Find the largest palindrome made from the 
 product of two 3-digit numbers
 */
{
	int largePal = 0,
		num = 0,
	tempnum = 0,
	flipped = 0,
	firstLimit = 100,
	topIndex = 0,
	digits[6],
	topPals[100];
	for (int i = 999; i > 99; i--) {
		num = i * 999;
		for (int j = 999; j > 99; j--) {
			if (j < firstLimit) {
				break;
			}
			num -= i;
			flipped = 0;
			if (num%100000) {
				tempnum = num;
				for (int k = 0; k < 6; k++) {
					digits[k] = tempnum%10;
					tempnum /=10;
				}
				for (int k = 0; k < 6; k++) {
					flipped*=10;
					flipped+=digits[k];
				}
				if (flipped == num) {
					topPals[++topIndex] = num;
					//topIndex++;
					firstLimit = j;
				}
			}
			else if (num%10000) {
				tempnum = num;
				for (int k = 0; k < 5; k++) {
					digits[k] = tempnum%10;
					tempnum /=10;
				}
				for (int k = 0; k < 5; k++) {
					flipped*=10;
					flipped+=digits[k];
				}
				if (flipped == num) {
					topPals[++topIndex] = num;
					//topIndex++;
					firstLimit = j;
				}
			}
		}
	}
	int max = 0;
	for (;topIndex > 0; topIndex--) {
		if (topPals[topIndex] > max) {
			max = topPals[topIndex];
		}
	}
	return max;
}

long long problem_5(const int& numMax)
/*
 2520 is the smallest number that can be 
 divided by each of the numers from 1 to 10
 without any remainder.
 What is the smallest positive number that is 
 evenly divisible by all of the numbers from 1 to 20?
 */
{
	long long smallestNum = 1;
	int iChg,
	primeArr[3][8] = 
	{{2,3,5,7,11,13,17,19},
	{0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0}};
	//0:primes	1:maxNumUsed	2:currNumUsed
	//0:2, 
	//1:3,
	//2:5,
	//3:7,
	//4:11,
	//5:13,
	//6:17,
	//7:19,
	//8:23,
	//9:29

	for (int i = 20; i > 0 ; i--) {
		iChg = i;
		for (int j = 0; j < 8; j++)
		{
			primeArr[2][j] = 0;
			while(problem_5_helper(primeArr,j,iChg)){
				if (primeArr[2][j]> primeArr[1][j]) {
					primeArr[1][j] = primeArr[2][j];
					smallestNum *= primeArr[0][j];
				}
			}
		}
	}
	return smallestNum;
}
	
bool problem_5_helper(int primes[3][8], const int& index, int& iChg)
{
	if (iChg % primes[0][index] == 0){
		iChg /= primes[0][index];
		primes[2][index]++;
		return true;
	}
	return false;
}
	
long problem_6(const int& numMax)
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
{
	int numToNext = 1, sumSq = 0, sqSum = 0, nextSq = 1;
	for (int i = 0;  i < numMax; i++) {
		sumSq+=nextSq;
		numToNext+=2;
		nextSq+=numToNext;
		sqSum+=i+1;
	}
	sqSum*=sqSum;
	return sqSum - sumSq;
}

long problem_8(const string& numString)
/*
 Find the greatest product of five consecutive 
 digits in the 1000-digit number.
 */
{
	int digits[5];
	long greatProd = 1, tempProd = 1;
	for (int i = 0; i < 5; i++){
		digits[i] = numString[i]-'0';
		greatProd*=digits[i];
	}
	for (int i = 5; i < numString.length(); i++){
		digits[i%5] = numString[i]-'0';
		tempProd = 1;
		for (int j = 0; j < 5; j++){
			digits[j] = numString[i-j]-'0';
			tempProd*=digits[j];
		}
		if (tempProd > greatProd) {
			greatProd = tempProd;
		}
	}
	return greatProd;
}

int min(int x, int y){
	return x < y ? x : y;
}

long problem_9(const int& numMax)
/*
A Pythagorean triplet is a set of three 
 natural numbers, a  b  c, for which,

a^2 + b^2 = c^2
For example, 3^2 + 4^2 = 9 + 16 = 25 = 5^2.

There exists exactly one Pythagorean triplet for which a + b + c = 1000.
Find the product abc.
 */
{
	int block = 10, aSq = 0, bSq = 0, cSq = 0, sum = 0;
	for (int aa = 1; aa < numMax; aa+=block) {
		for (int bb = aa+1; bb < numMax; bb+=block) {
			for (int a = aa; a < min(aa+block,numMax); a++){
				aSq = a*a;
				for (int b = a+1; b < min(bb+block,numMax); b++) {
					sum = aSq + b*b;
					cSq = 0;
					for (int c = b; cSq <= sum; c++) {
						cSq = c*c;
						if ((cSq == sum) && (a+b+c == numMax)){
							return a*b*c;
						}
					}
				}
			}
		}
	}
}

long problem_11(char * numCString)
/*
 What is the greatest product of four adjacent 
 numbers in any direction (up, down, left, right,
 or diagonally) in the 20x20 grid?
 */
{
	int yind = 0, grid[400];
	long maxProd = 0, 
	tempProdRight = 0, 
	tempProdDown = 0, 
	tempProdDiagL = 0,
	tempProdDiagR = 0;
for (int i = 0, gi = 0; i < 1198 && gi < 400; i+=3, gi++) {
	grid[gi] = atoi(&numCString[i]);
}
	for (int y = 0; y < 20; y++) {
		yind = y*20;
		for (int x = 0; x < 20; x++) {
			if (x < 20-3) {
				tempProdRight = grid[yind+x]*grid[yind+x+1]*grid[yind+x+2]*grid[yind+x+3];
			}
			if (y < 20-3) {
				tempProdDown = grid[yind+x]*grid[yind+20+x]*grid[yind+40+x]*grid[yind+60+x];
				if (x < 20-3) {
					tempProdDiagR = grid[yind+x]*grid[yind+21+x]*grid[yind+42+x]*grid[yind+63+x];

				}
				if (x > 2) {
					tempProdDiagL = grid[yind+x]*grid[yind+19+x]*grid[yind+38+x]*grid[yind+57+x];
					
				}
			}
			if (tempProdRight > maxProd) {
				maxProd = tempProdRight;
				
			}
			if (tempProdDown > maxProd) {
				maxProd = tempProdDown;
			}
			if (tempProdDiagL > maxProd) {
				maxProd = tempProdDiagL;
			}
			if (tempProdDiagR > maxProd) {
				maxProd = tempProdDiagR;
			}
		}
	}
	return maxProd;
}

int problem_12(const int& numDivisors)
/*
 The sequence of triangle numbers is generated 
 by adding the natural numbers. So the 7th triangle 
 number would be 1 + 2 + 3 + 4 + 5 + 6 + 7 = 28.
 Let us list the factors of the first seven triangle numbers:
 1: 1
 3: 1,3
 6: 1,2,3,6
 10: 1,2,5,10
 15: 1,3,5,15
 21: 1,3,7,21
 28: 1,2,4,7,14,28
 We can see that 28 is the first triangle number 
 to have over five divisors.

 What is the value of the first triangle number 
 to have over five hundred divisors?
 */
{
	int num = 0;
	for (int tri = 1, div = 1; true; tri++, div = 1) {
		for (int divers = 1; divers <= sqrt(num); divers++) {
			if (num%divers == 0) {
				div++;
			}
			if (div > 500) {
				return num;
			}
		}
		num+=tri;
	}
		//NEED TO FINISH
}

long long problem_13(const string numString)

{
	string tempString;
	long long sum;//, grid[100]; 
	for (int stri = 0, gi = 0; stri < 5100 && gi < 100; stri+=51, gi++) {
		sum+= atol(numString.substr(stri,12).c_str());
	}
	if(sum%10000000000)
		return sum/10000;
	else {
		return sum/1000;
	}

}

