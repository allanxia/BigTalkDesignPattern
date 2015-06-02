#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include <list>
#include <algorithm>

using namespace std;
/*一个具体的策略模式的例子
 * Strategy为SortStrategy
 * ConcreteStrategy为QuickSort,ShellSort,MergeSort
 * Contex为SortedList
 * */

//所有排序类的父类
class SortStrategy
{
	public:
			virtual void sort(list<string>& lists)=0;
};


class QuickSort:public SortStrategy
{
	public:
			void sort(list<string>& lists)
			{
				std::cout<<"QuickSort:sort"<<std::endl;
			}
};

class ShellSort:public SortStrategy
{
	public:
			void sort(list<string>& lists)
			{
				std::cout<<"ShellSort:sort"<<std::endl;
			}
};

class MergeSort:public SortStrategy
{
	public:
			void sort(list<string>& lists)
			{
				std::cout<<"Merge:sort"<<std::endl;
			}
};

class SortList
{
		public:
				void sort()
				{
					sortStrategy->sort(lists);	
					print();
				}
				void setSortStrategy(SortStrategy * s)
				{
					sortStrategy=s;
				}
				void add(string str)
				{
					lists.push_back(str);
				}
				void print()
				{
					list<string>::iterator iter;
					for(iter=lists.begin();iter!=lists.end();iter++)
					{
						std::cout<<*iter<<std::endl;
					}
				}

		private:
				list<string> lists;
				SortStrategy * sortStrategy;
};


int main()
{
	std::cout<<"具体的策略模式例子"<<std::endl;
	SortList sortList;
	sortList.add("allan");
	sortList.add("john");
	sortList.add("harrison");

	QuickSort *qs=new QuickSort();
	ShellSort *ss=new ShellSort();
	MergeSort *ms=new MergeSort();

	sortList.setSortStrategy(qs);
	sortList.sort();

	sortList.setSortStrategy(ss);
	sortList.sort();

	sortList.setSortStrategy(ms);
	sortList.sort();

	delete qs;
	delete ss;
	delete ms;

	return 0;
}
