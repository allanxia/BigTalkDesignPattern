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


//Ŀǰ��û�з��ֳ����Aggregate����;��ʲô����Ϊ����ĵ�������Ҫ֪��ConcreteAggregate
//���ڲ�ʵ��ϸ�ڣ�����stl����ͨ��Ϊÿ�����׶���һ���ڲ�������������֤��
class ConcreteAggregate:public Aggregate
{
		public:
				ConcreteAggregate()
				{
					datas=vector<string>(100);
				}
				friend class ConcreteIterator;

				//�����ʵ����һ�����⣬��datasԪ�س���100ʱ�������⣬��ʱ��Ҫ���ڴ����·���
				string& operator[](const int &index)
				{   
							return datas[index];
				}
		private:
				vector<string> datas;

};


//����ĵ�������,�ṩ�����������ڣ��������п��Ծ���ʵ����Щ�ӿڵĺ��壬����stl�е�����
//�ͷ�����������ǶԽӿڵĲ�ͬʵ��
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
		std::cout<<"������ģʽ����"<<std::endl;

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
