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
  const int wantedPrimes = 100001;
  int  numPrimes = 2;
  int number = 3;
  int primes[wantedPrimes];
  primes[0] = 2;
  primes[1] = 3;
  while (numPrimes < wantedPrimes)
    {
      number+=2;
      if(isPrime(number, numPrimes, primes))
	{
	  primes[numPrimes] = number;
	  numPrimes++;
	}
    }
  cout << "Prime #" << wantedPrimes << " is " << number << endl;
  return 0;
}
