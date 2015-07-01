#include <iostream>
#include <list>

using namespace std;

class Context
{
};

class AbstractExpression
{
		public:
				virtual void interpret(Context * c)=0;
};

class TerminalExpression:public AbstractExpression
{
		public:
				void interpret(Context *c)
				{
					cout<<"TerminalExpression interpret"<<endl;
				}

};

class NonTerminalExpression:public AbstractExpression
{
		public:
				void interpret(Context *c)
				{
					cout<<"NonTerminalExpression interpret"<<endl;
				}
};

int main()
{
	cout<<"解释器模式代码"<<endl;
	list<AbstractExpression *> lists;
	Context *c=new Context;

	AbstractExpression * te1=new TerminalExpression();
	lists.push_back(te1);

	AbstractExpression * te2=new TerminalExpression();
	lists.push_back(te2);

	AbstractExpression * te3=new TerminalExpression();
	lists.push_back(te3);

	AbstractExpression * te4=new TerminalExpression();
	lists.push_back(te4);

	AbstractExpression * nte1=new NonTerminalExpression();
	lists.push_back(nte1);
	
	list<AbstractExpression*>::iterator iter=lists.begin();
	for(;iter!=lists.end();iter++)
	{
		(*iter)->interpret(c);
	}

	delete c;
	delete te1;
	delete te2;
	delete te3;
	delete te4;
	delete nte1;

	return 0;
}	



