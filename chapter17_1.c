#include <stdlib.h>
#include <stdio.h>
#include <iostream>

class Adaptee
{
		public:
				void specialRequest()
				{
					std::cout<<"call specialRequest"<<std::endl;
				}

};


class Target
{
		public:
				virtual void request()
				{
					std::cout<<"call request"<<std::endl;
				}


};

class Adapter:public Target
{
		public:
				Adapter()
				{

				}
				Adapter(Adaptee * a)
				{
						adaptee=a;
				}
				void request()
				{
					adaptee->specialRequest();	
				}
		private:
				Adaptee * adaptee;

};


int main()
{
	Adaptee * ape=new Adaptee();
	Target * adapter=new Adapter(ape);
	adapter->request();
	return 0;
}
