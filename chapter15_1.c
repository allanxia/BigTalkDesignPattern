#include <iostream>
#include <stdlib.h>
#include <stdio.h>


class AbstractProductA
{
	public:
			virtual void show()=0;
};

class  ProductA1:public AbstractProductA
{
	public:
			void show()
			{
				std::cout<<"ProductA1::show()"<<std::endl;
			}

};

class  ProductA2:public AbstractProductA
{
	public:
			void show()
			{
				std::cout<<"ProductA2::show()"<<std::endl;
			}
};

class AbstractProductB
{
	public :
			virtual void display()=0;
};

class ProductB1:public AbstractProductB
{
	public:
			void display()
			{
				std::cout<<"ProductB1::display()"<<std::endl;
			}
};

class ProductB2:public AbstractProductB
{
	public:
			void display()
			{
				std::cout<<"ProductB2::display()"<<std::endl;
			}
};


class AbstractFactory
{
		public:
				virtual AbstractProductA* createProductA()=0;
				virtual AbstractProductB* createProductB()=0;

};

class ConcreteFactory1:public AbstractFactory
{
		public:
				AbstractProductA *createProductA()
				{
					return new ProductA1();
				}
				AbstractProductB *createProductB()
				{
					return new ProductB1();
				}
};

class ConcreteFactory2:public AbstractFactory
{
		public:
				AbstractProductA *createProductA()
				{
					return new ProductA2();
				}
				AbstractProductB *createProductB()
				{
					return new ProductB2();
				}
};

class Client
{
	public:

	Client()
	{
	}
	Client(AbstractFactory *af)
	{
		abstractFactory=af;
	}
	AbstractProductA * getProductA()
	{
		return abstractProductA;
	}
	AbstractProductB* getProductB()
	{
		return abstractProductB;
	}


	void run()
	{
		abstractProductA=abstractFactory->createProductA();
		abstractProductB=abstractFactory->createProductB();	
	}
	~Client()
	{
		if(!abstractProductA)
				delete abstractProductA;
		if(!abstractProductB)
				delete abstractProductB;
	}

	private:
	AbstractFactory *abstractFactory;
	AbstractProductA * abstractProductA;
	AbstractProductB * abstractProductB;
};

int main()
{
	std::cout<<"抽象工厂模式测试"<<std::endl;
	AbstractFactory *af=new ConcreteFactory1();
	Client* client=new Client(af);

	client->run();
	client->getProductA()->show();
	client->getProductB()->display();

	delete af;
	delete client;
	return 0;
}
