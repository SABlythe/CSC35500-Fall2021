#include <iostream>
#include <unistd.h>
#include <sys/wait.h>

using namespace std;

int main(int argc, char *argv[])
{
  int newPID = fork();
  
  if (newPID != 0)
  {
     waitpid(newPID, NULL, 0);
     cout << "tantrum over !!" << endl;
  }
  else
  {
	for (int i=0; i<20; i++)
	{
	  cout << i << ") childish behavior" << endl;
	  sleep(1);
	}
  }
  return 0;
}
