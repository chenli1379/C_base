�õ���֪ʶ��:
	���߳�
	fork exec wait
	IO
	open read write close	
	��̬��
	���̼�ͨ��
        	�����ڴ�,�ź���
	�ź�
���:
	�������Ϊ���ӽ���,������ʵ��:
	1>.���ļ���ȡ������
		ͨ��open("tmp.txt")��tmp.txt�ļ�,����������buf,read(pfile,buf,sizeof(buf))
		��ȡ�ļ�����.����buf������.��sscanf(buf,"%d+%d",&a,&b)ȡ������.
		���ö�̬���ӿ⺯��add(a,b);sprintf(buf,"%d+%d=%d",a,b,c);������õ����ݷ���buf;
	2>.���������ڴ�,ʹ��strcpy(pshm,buf),��buf���ݷ��빲���ڴ�
		int shmid=shmget(1234,100,IPC_CREAT|0644);
		if(shmid==-1) perror("shmget"),exit(1);
		char *pshm=(char *)shmat(shmid,NULL,0);
		strcpy(pshm,buf);
	3>.�����ź���,�ڸ����̷������ݺ�ִ��V����,�ӽ���ȡ����ʱִ��P����
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
	4>.�����ź�,SIGCHID,
		struct sigaction set;
		set.sa_handler=handler;
		set.sa_flags=0;
		sigemptyset(&set.sa_mask);
		sigaction(SIGCHLD,&set,NULL);
	   �źŴ�����
		void handler(int s)
		{
			wait(NULL);
			exit(0);
		}
	   �����ӽ���
	
	�ӽ���ʵ��:
	1>.����ź���,�ȴ������̽����ݷ��빲���ڴ�.
	2>.�ӹ����ڴ��ж�ȡ����,д��tmp.txt�ļ�.

ע��:��̬���ӿ���Ȼָ����·��,�����ǲ���,��������LD_LIBRARY_PATH=.  ��ʱ�����ӵ���̬���ӿ�























