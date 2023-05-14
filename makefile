main: main.o mkdir.o ls.o pwd.o rm.o rmdir.o touch.o
	gcc main.o mkdir.o ls.o pwd.o rm.o rmdir.o touch.o -o main

main.o: main.c
	gcc -c main.c

mkdir.o: mkdir.c mkdir.h
	gcc -c mkdir.c

ls.o: ls.c ls.h
	gcc -c ls.c

pwd.o: pwd.c pwd.h
	gcc -c pwd.c

rm.o: rm.c rm.h
	gcc -c rm.c
rmdir.o: rmdir.c rmdir.h
	gcc -c rmdir.c

touch.o: touch.c touch.h
	gcc -c touch.c

clean:
	rm *.o