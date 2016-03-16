//
//  main.cpp
//  Euler71
//
//  Created by Ryan Mercer on 12/8/12.
//  Copyright (c) 2012 Ryan Mercer. All rights reserved.
//

#include <iostream>
using namespace std;


int closestLessThan_71(int den, int upper, int lower, double givenFrac)
//does a binary search to find closest num for num/den < n/d
{
//    cout << "den, upper, lower " << den <<" " << upper << " " <<lower << endl;
    int testNum = (upper+lower)/(2);
    double testFrac = (double)testNum/(double)den;
    if (abs(upper-lower) == 1) {
        if(testFrac < givenFrac) testNum = testNum;
        else testNum = testNum-1;
    }
    else if (testFrac >= givenFrac) {
        testNum = closestLessThan_71(den, testNum, lower,givenFrac);
    }
    else if(testFrac < givenFrac){
        testNum = closestLessThan_71(den, upper, testNum, givenFrac);
    }
    return testNum;
}

int problem_71(int maxd,int n,int d)
/*Consider the fraction, n/d, where n and d are positive integers and n < d. 
 By listing the set of reduced proper fractions for d<=1,000,000 in ascending order of size,
 find the numerator of the fraction immediately to the left of 3/7.
 */
{
    int possibleNum = 0;
    double tempDbl = 0;
    double lastClosest = 0;
    double closestNum = 0;
    double givenFrac = double(n)/double(d);
    for(double iter = maxd; iter > 1; iter -= 1)
    {
        possibleNum = closestLessThan_71(iter, maxd-1, 1,givenFrac);
        tempDbl = (double)possibleNum/(double)iter;
        if (tempDbl < givenFrac && tempDbl > lastClosest) {
//            cout << "possibleNum, iter: " << possibleNum <<" " << iter << endl;
            closestNum = possibleNum;
            lastClosest = tempDbl;
        }
    }
    return closestNum;
}


int main(int argc, const char * argv[])
{
//    cout << "Answer?: " << problem_71(8, 3, 7) << endl;
    cout << "Answer?: " << problem_71(1000000, 3, 7) << endl;
    return 0;
}

