#include <iostream>
using namespace std;
#define grid 20

	     
int main()
{
  long map[grid+1][grid+1];
  for(int r = 0; r < grid+1; r++)
    {
      for(int c = 0; c < grid+1; c++)
	{
	  if(r == 0 || c == 0)
	    {
	      map[r][c] = 1;
	    }
	  else 
	    {
	      map[r][c] = map[r-1][c]+map[r][c-1];  
	    }
	}
    }
  cout << "for a square grid where n = " << grid
       << "\nthe number of steps is " << map[grid][grid] << endl;
    return 0;
}
