#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <list>
using namespace std;
class Subject;

class Observer
{
	public:
			Observer()
			{
			}
			Observer(Subject* s,string n)
			{
				subject=s;
				name=n;
			}
			virtual void update()=0;
			
			string getName()
			{
				return name;
			}

			Subject * getSubject()
			{
				return subject;
			}
	private:
			Subject *subject;
			string name;
};


class Subject
{
	public:
			void attach(Observer * o)
			{
				lists.push_back(o);
			}
			void detach(Observer * o)
			{
				lists.remove(o);
			}
			void notify()
			{
				list<Observer *>::iterator iter=lists.begin();
				for(;iter!=lists.end();iter++)
				{
					(*iter)->update();
				}
			}
			
			virtual string getState()=0;
	private:
			list<Observer*> lists;

};

class ConcreteSubject :public Subject
{
	public:
		string getState()
		{
			string str("ConcreteSubject notify");
			return str;
		}
};

class ConcreteObserver:public Observer
{
	public:
			ConcreteObserver(Subject * s,string n):Observer(s,n)
			{	

			}
			void update()
			{
				std::cout<<getName()<<" update from "<<getSubject()->getState()<<std::endl;
			}
};

int main()
{
	Subject *s=new ConcreteSubject();
	Observer *o1=new ConcreteObserver(s,"Bill");
	Observer *o2=new ConcreteObserver(s,"Joe");

	s->attach(o1);
	s->attach(o2);

	s->notify();

	delete s;
	delete o1;
	delete o2;
	return 0;
}
