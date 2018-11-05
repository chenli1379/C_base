用到的知识点:
	多线程
	fork exec wait
	IO
	open read write close	
	动态库
	进程间通信
        	共享内存,信号量
	信号
简介:
	主程序分为父子进程,父进程实现:
	1>.读文件并取出数据
		通过open("tmp.txt")打开tmp.txt文件,建立缓冲区buf,read(pfile,buf,sizeof(buf))
		读取文件内容.放入buf缓冲区.用sscanf(buf,"%d+%d",&a,&b)取出数据.
		调用动态链接库函数add(a,b);sprintf(buf,"%d+%d=%d",a,b,c);将处理好的数据放入buf;
	2>.建立共享内存,使用strcpy(pshm,buf),将buf数据放入共享内存
		int shmid=shmget(1234,100,IPC_CREAT|0644);
		if(shmid==-1) perror("shmget"),exit(1);
		char *pshm=(char *)shmat(shmid,NULL,0);
		strcpy(pshm,buf);
	3>.建立信号量,在父进程放入数据后执行V操作,子进程取数据时执行P操作
		union semun
		{int val;};
		void op_v(int id)
		{
			struct sembuf sb[1]={0,1,0};
			semop(id,sb,1);
		}


		int semid=semget(1234,1,IPC_CREAT | 0644);
		if(semid==-1) perror("semget"),exit(1);
		union semun su;
		su.val=0;
		semctl(semid,0,SETVAL,su);
	4>.设置信号,SIGCHID,
		struct sigaction set;
		set.sa_handler=handler;
		set.sa_flags=0;
		sigemptyset(&set.sa_mask);
		sigaction(SIGCHLD,&set,NULL);
	   信号处理函数
		void handler(int s)
		{
			wait(NULL);
			exit(0);
		}
	   回收子进程
	
	子进程实现:
	1>.检测信号量,等待父进程将数据放入共享内存.
	2>.从共享内存中读取数据,写入tmp.txt文件.

注意:动态链接库虽然指定了路径,但还是不行,即在设置LD_LIBRARY_PATH=.  这时才链接到动态链接库























