#include <iostream>


using namespace std;

class Implementor
{
	public:
	virtual void operationImpl()=0;
};

class ConcreteImplementorA:public Implementor
{
	public:
	void operationImpl()
	{
		cout<<"ConcreteImplementorA::operationImpl"<<endl;
	}
	
};

class ConcreteImplementorB:public Implementor
{
	public:
	void operationImpl()
	{
		cout<<"ConcreteImplementorB::operationImpl"<<endl;
	}
	
};

class Abstraction
{
	public:
		virtual void operation()=0;
		void setImplementor(Implementor * i)
		{
			impl=i;
		}
		Implementor * getImplementor()
		{
				return impl;
		}
	protected:
		Implementor * impl;		
};

class RefinedAbstraction:public Abstraction
{
	public:
		void operation()
		{
			impl->operationImpl();
		}
};

int main()
{
	cout<<"桥接模式例子"<<endl;
	Abstraction * ab=new RefinedAbstraction();
	Implementor * cia=new ConcreteImplementorA();
	ab->setImplementor(cia);
	ab->operation();
	Implementor * cib=new ConcreteImplementorB();
	ab->setImplementor(cib);
	ab->operation();
	delete cia;
	delete cib;
	delete ab;
	return 0;
}
