#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string>
#include <vector>

using namespace std;

class LoadBalancer
{
	public:
			static LoadBalancer * getInstance();
			string getServer()
			{
				int i=rand()%5;
				return servers[i];
			}
	private:
			LoadBalancer()
			{
					servers.push_back("server I");
					servers.push_back("server II");
					servers.push_back("server III");
					servers.push_back("server IV");
					servers.push_back("server V");
			}	
	private:
			static	LoadBalancer * instance;
			vector<string> servers;
};

LoadBalancer * LoadBalancer::instance=NULL;

LoadBalancer * LoadBalancer::getInstance()
{
	if(instance==NULL)
			instance=new LoadBalancer();
	return instance;
}
int main()
{
	srand(time(0));
	LoadBalancer * load1=LoadBalancer::getInstance();
	LoadBalancer * load2=LoadBalancer::getInstance();

	cout<<load1->getServer()<<endl;
	cout<<load1->getServer()<<endl;
	cout<<load1->getServer()<<endl;
	cout<<load1->getServer()<<endl;
	cout<<load1->getServer()<<endl;
	cout<<load1->getServer()<<endl;
	cout<<load1->getServer()<<endl;
	cout<<load1->getServer()<<endl;
	cout<<load1->getServer()<<endl;
	cout<<load1->getServer()<<endl;
	cout<<load1->getServer()<<endl;
	cout<<load1->getServer()<<endl;

	delete load1;
	return 0;
}

