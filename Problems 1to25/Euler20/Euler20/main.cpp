//
//  main.cpp
//  Euler20
//
//  Created by Ryan Mercer on 12/8/12.
//  Copyright (c) 2012 Ryan Mercer. All rights reserved.
//

#include <iostream>
#define FACTORIAL 100



void multiply_20(int digits[], int mult)
{
    int product[200];
    int offset = 0;
    int singleMult = 1;
    int carry = 0;
    int singleProd = 1;
    for(int iter = 0; iter < 200; iter++)
    {
        product[iter] = 0;
    }
    while (mult > 0){
        singleMult = mult%10;
        carry = 0;
        for (int iter = 0; iter < 200-3; iter++) {
            singleProd = digits[iter]*singleMult + product[iter+offset] + carry;
            product[iter+offset] = singleProd%10;
            carry = singleProd/10;
        }
        mult = mult/10;
        offset++;
    }
    for (int iter = 0; iter < 200; iter++) {
        digits[iter] = product[iter];
    }
}

int problem_20(int factNum)
/*
 For example, 10! = 10 x 9 x ... x 3 x 2 x 1 = 3628800,
 and the sum of the digits in the number 10! is 3 + 6 + 2 + 8 + 8 + 0 + 0 = 27.
 
 Find the sum of the digits in the number 100!
 */
{
    int digits[200];
    int sum = 0;
    for(int iter = 0; iter < 200; iter++)
    {
        digits[iter] = 0;
    }
    digits[0] = 1;
    for (int iter = 1; iter <= factNum; iter++) {
        multiply_20(digits,iter);
    }
    
    for (int iter = 0; iter < 200; iter++) {
        sum += digits[iter];
    }
    return sum;
}

int main(int argc, const char * argv[])
{

    // insert code here...
    std::cout << "sum of digits in 100!: " << problem_20(FACTORIAL) << std::endl;
    return 0;
}

