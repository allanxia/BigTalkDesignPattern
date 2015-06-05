#include <iostream>
#include <string>

using namespace std;
class Prototype
{
	public:
			Prototype(string str=""):id(str)
			{
			}
			//对C++而言需要返回指针
			virtual Prototype * clone()=0;
			string getId() const
			{
				return id;
			}
	private:
			string id;
	
};

class ConcretePrototype1:public Prototype
{
	public:
			ConcretePrototype1(string str=""):Prototype(str)
			{

			}
			Prototype * clone()
			{
				std::cout<<"ConcretePrototype1::clone()"<<std::endl;
				return new ConcretePrototype1(*this);
			}
};

class ConcretePrototype2:public Prototype
{
	public:
			ConcretePrototype2(string str=""):Prototype(str)
			{

			}
			Prototype * clone()
			{
				std::cout<<"ConcretePrototype2::clone()"<<std::endl;
				return new ConcretePrototype2(*this);
			}
};

int main()
{
	std::cout<<"原型模式测试"<<std::endl;
	ConcretePrototype1* cp1=new ConcretePrototype1("001");
	ConcretePrototype1* cp11=dynamic_cast<ConcretePrototype1 *>(cp1->clone());

	ConcretePrototype2* cp2=new ConcretePrototype2("002");
	ConcretePrototype2* cp22=dynamic_cast<ConcretePrototype2 *>(cp2->clone());

	delete cp1;
	delete cp11;
	delete cp2;
	delete cp22;
	return 0;
}
