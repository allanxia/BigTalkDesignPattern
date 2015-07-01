#include <iostream>
#include <map>

using namespace std;


class FlyWeight
{
		public:
				virtual void operation(int extrinsicState)=0;

};

class ConcreteFlyWeight:public FlyWeight
{
		public:
				void operation(int extrinsicState)
				{
					cout<<"ConcreteFlyWeight : "<<extrinsicState<<endl;
				}
};


class UnSharedConcreteFlyWeight:public FlyWeight
{
		public:
				void operation(int extrinsicState)
				{
					cout<<"UnSharedConcreteFlyWeight : "<<extrinsicState<<endl;
				}
};	

class FlyWeightFactory
{
		public:
				FlyWeightFactory()
				{
					flyWeights["X"]=new ConcreteFlyWeight();
					flyWeights["Y"]=new ConcreteFlyWeight();
					flyWeights["Z"]=new ConcreteFlyWeight();
				}

				FlyWeight * getFlyWeight(string key)
				{
					return flyWeights[key];
				}
		private:
				map<string,FlyWeight *> flyWeights;

};


int main()
{
	cout<<"基本享元模式代码"<<endl;
	int extrinsicState=22;
	FlyWeightFactory *factory=new FlyWeightFactory();

	FlyWeight * fx=factory->getFlyWeight("X");
	fx->operation(--extrinsicState);

	FlyWeight * fy=factory->getFlyWeight("Y");
	fy->operation(--extrinsicState);

	FlyWeight * fz=factory->getFlyWeight("Z");
	fz->operation(--extrinsicState);

	FlyWeight * fu=new UnSharedConcreteFlyWeight();
	fu->operation(--extrinsicState);

	delete factory;
	delete fx;
	delete fy;
	delete fz;
	delete fu;

	return 0;
}
