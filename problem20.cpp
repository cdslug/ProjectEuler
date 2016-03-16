#include <iostream>
#define FACTORIAL 20

using namespace std;

int main()
{
  int sum = 0;
  unsigned long number = 1;
  for(int i = 1; i <= FACTORIAL; i++)
    {
      number*=i;
    }
  cout << "the factorial of "<< FACTORIAL<< "! is: " << number << endl;
  while(number > 0){
    sum += number%10;
    number/=10;
 }
  cout << "and the sum of the digits is: " << sum << endl;
}
