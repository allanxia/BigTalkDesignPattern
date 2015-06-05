#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <list>
#include <algorithm>
using namespace std;

class Page
{
		public:
				virtual void show()=0;
};

class SkillPage:public Page
{
		public:
				void show()
				{
					std::cout<<"SkillPage::show"<<std::endl;
				}
};

class EducationPage:public Page
{
		public:
				void show()
				{
					std::cout<<"Education::show"<<std::endl;
				}

};

class ExperiencePage:public Page
{
		public:
				void show()
				{
					std::cout<<"Experience::show"<<std::endl;
				}
};

class Document
{
	public:
			virtual void factoryMethod()=0;
			list<Page*>& getLists()
			{
				return lists;
			}
			void print()
			{
				list<Page*>::iterator iter;
				for(iter=lists.begin();iter!=lists.end();iter++)
						(*iter)->show();
			}
		    //ע������Ҫ��list�е�ָ��ָ����ڴ�ɾ��������Ȼ������ڴ�й¶
			virtual ~Document(){
				list<Page*>::iterator iter;
				for(iter=lists.begin();iter!=lists.end();iter++)
				{
					if(*iter)
							delete *iter;
				}
			}
	private:
			list<Page*> lists;
};

class Report:public Document
{
	public:
			void factoryMethod()
			{
				getLists().push_back(new SkillPage());
				getLists().push_back(new EducationPage());
			}
};

class Resume:public Document
{
	public:
			void factoryMethod()
			{
				getLists().push_back(new SkillPage());
				getLists().push_back(new EducationPage());
				getLists().push_back(new ExperiencePage());
			}
};

int main()
{
	std::cout<<"����Ĺ�������ģʽ����"<<std::endl;
	Document * report=new Report();
	Document * resume=new Resume();
	report->factoryMethod();
	resume->factoryMethod();
	std::cout<<"report print"<<std::endl;
	report->print();
	std::cout<<"resume print"<<std::endl;
	resume->print();
	return 0;

}
