#include <cstdlib>
#include <iostream>

#include <sys/sem.h>

using namespace std;

#define NUM_SEMAPHORES 1
int main (int argc, char *argv[])
{
  if (argc!=2)
  {
    cerr << "Usage: " << argv[0] << " <key-value>" << endl;
    return 1;
  }

  int sharedKey = atoi(argv[1]); 
  
  int sem_id = semget(sharedKey, NUM_SEMAPHORES, IPC_CREAT|IPC_EXCL|0600);
  
  cout << "semget gave: " << sem_id << endl;

  if (sem_id <0) // semaphore creation failure - likely already exists !
    {
      sem_id = semget(sharedKey, NUM_SEMAPHORES, 0);
    }

  cout << "semget NOW gave: " << sem_id << endl;

  // next, let's initialize the semaphore.
  int status = semctl(sem_id, 0, SETVAL, 4 );

  cout << "semctl returned " << status << endl;

  // let's try to wait 10 times ...
  for (int i=0; i<10; i++)
    {
      cout << "Waiting on pass #" << i << " ... "; cout.flush();

      struct sembuf semWaitCommand[1];

      semWaitCommand[0].sem_num = 0;
      semWaitCommand[0].sem_op = -1; // wait (once)
      semWaitCommand[0].sem_flg = 0;

      /*int semResult =*/  semop(sem_id, semWaitCommand, 1);
      // could check semResult to make sure it is 0 if you want. 

      cout << "done waiting!" << endl;
    }
  
  return 0;
}

