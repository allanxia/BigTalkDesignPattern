#include <iostream>

using namespace std;

class Handler
{
	public:
	void setSuccessor(Handler * h)
	{
		successor=h;
	}
	virtual void handleRequest(int request)=0;
	protected:
	Handler * successor;
};

class ConcreteHandler1:public Handler
{
	public:
	void handleRequest(int request)
	{
		if(request>=0&&request<=10)
			cout<<"ConcreteHandler1 handle between 0 and 10"<<endl;
		else 
		{
			if(successor!=NULL)
					successor->handleRequest(request);
		}
	}

};

class ConcreteHandler2:public Handler
{
	public:
	void handleRequest(int request)
	{
		if(request>10&&request<=20)
			cout<<"ConcreteHandler2 handle between 10 and 20"<<endl;
		else 
		{
			if(successor!=NULL)
					successor->handleRequest(request);
		}
	}

};


class ConcreteHandler3:public Handler
{
	public:
	void handleRequest(int request)
	{
		if(request>20)
			cout<<"ConcreteHandler3 handle greater than 20 "<<endl;
	}

};

int main()
{
	cout<<"基本的责任链模式代码"<<endl;
	Handler *h1=new ConcreteHandler1();
	Handler *h2=new ConcreteHandler2();
	Handler *h3=new ConcreteHandler3();

	h1->setSuccessor(h2);
	h2->setSuccessor(h3);

	int requests[]={1,3,11,19,20,22};
	for(int i=0;i<sizeof(requests)/sizeof(requests[0]);i++)
	{
		h1->handleRequest(requests[i]);
	}
	return 0;

}

