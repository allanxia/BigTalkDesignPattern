#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <list>
#include <string>

using namespace std;

class Product
{
		public:
				void addPart(string str)
				{
					parts.push_back(str);
				}
				list<string>& getParts()
				{
					return parts;
				}
		private:
				list<string> parts;

};

class Builder
{
	public:
			Builder()
			{
				product=new Product();
			}
			virtual void buildPart1()=0;
			virtual void buildPart2()=0;
			void getResult()
			{
				list<string>::iterator iter=product->getParts().begin();
				for(;iter!=product->getParts().end();iter++)
				{
					std::cout<<*iter<<std::endl;
				}
			}
			virtual ~Builder()
			{
				if(!product)
						delete product;
			}
		protected:
			Product *product;
};

class ConcreteBuilder1:public Builder
{
		public:
			void buildPart1()
			{
				product->addPart("part one");
			}
			void buildPart2()
			{
				product->addPart("part two");
			}
	
};

class ConcreteBuilder2:public Builder
{
		public:
			void buildPart1()
			{
				product->addPart("part X");
			}
			void buildPart2()
			{
				product->addPart("part Y");
			}
	
};

class Director
{
	public:
			Director()
			{

			}
			Director(Builder * b):build(b)
			{
			}
			void construct()
			{
				build->buildPart1();
				build->buildPart2();
				build->getResult();
			}
				
	private:
			Builder *build;

};


int main()
{
	std::cout<<"建造者模式测试"<<std::endl;
	ConcreteBuilder1* cb1=new ConcreteBuilder1();
	Director d1(cb1);
	d1.construct();

	ConcreteBuilder2 * cb2=new ConcreteBuilder2();
	Director d2(cb2);
	d2.construct();
	return 0;
}
