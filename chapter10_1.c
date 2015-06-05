#include <iostream>

class AbstractClass
{
		public:
				void templateMethod()
				{
					std::cout<<"before primitiveOperation1"<<std::endl;
					primitiveOperation1();
					std::cout<<"after primitiveOperation1"<<std::endl;
					std::cout<<"before primitiveOpreation2"<<std::endl;
					primitiveOperation2();
					std::cout<<"after primitiveOperation2"<<std::endl;
				}
				virtual void primitiveOperation1()=0;
				virtual void primitiveOperation2()=0;

};

class ConcreteClass :public AbstractClass
{
	public:
			void primitiveOperation1()
			{
				std::cout<<"ConcreteClass primitiveOperation1"<<std::endl;
			}
			void primitiveOperation2()
			{
				std::cout<<"ConcreteClass primitiveOperation2"<<std::endl;
			}

};

int main()
{
	AbstractClass * cc=new ConcreteClass;
	cc->templateMethod();
	return 0;
}
