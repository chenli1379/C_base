#include<stdio.h>
#include<string.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<sys/sem.h>
#include<unistd.h>
#include<fcntl.h>
void op_p(int id)
{
	struct sembuf sb[1]={0,-1,0};
	semop(id,sb,1);
}
int main()
{
	int fd=open("tmp.txt",O_RDWR);
	int semid=semget(1234,0,0);
	if(semid==-1) perror("semget"),exit(1);
	

	int shmid=shmget(1234,100,0);
	if(shmid==-1) perror("shmget"),exit(1);

	op_p(semid);

	char *pshm=(char *)shmat(shmid,NULL,0);
	write(fd,pshm,strlen(pshm));
	
	close(fd);
	shmdt(pshm);
	return 0;
}
