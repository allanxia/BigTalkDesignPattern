all:chapter2_1 chapter2_2 chapter3_1 chapter3_2 chapter6_1 chapter6_2

#switch中default测试
chapter2_1:chapter2_1.o
	g++ -o chapter2_1 chapter2_1.o
chapter2_1.o:chapter2_1.c
	g++ -c chapter2_1.c

#简单工厂模式
chapter2_2:chapter2_2.o
	g++ -o chapter2_2 chapter2_2.o
chapter2_2.o:chapter2_2.c
	g++ -c chapter2_2.c

#策略模式
chapter3_1:chapter3_1.o
	g++ -o chapter3_1 chapter3_1.o
chapter3_1.o:chapter3_1.c
	g++ -c chapter3_1.c

#具体的策略模式
chapter3_2:chapter3_2.o
	g++ -o chapter3_2 chapter3_2.o
chapter3_2.o:chapter3_2.c
	g++ -c chapter3_2.c

#装饰模式
chapter6_1:chapter6_1.o
	g++ -o chapter6_1 chapter6_1.o
chapter6_1.o:chapter6_1.c
	g++ -c chapter6_1.c

#具体装饰模式的实现
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
