#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string>
using namespace std;
class Customer
{
		public:
		Customer(string str=""):name(str)
		{
		
		}
		string getName() const
		{
				return name;
		}
		void setName(string str)
		{
			name=str;
		}

		private:
				string name;

};

class Bank
{
		public:
				bool hasSufficientSavings(Customer c,int amount)
				{
					std::cout<<"check bank for "<<c.getName()<<std::endl;
					return true;
				}
};

class Credit
{
		public:
				bool hasGoodCredit(Customer c)
				{
					std::cout<<"check credit for "<<c.getName()<<std::endl;
					return true;
				}
};

class Loan
{
		public:
				bool hasNoBadLoans(Customer c)
				{
					std::cout<<"check loans for "<<c.getName()<<std::endl;
					return true;
				}	
};

class Mortgage
{
		public:
				Mortgage()
				{
					bank=new Bank;
					credit=new Credit;
					loan=new Loan;
				}
				bool isEligible(Customer c, int amount)
				{
					std::cout<<c.getName()<<" applies for "<<amount<<std::endl;
					bool eligible=true;
					if(!bank->hasSufficientSavings(c,amount))
					{
						eligible=false;
					}
					else if(!credit->hasGoodCredit(c))
					{
						eligible=false;
					}
					else if(!loan->hasNoBadLoans(c))
					{
						eligible=false;
					}

					return eligible;
			
				}
				~Mortgage()
				{
					if(!bank)
							delete bank;
					if(!credit)
							delete credit;
					if(!loan)
							delete loan;
				}
		private:
				Bank * bank;
				Credit *credit;
				Loan * loan;
};


int main()
{
	std::cout<<"外观模式具体例子"<<std::endl;
	Mortgage *mortgage=new Mortgage();
	Customer c(string("John"));
	bool eligible =mortgage->isEligible(c,25000);

	std::cout<<c.getName()<<" has been "<<(eligible?"approve":"reject")<<std::endl;
	return 0;
}
