#include <iostream>
#include <list>

using namespace std;

class ConcreteElementA;
class ConcreteElementB;

class Visitor
{
		public:
				virtual void visitConcreteElementA(ConcreteElementA * c)=0;
				virtual void visitConcreteElementB(ConcreteElementB *)=0;
};


class ConcreteVisitor1:public Visitor
{
		public:
				virtual void visitConcreteElementA(ConcreteElementA * c)
				{
					cout<<"ConcreteVisit1 operate on ConcreteElementA"<<endl;
				}


				virtual void visitConcreteElementB(ConcreteElementB *)
				{
					cout<<"ConcreteVisitor1 operate on ConcreteElementB"<<endl;
				}
};

class ConcreteVisitor2:public Visitor
{
		public:
				virtual void visitConcreteElementA(ConcreteElementA * c)
				{
					cout<<"ConcreteVisit2 operate on ConcreteElementA"<<endl;
				}


				virtual void visitConcreteElementB(ConcreteElementB *)
				{
					cout<<"ConcreteVisitor2 operate on ConcreteElementB"<<endl;
				}
};

class Element
{
		public:
				virtual void accept(Visitor * visitor)=0;

};

class ConcreteElementA:public Element
{
		public:
				 void accept(Visitor * visitor)
				{
					visitor->visitConcreteElementA(this);
				}

};

class ConcreteElementB:public Element
{
		public:
				 void accept(Visitor * visitor)
				{
					visitor->visitConcreteElementB(this);
				}

};


class ObjectStructure
{
		public:
				void attach(Element *e)
				{
					elements.push_back(e);
				}	
				void detach(Element *e)
				{
					elements.remove(e);
				}
				void accept(Visitor * v)
				{
					list<Element *>::iterator iter;
					for(iter=elements.begin();iter!=elements.end();iter++)
					{
						(*iter)->accept(v);
					}
				}

		private:
				list<Element *> elements;

};


int main()
{
	ObjectStructure * o=new ObjectStructure();
	Element * a=new ConcreteElementA();
	Element * b=new ConcreteElementB();
	o->attach(a);
	o->attach(b);

	Visitor * v1=new ConcreteVisitor1();
	Visitor *v2=new ConcreteVisitor2();
	o->accept(v1);
	o->accept(v2);

	delete o;
	delete a;
	delete b;
	delete v1;
	delete v2;


}
