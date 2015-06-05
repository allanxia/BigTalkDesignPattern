#include <stdio.h>
#include <stdlib.h>
#include <iostream>


class Subject
{
		public:
				virtual void request()=0;
};

class RealSubject:public Subject
{
		public:
				void request()
				{
					std::cout<<"RealSubject::request()"<<std::endl;
				}

};

class Proxy:public Subject
{
		public:
				void request()
				{
						//使用延迟初始化的技术
						if(realSubject==NULL)
								realSubject=new RealSubject();

						realSubject->request();
				}
	private:
			RealSubject * realSubject;

};


int main()
{
	std::cout<<"代理模式测试："<<std::endl;
	Proxy * proxy=new Proxy();
	proxy->request();

	delete proxy;
	return 0;
}
