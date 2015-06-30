#include <iostream>

using namespace std;

class Receiver
{
	public:
	void action()
	{
		cout<<"real action1"<<endl;
	}
};


class Command
{
	public:
	Command(Receiver* r)
	{
		receiver=r;
	}
	virtual void execute()=0;

	protected:
	Receiver * receiver;
};

class ConcreteCommand:public Command
{
	public:
	ConcreteCommand(Receiver * r):Command(r)
	{
		
	}
	void execute()
	{
		receiver->action();	
	}
};

class Invoker
{
	public:
	void setCommand(Command * c)
	{
		command=c;
	}
	void execute()
	{
		command->execute();
	}

	private:
	Command* command;
};



int main()
{
	cout<<"命令模式基本代码"<<endl;
	Receiver * r=new Receiver();
	Command * c=new ConcreteCommand(r);

	Invoker * invoker=new Invoker();
	invoker->setCommand(c);
	invoker->execute();

	delete r;
	delete c;
	delete invoker;

	return 0;
}
