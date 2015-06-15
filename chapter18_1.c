#include <iostream>
#include <string>
using namespace std;
class Memento
{
		public:
		Memento(string s)
		{
			state=s;	
		}
		string getState()
		{
			return state;
		}
		private:
				string state;


};

class Originator
{
		public:
				void setMemento(Memento *m)
				{
					state=m->getState();
				}
				Memento * createMemento(){
					return new Memento(state);
				}
				void setState(string s)
				{
					state=s;
				}
				string getState()
				{
					return state;
				}
		private:
				string state;
};


class Caretaker
{
	public:
			Memento* getMemento()
			{
				return memento;
			}
			void setMemento(Memento *m)
			{
				memento=m;
			}
	private:
			Memento * memento;

};
int main()
{
	std::cout<<"±¸ÍüÂ¼Ä£Ê½²âÊÔ"<<std::endl;
	Originator * originator=new Originator();
	originator->setState("origin state");
	std::cout<<"state 1:"<<originator->getState()<<std::endl;
	Caretaker * caretaker=new Caretaker();
	caretaker->setMemento(originator->createMemento());
	originator->setState("change to state");
	std::cout<<"state 2:"<<originator->getState()<<std::endl;
	originator->setMemento(caretaker->getMemento());
	std::cout<<"state 3:"<<originator->getState()<<std::endl;

	return 0;
}
