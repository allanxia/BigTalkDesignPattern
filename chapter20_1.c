#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Iterator;
class ConcreteIterator;

class Aggregate
{

};


//目前还没有发现抽象的Aggregate的用途是什么，因为具体的迭代器需要知道ConcreteAggregate
//的内部实现细节，而在stl中是通过为每种容易定义一个内部迭代器类来保证的
class ConcreteAggregate:public Aggregate
{
		public:
				ConcreteAggregate()
				{
					datas=vector<string>(100);
				}
				friend class ConcreteIterator;

				//这而其实还有一点问题，当datas元素超过100时会有问题，此时需要对内存重新分配
				string& operator[](const int &index)
				{   
							return datas[index];
				}
		private:
				vector<string> datas;

};


//抽象的迭代器类,提供了下面这个借口，在子类中可以具体实现这些接口的含义，比如stl中的正向
//和反向迭代器就是对接口的不同实现
class Iterator
{
		public:
				virtual string &first()=0;
				virtual string next()=0;
				virtual bool isDone()=0;
				virtual string &currentItem()=0;
};

class ConcreteIterator:public Iterator
{
		public:
				ConcreteIterator(ConcreteAggregate * agg)
				{
					aggregate=agg;
					cur=0;
				}
				 string& first()
				 {
						 return aggregate->datas[0];
				 }
				 string next()
				 {
						if(cur+1<aggregate->datas.size())
						{
								cur+=1;
								return aggregate->datas[cur];
						}else
						{
								return NULL;
						}

				 }
				 bool isDone()
				 {
						int len=aggregate->datas.size();
						if(cur==len-1)
								return true;
						else
								return false;
				 }
				 string& currentItem()
				 {
						return aggregate->datas[cur];
				 }
		private:
				 ConcreteAggregate * aggregate;
				 int cur;
};

int main()
{
		std::cout<<"迭代器模式测试"<<std::endl;

		ConcreteAggregate agg ;
		agg[0]="John";
		agg[1]="Mike";
		agg[2]="Bill";
		agg[3]="Joe";
		agg[4]="Kelly";

		ConcreteIterator* iter=new ConcreteIterator(&agg);
		std::cout<<iter->first()<<std::endl;
		iter->next();
		std::cout<<iter->currentItem()<<std::endl;
		

		return 0;
}
