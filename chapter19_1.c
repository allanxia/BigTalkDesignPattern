#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Component
{
		public:
				Component(string n=string("")):name(n)
				{	
				
				}
				virtual void add(Component * c)
				{
				}
				virtual void removeComponent(Component * c)
				{

				}
				virtual Component* getChild(int index)
				{

				}
				virtual void display(int depth)=0;

		protected:
				string name;
};

class Leaf:public Component
{
	public:
			Leaf(string str=""):Component(str)
			{

			}
			void display(int depth)
			{
				string str(depth+2,'-');
				std::cout<<str<<name<<std::endl;
			}
};

class Composite:public Component
{
		public:
			Composite(string str=""):Component(str)
			{

			}
			void add(Component* c)
			{
				children.push_back(c);
			}
			void removeComponent(Component *c)
			{
				children.erase( remove(children.begin(),children.end(),c),children.end());
			}
			void display(int depth)
			{
				string str(depth+2,'-');
				std::cout<<str<<name<<std::endl;
				vector<Component*>::iterator iter=children.begin();
				for(;iter!=children.end();iter++)
						(*iter)->display(depth+1);
			}

			Component* getChild(int index)
			{
				return children[index];
			}

		private:
			vector<Component *> children;

};


int main()
{
	std::cout<<"组合模式例子"<<std::endl;
	Component *root=new Composite("root");
	Component * etc=new Composite("etc");
	Component * mnt=new Composite("mnt");

	root->add(etc);
	root->add(mnt);

	Component * txt1=new Leaf("txt1");
	Component *txt2=new Leaf("txt2");
	etc->add(txt1);
	etc->add(txt2);

	root->display(0);

	std::cout<<std::endl<<std::endl<<"after erase"<<std::endl;
	etc->removeComponent(txt1);
	root->display(0);

	return 0;
}
