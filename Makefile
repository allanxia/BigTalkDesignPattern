all:chapter2_1 chapter2_2 chapter3_1 chapter3_2 chapter6_1 chapter6_2

#switch��default����
chapter2_1:chapter2_1.o
	g++ -o chapter2_1 chapter2_1.o
chapter2_1.o:chapter2_1.c
	g++ -c chapter2_1.c

#�򵥹���ģʽ
chapter2_2:chapter2_2.o
	g++ -o chapter2_2 chapter2_2.o
chapter2_2.o:chapter2_2.c
	g++ -c chapter2_2.c

#����ģʽ
chapter3_1:chapter3_1.o
	g++ -o chapter3_1 chapter3_1.o
chapter3_1.o:chapter3_1.c
	g++ -c chapter3_1.c

#����Ĳ���ģʽ
chapter3_2:chapter3_2.o
	g++ -o chapter3_2 chapter3_2.o
chapter3_2.o:chapter3_2.c
	g++ -c chapter3_2.c

#װ��ģʽ
chapter6_1:chapter6_1.o
	g++ -o chapter6_1 chapter6_1.o
chapter6_1.o:chapter6_1.c
	g++ -c chapter6_1.c

#����װ��ģʽ��ʵ��
chapter6_2:chapter6_2.o
	g++ -o chapter6_2 chapter6_2.o
chapter6_2.o:chapter6_2.c
	g++ -c chapter6_2.c



.PHONY:all
.PHONY:clean
.PHONY:cleanAll
clean:
	del *.o *~ *.swp
cleanAll:
	del *.o *~ *.exe *.swp
