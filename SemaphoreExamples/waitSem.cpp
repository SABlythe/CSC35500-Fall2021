#include <cstdlib>
#include <iostream>

#include <sys/sem.h>

using namespace std;

#define NUM_SEMAPHORES 1
#define NUM_COMMANDS 1

int main (int argc, char *argv[])
{
  if (argc!=2)
  {
    cerr << "Usage: " << argv[0] << " <key-value>" << endl;
    return 1;
  }

  int sharedKey = atoi(argv[1]); 
  
  int sem_id = semget(sharedKey, NUM_SEMAPHORES, 0); // 0 for flag means get ... not create
  
  if (sem_id<0)
  {
    cerr << "semget FAILD!" << endl;
    return 2;
  }
  
  struct sembuf    semWaitCommand[NUM_COMMANDS];
  
  semWaitCommand[0].sem_num =  0; 
  semWaitCommand[0].sem_op  = -1;
  semWaitCommand[0].sem_flg =  0; 

  int semResult = semop(sem_id, semWaitCommand, NUM_COMMANDS);  

  if (semResult == -1)
  {
     cerr << "Unable to wait on semaphore!" << endl;
     return 3;
  }
  
  cout << "Done Waiting!" << endl;

  return 0;
}



















