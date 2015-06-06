#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include <list>


using namespace std;

class Stock;

class IInvestor
{
	public:
			IInvestor()
			{

			}
			IInvestor(string str,Stock *s):name(str),stock(s)
			{
			}
			Stock * getStock()
			{
				return stock;
			}
			string getName()
			{
				return name;
			}
			virtual void update()=0;
	private:
			Stock * stock;//投资的股票
			string name;//投资人名称
};

class Stock
{
	public:
			Stock()
			{

			}
			Stock(string str,double p):symbol(str),price(p)
			{
			}
			void setPrice(double p)
			{
					price=p;
					notify();
					std::cout<<std::endl;
			}
			double getPrice()
			{
					return price;
			}
			string getSymbol()
			{
					return symbol;
			}
			void attach(IInvestor * ii)
			{
				investors.push_back(ii);
			}	
			void deattach(IInvestor *ii)
			{
				investors.remove(ii);
			}
			
			void notify()
			{
				list<IInvestor*>::iterator iter=investors.begin();
				for(;iter!=investors.end();iter++)
				{
					(*iter)->update();
				}
			}

	private:
			string symbol; //股票名称
			double price;//股票价格
			list<IInvestor *> investors;//投资者

};

class IBM:public Stock
{
	public:
			IBM()
			{

			}
			IBM(string symbol,double price):Stock(symbol,price)
			{
			}
};

class Investor :public IInvestor
{
	public:
			Investor()
			{
			}
			Investor(string n,Stock *s):IInvestor(n,s)
			{
			}
			void update()
			{
				std::cout<<"Notified "<<getName()<<" of "<<getStock()->getSymbol()<<"'s change to "<<getStock()->getPrice()<<std::endl;
			}
	

};

int main()
{
	std::cout<<"股票交易的观察着模式的实现"<<std::endl;
	IBM *ibm=new IBM("IBM",120.10);

	IInvestor* investor1=new Investor("Sorros",ibm);
	IInvestor* investor2=new Investor("Berkshire",ibm);

	ibm->attach(investor1);
	ibm->attach(investor2);

	ibm->setPrice(120.50);
	ibm->setPrice(120.75);

	delete ibm;
	delete investor1;
	delete investor2;
	return 0;
}
