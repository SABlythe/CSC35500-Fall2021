#include <iostream>

#include <signal.h>

using namespace std;

void myHandler(int sigNum)
{
  cout << "signal Handled!" << endl;
}

int main(int arg, char *argv[])
{
  signal(SIGCHLD , myHandler );   //note no () aftyer myHandler !!!
  //signal(SIGSEGV , myHandler );
  
  int *ptr=NULL;
  
  *ptr =5;
  
  cout << "About to enter inf loop!" << endl;
  while(1);
    
  cout << "Hello!" << endl;

  return 0;
}
