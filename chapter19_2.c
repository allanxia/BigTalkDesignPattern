#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class DarawingElement
{
		public:
				DarawingElement(string n=string("")):name(n)
				{	
				
				}
				virtual void add(DarawingElement * c)
				{
				}
				virtual void removeDarawingElement(DarawingElement * c)
				{

				}
				virtual DarawingElement* getChild(int index)
				{

				}
				virtual void display(int depth)=0;

		protected:
				string name;
};

class PrimitiveElement:public DarawingElement
{
	public:
			PrimitiveElement(string str=""):DarawingElement(str)
			{

			}
			void display(int depth)
			{
				string str(depth+2,'-');
				std::cout<<str<<name<<std::endl;
			}
};

class CompositeElement:public DarawingElement
{
		public:
			CompositeElement(string str=""):DarawingElement(str)
			{

			}
			void add(DarawingElement* c)
			{
				children.push_back(c);
			}
			void removeElement(DarawingElement *c)
			{
				children.erase( remove(children.begin(),children.end(),c),children.end());
			}
			void display(int depth)
			{
				string str(depth+2,'-');
				std::cout<<str<<"+"<<name<<std::endl;
				vector<DarawingElement*>::iterator iter=children.begin();
				for(;iter!=children.end();iter++)
						(*iter)->display(depth+1);
			}

		private:
			vector<DarawingElement *> children;

};


int main()
{
	std::cout<<"具体的组合模式，画图程序例子"<<std::endl;
	DarawingElement *pic=new CompositeElement("picture");
	DarawingElement * redLine=new PrimitiveElement("red line");
	DarawingElement * blueCircle=new PrimitiveElement("blueCircle");
	DarawingElement * greenBox=new PrimitiveElement("green box");

	pic->add(redLine);
	pic->add(blueCircle);
	pic->add(greenBox);

	DarawingElement * twoCircles=new CompositeElement("two circles");
	DarawingElement * blackCircle=new PrimitiveElement("black circle");
	DarawingElement * whiteCircle=new PrimitiveElement("white Circle");

	twoCircles->add(blackCircle);
	twoCircles->add(whiteCircle);
	pic->add(twoCircles);
	pic->display(1);


	return 0;
}
