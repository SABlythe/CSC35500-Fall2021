#include <cstdio>
#include <cstring>
#include <iostream>
#include <unistd.h>

using namespace std;

// implement:     ls -l | wc

int main (int argc, char *argv[])
{
  int pipeInfo[2];
  int myPipe = pipe(pipeInfo);

  int pid=fork();
  
  if (pid!=0) // parent, which will do "wc"
  {
     char *args[2];
     args[0] = new char[80]; strcpy(args[0], "wc");
     args[1] = NULL;
     
     close(pipeInfo[1]); // close parent's ability to write into pipe
     dup2(pipeInfo[0] , fileno(stdin) );
     
     execvp(args[0], args);
  }
  else // child ("ls -l")
  {
     char *args[3];
     args[0] = new char[80]; strcpy(args[0], "ls");
     args[1] = new char[80]; strcpy(args[1], "-l");
     args[2] = NULL;
  
     close(pipeInfo[0]); // close child's ability to read from pipe   
     dup2(pipeInfo[1] , fileno(stdout) );
     
     execvp(args[0], args);
  }
  
  cout << "If this prints, something didn't work!" << endl;
  return 0;
}










