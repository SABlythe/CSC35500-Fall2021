#include <cstdio>
#include <cstring>
#include <unistd.h>

int main(int argc, char *argv[])
{
  int pipefd[2];
  pipe(pipefd);

  int pid=fork();
  if (pid==0) // child which will do wget
    {
      char *cmd[3];
      cmd[0] = new char[100]; strcpy(cmd[0], "curl"); // "curl" is "wget" on exam
      cmd[1] = new char[100]; strcpy(cmd[1], "https://www.espn.com");
      cmd[2] = NULL;

      close(pipefd[0]);
      dup2(pipefd[1], fileno(stdout));
      
      execvp(cmd[0], cmd);
    }
  else // parent will do grep 
    {
      char *cmd[3];
      cmd[0] = new char[100]; strcpy(cmd[0], "grep");
      cmd[1] = new char[100]; strcpy(cmd[1], "Cardinals");
      cmd[2] = NULL;

      close(pipefd[1]);
      dup2(pipefd[0], fileno(stdin));

      FILE *fp = fopen("stlnews.txt", "w");
      dup2(fileno(fp) , fileno(stdout));
      
      execvp(cmd[0], cmd);
    }

  
  return 0;
}
