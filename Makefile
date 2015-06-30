all:chapter2_1 chapter2_2 chapter3_1 chapter3_2 chapter6_1 chapter6_2 \
	chapter7_1 chapter7_2 chapter8_1 chapter8_2 chapter9_1 chapter9_2 \
	chapter10_1  chapter12_1 chapter12_2 chapter13_1 chapter14_1 \
	chapter14_2 chapter15_1 chapter15_2 chapter18_1 chapter18_2 \
	chapter19_1  chapter19_2 chapter20_1 chapter21_1 chapter21_2 \
	chapter22_1 chapter22_2 chapter23_1 chapter24_1 chapter25_1 \
	chapter25_2

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

#代理模式的实现
chapter7_1:chapter7_1.o
	g++ -o chapter7_1 chapter7_1.o
chapter7_1.o:chapter7_1.c
	g++ -c chapter7_1.c

#具体代理模式的实现
chapter7_2:chapter7_2.o
	g++ -o chapter7_2 chapter7_2.o
chapter7_2.o:chapter7_2.c
	g++ -c chapter7_2.c

#具体工厂方法模式一对一的实现
chapter8_1:chapter8_1.o
	g++ -o chapter8_1 chapter8_1.o
chapter8_1.o:chapter8_1.c
	g++ -c chapter8_1.c

#具体工厂方法模式一对多的实现
chapter8_2:chapter8_2.o
	g++ -o chapter8_2 chapter8_2.o
chapter8_2.o:chapter8_2.c
	g++ -c chapter8_2.c

#基本原型模式的实现
chapter9_1:chapter9_1.o
	g++ -o chapter9_1 chapter9_1.o
chapter9_1.o:chapter9_1.c
	g++ -c chapter9_1.c

#原型模式深拷贝的实现
chapter9_2:chapter9_2.o
	g++ -o chapter9_2 chapter9_2.o
chapter9_2.o:chapter9_2.c
	g++ -c chapter9_2.c

#模板方法模式的实现
chapter10_1:chapter10_1.o
	g++ -o chapter10_1 chapter10_1.o
chapter10_1.o:chapter10_1.c
	g++ -c chapter10_1.c

#外观模式例子
chapter12_1:chapter12_1.o
	g++ -o chapter12_1 chapter12_1.o
chapter12_1.o:chapter12_1.c
	g++ -c chapter12_1.c

#申请贷款的外观模式例子
chapter12_2:chapter12_2.o
	g++ -o chapter12_2 chapter12_2.o
chapter12_2.o:chapter12_2.c
	g++ -c chapter12_2.c


#建造者模式例子
chapter13_1:chapter13_1.o
	g++ -o chapter13_1 chapter13_1.o
chapter13_1.o:chapter13_1.c
	g++ -c chapter13_1.c


#观察者模式例子
chapter14_1:chapter14_1.o
	g++ -o chapter14_1 chapter14_1.o
chapter14_1.o:chapter14_1.c
	g++ -c chapter14_1.c

#股票交易的观察者模式例子
chapter14_2:chapter14_2.o
	g++ -o chapter14_2 chapter14_2.o
chapter14_2.o:chapter14_2.c
	g++ -c chapter14_2.c

#抽象工厂模式例子
chapter15_1:chapter15_1.o
	g++ -o chapter15_1 chapter15_1.o
chapter15_1.o:chapter15_1.c
	g++ -c chapter15_1.c

#实际抽象工厂模式（动物世界）例子
chapter15_2:chapter15_2.o
	g++ -o chapter15_2 chapter15_2.o
chapter15_2.o:chapter15_2.c
	g++ -c chapter15_2.c

#备忘录模式例子
chapter18_1:chapter18_1.o
	g++ -o chapter18_1 chapter18_1.o
chapter18_1.o:chapter18_1.c
	g++ -c chapter18_1.c

#具体的备忘录，经销商例子
chapter18_2:chapter18_2.o
	g++ -o chapter18_2 chapter18_2.o
chapter18_2.o:chapter18_2.c
	g++ -c chapter18_2.c

#基本组合模式例子
chapter19_1:chapter19_1.o
	g++ -o chapter19_1 chapter19_1.o
chapter19_1.o:chapter19_1.c
	g++ -c chapter19_1.c

#绘图程序的组合模式例子
chapter19_2:chapter19_2.o
	g++ -o chapter19_2 chapter19_2.o
chapter19_2.o:chapter19_2.c
	g++ -c chapter19_2.c

#迭代器模式测试
chapter20_1:chapter20_1.o
	g++ -o chapter20_1 chapter20_1.o
chapter20_1.o:chapter20_1.c
	g++ -c chapter20_1.c

#单例模式
chapter21_1:chapter21_1.o
	g++ -o chapter21_1 chapter21_1.o
chapter21_1.o:chapter21_1.c
	g++ -c chapter21_1.c

#单例模式
chapter21_2:chapter21_2.o
	g++ -o chapter21_2 chapter21_2.o
chapter21_2.o:chapter21_2.c
	g++ -c chapter21_2.c

#桥接模式例子
chapter22_1:chapter22_1.o
	g++ -o chapter22_1 chapter22_1.o
chapter22_1.o:chapter22_1.c
	g++ -c chapter22_1.c

#不同品牌手机游戏桥接模式例子
chapter22_2:chapter22_2.o
	g++ -o chapter22_2 chapter22_2.o
chapter22_2.o:chapter22_2.c
	g++ -c chapter22_2.c

#命令模式例子
chapter23_1:chapter23_1.o
	g++ -o chapter23_1 chapter23_1.o
chapter23_1.o:chapter23_1.c
	g++ -c chapter23_1.c

#责任链模式代码
chapter24_1:chapter24_1.o
	g++ -o chapter24_1 chapter24_1.o
chapter24_1.o:chapter24_1.c
	g++ -c chapter24_1.c

#中介者模式代码
chapter25_1:chapter25_1.o
	g++ -o chapter25_1 chapter25_1.o
chapter25_1.o:chapter25_1.c
	g++ -c chapter25_1.c

#聊天室中介者模式代码
chapter25_2:chapter25_2.o
	g++ -o chapter25_2 chapter25_2.o
chapter25_2.o:chapter25_2.c
	g++ -c chapter25_2.c


.PHONY:all
.PHONY:clean
.PHONY:cleanAll
clean:
	del *.o *~ *.swp
cleanAll:
	del *.o *~ *.exe *.swp
