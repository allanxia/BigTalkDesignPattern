#include <stdlib.h>
#include <stdio.h>
#include <iostream>

class Context;

class State{
		public:
				virtual void handle(Context * c)=0;
};

class Context
{
		public:
				void setState(State * s)
				{
					state=s;
				}
				void request()
				{
					state->handle(this);
				}

		private:
				State * state;
};

class ConcreteStateA:public State
{
	public:
			void handle(Context * c);
};

class ConcreteStateB:public State
{
	public:
			void handle(Context * c);
};

void ConcreteStateA::handle(Context * c)
{
				std::cout<<"do something dependended on concreteStateA"<<std::endl;
				c->setState(new ConcreteStateB());
}


void ConcreteStateB::handle(Context * c)
{
				std::cout<<"do something dependended on concreteStateB"<<std::endl;
				c->setState(new ConcreteStateA());
}

int main()
{
	Context * c=new Context();
	State * sA=new ConcreteStateA();
	c->setState(sA);

	c->request();
	c->request();
	c->request();

	return 0;
}
