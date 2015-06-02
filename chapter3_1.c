#include <stdlib.h>
#include <stdio.h>
#include <iostream>

class Strategy
{
	public:
		virtual void algorithmInterface()=0;

};

class ConcreteStrategyA:public Strategy
{
	public:
		void algorithmInterface()
		{
			std::cout<<"ConcreteStrategyA::algorithmInterface()"<<std::endl;
		}

};

class ConcreteStrategyB:public Strategy
{
	public:
		void algorithmInterface()
		{
			std::cout<<"ConcreteStrategyB::algorithmInterface()"<<std::endl;
		}

};

class ConcreteStrategyC:public Strategy
{
	public:
		void algorithmInterface()
		{
			std::cout<<"ConcreteStrategyC::algorithmInterface()"<<std::endl;
		}

};

class Context
{
	public:
		void setStrategy(Strategy * s)
		{
			strategy=s;
		}
		void contextInterface()
		{
			strategy->algorithmInterface();
		}
	private:
		Strategy* strategy;
};


int main()
{
	std::cout<<"²ßÂÔÄ£Ê½"<<std::endl;
	Context context;
	Strategy *sa=new ConcreteStrategyA();
	Strategy *sb=new ConcreteStrategyB();
	Strategy *sc=new ConcreteStrategyC();

	context.setStrategy(sa);
	context.contextInterface();

	context.setStrategy(sb);
	context.contextInterface();
	
	context.setStrategy(sc);
	context.contextInterface();

	delete sa;
	delete sb;
	delete sc;
	return 0;
}
