#include <iostream>
#include <string>

using namespace std;

class Colleague;
class Mediator
{
	public:
	virtual void send(string message,Colleague * c)=0;

};


class Colleague
{
		public:
		Colleague(Mediator *m)
		{
			mediator=m;
		}
		void send(string message)
		{
			mediator->send(message,this);
		}
		virtual void notify(string message)=0;
		protected:
		Mediator * mediator;

};

class ConcreteColleague1:public Colleague
{
		public:
		ConcreteColleague1(Mediator * c):Colleague(c)
		{

		}
		void notify(string message)
		{
			cout<<"concreteColleague1 receive message:"<<message<<endl;
		}

};

class ConcreteColleague2:public Colleague
{
		public:
		ConcreteColleague2(Mediator *m):Colleague(m)
		{

		}
		void notify(string message)
		{
			cout<<"concreteColleague2 receive message:"<<message<<endl;
		}

};


class ConcreteMediator:public Mediator
{
	public:
	void send(string message,Colleague * c)
	{
		ConcreteColleague1* c1=dynamic_cast<ConcreteColleague1 *>(c);
		ConcreteColleague2* c2=dynamic_cast<ConcreteColleague2 *>(c);
		if(c1!=NULL)
		{
			cc2->notify(message);
		}

		if(c2!=NULL)
		{
			cc1->notify(message);
		}

	}

	void setCC1(ConcreteColleague1 * c)
	{
		cc1=c;
	}	
	void setCC2(ConcreteColleague2 * c)
	{
		cc2=c;
	}
	private:
	ConcreteColleague1 * cc1;
	ConcreteColleague2 * cc2;

};


int main()
{
	ConcreteMediator *m=new ConcreteMediator();
	ConcreteColleague1 * cc1=new ConcreteColleague1(m);
	ConcreteColleague2 * cc2=new ConcreteColleague2(m);

	m->setCC1(cc1);
	m->setCC2(cc2);

	cc1->send("how are you !");
	cc2->send("fine ,thank you");

	return 0;


}
