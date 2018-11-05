.PHONLY:clean  main

all:main mycat

main:main.o libmyadd.so
	gcc $< -o main -L. -lmyadd

main.o:main.c
	gcc -c $< -o $@

mycat:mycat.o
	gcc $^ -o $@

%.o:%.c
	gcc -c $< -o $@

libmyadd.so: 
	gcc -fPIC -shared -o $@ add.c  
clean:
	rm -rf libmyadd.so main mycat *.o
