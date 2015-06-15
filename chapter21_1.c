#include <iostream>

class Singleton
{
	public:
			//这里要将这个方法定义成静态的
			static Singleton * getInstance();
	private:
			Singleton()
			{

			}
	private:
			//静态成员函数只能操作静态成员变量，所以instance也应该是静态的
			static Singleton * instance;

};

//静态成员变量的初始化
Singleton * Singleton::instance=NULL;

Singleton * Singleton::getInstance()
{
				if(instance==NULL)
						instance=new Singleton();
				return instance;	
}

int main()
{
	Singleton *s1=Singleton::getInstance();
	Singleton *s2=Singleton::getInstance();
	if(s1==s2)
			std::cout<<"s1 and s2 are the same object"<<std::endl;

	return 0;
}
