#include <iostream>
#include <cstring>
#include <unistd.h>
using namespace std;

int main(int argc, char *argv[])
{
  char *array[3];
  array[0] = new char[10]; strcpy(array[0], "ls");
  array[1] = new char[10]; strcpy(array[1], "-la");
  array[2] = NULL;
  
  execvp(array[0], array);
  
  cout << "Did I print?" << endl;
  return 0;
}
