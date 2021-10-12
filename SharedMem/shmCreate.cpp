#include <iostream>
#include <cstdlib>

#include <sys/shm.h>

using namespace std;

int main(int argc, char *argv[])
{
  if (argc!=2) 
  {
     cerr << "USAGE: " << argv[0] << " <key Number>" << endl;
     return 1; 
  }  
  
  int myKeyVal = atoi(argv[1]);
  
  int shm_id = shmget(myKeyVal, 1024 , IPC_CREAT | IPC_EXCL | 0666);
  
  cout << "shmget gave: " << shm_id << endl; 

  return 0;
}
