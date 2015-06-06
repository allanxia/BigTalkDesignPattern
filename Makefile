all:chapter2_1 chapter2_2 chapter3_1 chapter3_2 chapter6_1 chapter6_2 \
	chapter7_1 chapter7_2 chapter8_1 chapter8_2 chapter9_1 chapter9_2 \
	chapter10_1  chapter12_1 chapter12_2 chapter13_1 chapter14_1 \
	chapter14_2 chapter15_1 chapter15_2

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

#����ģʽ��ʵ��
chapter7_1:chapter7_1.o
	g++ -o chapter7_1 chapter7_1.o
chapter7_1.o:chapter7_1.c
	g++ -c chapter7_1.c

#�������ģʽ��ʵ��
chapter7_2:chapter7_2.o
	g++ -o chapter7_2 chapter7_2.o
chapter7_2.o:chapter7_2.c
	g++ -c chapter7_2.c

#���幤������ģʽһ��һ��ʵ��
chapter8_1:chapter8_1.o
	g++ -o chapter8_1 chapter8_1.o
chapter8_1.o:chapter8_1.c
	g++ -c chapter8_1.c

#���幤������ģʽһ�Զ��ʵ��
chapter8_2:chapter8_2.o
	g++ -o chapter8_2 chapter8_2.o
chapter8_2.o:chapter8_2.c
	g++ -c chapter8_2.c

#����ԭ��ģʽ��ʵ��
chapter9_1:chapter9_1.o
	g++ -o chapter9_1 chapter9_1.o
chapter9_1.o:chapter9_1.c
	g++ -c chapter9_1.c

#ԭ��ģʽ�����ʵ��
chapter9_2:chapter9_2.o
	g++ -o chapter9_2 chapter9_2.o
chapter9_2.o:chapter9_2.c
	g++ -c chapter9_2.c

#ģ�巽��ģʽ��ʵ��
chapter10_1:chapter10_1.o
	g++ -o chapter10_1 chapter10_1.o
chapter10_1.o:chapter10_1.c
	g++ -c chapter10_1.c

#���ģʽ����
chapter12_1:chapter12_1.o
	g++ -o chapter12_1 chapter12_1.o
chapter12_1.o:chapter12_1.c
	g++ -c chapter12_1.c

#�����������ģʽ����
chapter12_2:chapter12_2.o
	g++ -o chapter12_2 chapter12_2.o
chapter12_2.o:chapter12_2.c
	g++ -c chapter12_2.c


#������ģʽ����
chapter13_1:chapter13_1.o
	g++ -o chapter13_1 chapter13_1.o
chapter13_1.o:chapter13_1.c
	g++ -c chapter13_1.c


#�۲���ģʽ����
chapter14_1:chapter14_1.o
	g++ -o chapter14_1 chapter14_1.o
chapter14_1.o:chapter14_1.c
	g++ -c chapter14_1.c

#��Ʊ���׵Ĺ۲���ģʽ����
chapter14_2:chapter14_2.o
	g++ -o chapter14_2 chapter14_2.o
chapter14_2.o:chapter14_2.c
	g++ -c chapter14_2.c

#���󹤳�ģʽ����
chapter15_1:chapter15_1.o
	g++ -o chapter15_1 chapter15_1.o
chapter15_1.o:chapter15_1.c
	g++ -c chapter15_1.c

#ʵ�ʳ��󹤳�ģʽ���������磩����
chapter15_2:chapter15_2.o
	g++ -o chapter15_2 chapter15_2.o
chapter15_2.o:chapter15_2.c
	g++ -c chapter15_2.c







.PHONY:all
.PHONY:clean
.PHONY:cleanAll
clean:
	del *.o *~ *.swp
cleanAll:
	del *.o *~ *.exe *.swp
