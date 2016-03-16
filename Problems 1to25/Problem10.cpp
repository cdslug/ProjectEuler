#include <iostream>
using namespace std;

bool isPrime(int number, int numPrimes, int* primes)
{
  for(int i = 0; i != numPrimes; i++){
    if(number%(primes[i]) == 0) {
      return false;
    }
  }
  return true;
}

int main()
{
  const int limit = 2000000;
  int  numPrimes = 1;
  int primes[limit>>1];
  long sumPrimes = 0;
  primes[0] = 2;
  for(int number = 3; number < limit; number+=2 )
    {
      if(isPrime(number, numPrimes, primes))
	{
	  primes[numPrimes] = number;
	  numPrimes++;
	}
    }
  for(int j = 0; j < numPrimes; j++)
    {
      sumPrimes += primes[j];
    }
  cout << "Sum of primes <" << limit << " is " << sumPrimes << endl;
  return 0;
}
