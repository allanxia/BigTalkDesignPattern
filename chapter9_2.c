#include <iostream>
#include <string>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

class Data
{
		public:
		Data()
		{

		}
		Data(string n,string i):name(n),info(i)
		{

		}
				string name;
				string info;
};

class Prototype
{
	public:
			Prototype()
			{

			}
			Prototype(char *point):pChar(point)
			{
			}
			Prototype(const Prototype& rhs)
			{
				data=new Data(*rhs.getData());
				pChar=rhs.getPchar();
			}
			//对C++而言需要返回指针
			virtual Prototype * clone()=0;
			char * getPchar() const 
			{
				return pChar;
			}
			void setPchar(char * ch)
			{
				pChar=ch;
			}
			Data * getData() const
			{
				return data;
			}
			void setData(Data *d)
			{
				data=d;
			}
	private:
			char * pChar;
			Data * data;
	
};

class ConcretePrototype1:public Prototype
{
	public:
			ConcretePrototype1()
			{

			}
			ConcretePrototype1(char * point):Prototype(point)
			{

			}
			ConcretePrototype1(const ConcretePrototype1 & rhs):Prototype(rhs)
			{

			}
			Prototype * clone()
			{
				std::cout<<"ConcretePrototype1::clone()"<<std::endl;
				return new ConcretePrototype1(*this);
			}
};


int main()
{
	std::cout<<"原型模式测试"<<std::endl;
	char p1[]="hello";
	char p2[]="world";
	Data data1("Bill","Microsofe");
	ConcretePrototype1* cp1=new ConcretePrototype1(p1);
	cp1->setData(&data1);
	ConcretePrototype1* cp11=dynamic_cast<ConcretePrototype1 *>(cp1->clone());
	
	std::cout<<"cp1 information:------------------"<<std::endl;
	printf("cp1->pChar address:%p\n",cp1->getPchar());
	printf("cp1->data address:%p\n",cp1->getData());
	std::cout<<"cp1->data->name:"<<cp1->getData()->name<<"    cp1->data->info    "<<cp1->getData()->info<<std::endl;

	std::cout<<"cp11 information:------------------"<<std::endl;
	printf("cp11->pChar address:%p\n",cp11->getPchar());
	printf("cp11->data address:%p\n",cp11->getData());
	std::cout<<"cp11->data->name:"<<cp11->getData()->name<<"    cp11->data->info    "<<cp11->getData()->info<<std::endl;

	cp11->setPchar(p2);
	cp11->getData()->name="change to John";	
	
	std::cout<<"cp11 change:----------------"<<std::endl;
	std::cout<<"cp1 information:------------------"<<std::endl;
	printf("cp1->pChar address:%p\n",cp1->getPchar());
	printf("cp1->data address:%p\n",cp1->getData());
	std::cout<<"cp1->data->name:"<<cp1->getData()->name<<"    cp1->data->info    "<<cp1->getData()->info<<std::endl;

	std::cout<<"cp11 information:------------------"<<std::endl;
	printf("cp11->pChar address:%p\n",cp11->getPchar());
	printf("cp11->data address:%p\n",cp11->getData());
	std::cout<<"cp11->data->name:"<<cp11->getData()->name<<"    cp11->data->info    "<<cp11->getData()->info<<std::endl;


	delete cp1;
	delete cp11;
	return 0;
}
