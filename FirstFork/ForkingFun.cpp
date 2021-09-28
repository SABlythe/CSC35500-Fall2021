#include <iostream>
#include <unistd.h>

using namespace std;

int main(int argc, char *argv[])
{


  
  int newPID = fork();
  
  int pid = getpid();
  cout << "My PID is : " << pid << " ... ";
  cout << "Fork gave me " << newPID << endl;
  
  if (newPID != 0)
  {
     while(true)
     {
     	cout << "P";
     } 
  }
  else
  {
     while(true)
     {
     	cout << "C";
     } 
  }
  return 0;
}
