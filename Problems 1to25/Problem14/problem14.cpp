#include <iostream>
using namespace std;
#define limit 50000

int countSequence(int number, int* train)
//1st parameter takes in number for sequence
//2nd parameter taken in the array of jumps
//returns number of steps to the end
{
  //bool found = false;
  int numJump = 0;
  //if(train[number] != 0) found = true;
  // else 
  // {
      if(number%2 == 0)
	{
	  numJump = number/2;
	}
      else
	{
	  numJump = 3*number+1;
	}
      //train[number] = numJump;
  //  }
  //  if(found)      return 0;
   if(number == 1)   return 1;
   else      return countSequence(numJump, train)+1;
   }

int main()
{
  int mostSteps = 0;
  int numMostSteps = 0;
   int train[300000];
/*int train[3*limit-1];
  cout << "entering first array access: " << limit << endl;
   for(int i = 0; i < 3*limit-1; i++)
    {
      train[i] = 0;
    } 
*/
  int tempSteps = 0;
  for(int i = 1; i < limit; i++)
    {
      tempSteps = countSequence(i, train);
      if(tempSteps > mostSteps)
	{
	  mostSteps = tempSteps;
	  numMostSteps = i;
	}
         }
  cout << "The number " << numMostSteps << " produces a sequence of length" 
       << mostSteps << endl;
    
return 0;
}
