all: Myshell.o ls.o cp.o ps.o mv.o ps_f.o grep2.o
	gcc Myshell.o ls.o cp.o ps.o mv.o ps_f.o grep2.o -o myshell -lreadline

Myshell.o: Myshell.c
	gcc -c Myshell.c -o Myshell.o -lreadline
ls.o: ls.c
	gcc -c ls.c -o ls.o -lreadline
cp.o: cp.c
	gcc -c cp.c -o cp.o -lreadline
ps.o: ps.c
	gcc -c ps.c -o ps.o -lreadline
mv.o: mv.c
	gcc -c mv.c -o mv.o -lreadline
ps_f.o:ps_f.c
	gcc -c ps_f.c -o ps_f.o -lreadline
grep2.o:grep2.c
	gcc -c grep2.c -o grep2.o -lreadline
