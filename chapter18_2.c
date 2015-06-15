#include <string>
#include <iostream>

using namespace std;

class Memento
{
		public:
				Memento(string n,string p,double b)
				{
					name=n;
					phone=p;
					budget=b;
				}
				string getName()
				{
					return name;
				}
				string getPhone()
				{
					return phone;
				}
				double getBudget()
				{
					return budget;
				}
		private:
				string name;
				string phone;
				double budget;
};

class SalesProspect
{
		public:
				void setName(string n)
				{
					name=n;
				}
				void setPhone(string p)
				{
					phone=p;
				}
				void setBudget(double b)
				{
					budget=b;
				}
				string getName()
				{
					return name;
				}
				string getPhone()
				{
					return phone;
				}
				double getBudget()
				{
					return budget;
				}
				Memento* saveMemento()
				{
					return new Memento(name,phone,budget);
				}
				void restoreMemento(Memento * m)
				{
					name=m->getName();
					phone=m->getPhone();
					budget=m->getBudget();
				}
		private:
				string name;
				string phone;
				double budget;
};

class ProspectMemory
{
		public:
			Memento * getMemento()
			{
				return memento;
			}
			void setMemento(Memento * m)
			{
				memento=m;
			}
		private:
			Memento * memento;
};

int main()
{
	std::cout<<"具体的备忘录模式测试"<<std::endl;
	SalesProspect * sale=new SalesProspect();
	sale->setName("John");
	sale->setPhone("15245869785");
	sale->setBudget(1200);

	std::cout<<"base sale:"<<std::endl<<sale->getName()<<std::endl<<sale->getPhone()<<std::endl<<sale->getBudget()<<std::endl<<std::endl;

	ProspectMemory * prospect=new ProspectMemory();
	prospect->setMemento(sale->saveMemento());

	sale->setName("Mike");
	sale->setPhone("13685478523");
	sale->setBudget(1500);

	std::cout<<"change sale:"<<std::endl<<sale->getName()<<std::endl<<sale->getPhone()<<std::endl<<sale->getBudget()<<std::endl<<std::endl;

	sale->restoreMemento(prospect->getMemento());

	std::cout<<"restore sale:"<<std::endl<<sale->getName()<<std::endl<<sale->getPhone()<<std::endl<<sale->getBudget()<<std::endl<<std::endl;

	delete sale;
	delete prospect;
	return 0;
}
