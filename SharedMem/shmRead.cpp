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
  int valueRead;
  
  int shm_id = shmget(myKeyVal, 1024 , 0);
  
  if (shm_id<=0)
  {
     cerr << "shmget  failed ... " << endl;
     return 2;
  }
  
  int *sharedValuePtr;
  sharedValuePtr = (int *) shmat(shm_id, NULL, 0);
  
  if ( sharedValuePtr == (int *) -1 )
  {
     cerr << "shmat failed ..." << endl;
     return 3;
  } 
  
  valueRead = sharedValuePtr[0];
  
  cout << "read: " << valueRead << endl;
  
  int detach_status = shmdt(sharedValuePtr);
  if (detach_status!=0)
  {
     cerr << "detach failed ..." << endl;
     return 4;
  }

  return 0;
}














