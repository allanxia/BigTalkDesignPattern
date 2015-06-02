#include <stdlib.h>
#include <stdio.h>
#include <iostream>

class Component
{
	public:
		virtual	void operation()=0;
};

class ConcreteComponent:public Component
{
	public:
		void operation()
		{
			std::cout<<"ConcreteCompont:operation()"<<std::endl;
		}
};

class Decorator:public Component
{
	public:
		void operation()
		{
			if(component!=NULL)
			{
				component->operation();
			}
		}
		void setComponent(Component * c)
		{
			component=c;
		}
	private:
		Component * component;
};

class ConcreteDecoratorA:public Decorator
{
	public:
		void operation()
		{
			Decorator::operation();
			std::cout<<"ConcreteDecoratorA::operation()"<<std::endl;
		}
};

class ConcreteDecoratorB:public Decorator
{
	public:
		void operation()
		{
			Decorator::operation();
			std::cout<<"ConcreteDecoratorB::operation()"<<std::endl;
		}
};

int main()
{
	std::cout<<"×°ÊÎÄ£Ê½²âÊÔ"<<std::endl;
	ConcreteComponent *c=new ConcreteComponent();
	ConcreteDecoratorA *cda=new ConcreteDecoratorA();
	ConcreteDecoratorB *cdb=new ConcreteDecoratorB();
	cda->setComponent(c);
	cdb->setComponent(cda);

	std::cout<<"cda->operation() include:"<<std::endl;
	cda->operation();

	std::cout<<"--------------------"<<std::endl;
	
	std::cout<<"cdb->operation() include:"<<std::endl;
	cdb->operation();

	delete c;
	delete cda;
	delete cdb;
	return 0;
}
