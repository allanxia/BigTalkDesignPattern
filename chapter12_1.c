#include <iostream>


class SubSystem1
{
	public:
			void method1()
			{
				std::cout<<"SubSystem1::method1 invoke"<<std::endl;
			}
};

class SubSystem2
{
	public:
			void method2()
			{
				std::cout<<"SubSystem2::method2 invoke"<<std::endl;
			}
};

class SubSystem3
{
	public:
			void method3()
			{
				std::cout<<"SubSystem3::method3 invoke"<<std::endl;
			}
};


class Facade
{
		public:
				Facade()
				{
					subSystem1=new SubSystem1();
					subSystem2=new SubSystem2();
					subSystem3=new SubSystem3();
				}
				void methodA()
				{
					std::cout<<"Facade methodA include:"<<std::endl;
					subSystem1->method1();
					subSystem2->method2();
				}
				void methodB()
				{
					std::cout<<"Facade methodB include:"<<std::endl;
					subSystem1->method1();
					subSystem3->method3();
				}
				~Facade()
				{
					if(subSystem1!=NULL)
							delete subSystem1;
					if(subSystem2!=NULL)
							delete subSystem2;
					if(subSystem3!=NULL)
							delete subSystem3;
				}
		private:
				SubSystem1 * subSystem1;
				SubSystem2 * subSystem2;
			  	SubSystem3 * subSystem3;	
};

int main()
{
	std::cout<<"外观模式测试"<<std::endl;
	Facade * facade=new Facade;
	facade->methodA();
	facade->methodB();
	delete facade;
	return 0;
}
