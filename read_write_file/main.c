#include<stdio.h>
#include<string.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<sys/sem.h>
#include<unistd.h>
#include<fcntl.h>
#include"add.h"
#include<signal.h>

union semun 
{int val;};
void op_v(int id)
{
	struct sembuf sb[1]={0,1,0};
	semop(id,sb,1);
}
void handler(int s)
{
	wait(NULL);
	exit(0);
}

int main()
{
	int pfile=open("tmp.txt",O_RDONLY);
	char buf[20];
	read(pfile,buf,sizeof(buf));
	int a,b;
	sscanf(buf,"%d+%d",&a,&b);
	int c=add(a,b);
	sprintf(buf,"%d+%d=%d",a,b,c);

	int semid=semget(1234,1,IPC_CREAT | 0644);
	if(semid==-1) perror("semget"),exit(1);
	union semun su;
	su.val=0;
	semctl(semid,0,SETVAL,su);

	int shmid=shmget(1234,100,IPC_CREAT|0644);
	if(shmid==-1) perror("shmget"),exit(1);
	
	char *pshm=(char *)shmat(shmid,NULL,0);
	strcpy(pshm,buf);

	op_v(semid);

	shmdt(pshm);
	close(pfile);
	
	struct sigaction set;
	set.sa_handler=handler;
	set.sa_flags=0;
	sigemptyset(&set.sa_mask);
	sigaction(SIGCHLD,&set,NULL);	

	pid_t pid=fork();
	if(pid==0)            //child
	{
		execlp("mycat","mycat",NULL);
		exit(1);
	}
	else
	{
		while(1)
		{printf("parent is die\n");sleep(1);}
	}

	return 0;
}
