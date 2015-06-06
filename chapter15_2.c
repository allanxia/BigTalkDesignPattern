#include <stdlib.h>
#include <stdio.h>
#include <iostream>

//食草动物
class Herbivore
{
		public:
				virtual void drink()=0;
};

//羚羊的一种，产于非洲
class Wildebeest:public Herbivore
{
		public:
				void drink()
				{
					std::cout<<"wildbeest drink"<<std::endl;
				}
};

//美洲野牛
class Bison:public Herbivore
{
		public:
				void drink()
				{
					std::cout<<"bison drink"<<std::endl;
				}
};

//食肉动物
class Carnivore
{
	public:
			virtual void eat()=0;
};

//非洲狮子
class Lion:public Carnivore
{
	public:
			void eat()
			{
				std::cout<<"lion eat"<<std::endl;
			}
};

//狼
class Wolf:public Carnivore
{
		public:
			void eat()
			{
				std::cout<<"wolf eat"<<std::endl;
			}
};

//大陆工厂
class ContinentFactory
{
		public:
				virtual Herbivore * createHerbivore()=0;
				virtual Carnivore * createCarnivore()=0;

};

class AfricaFactory :public ContinentFactory
{
		public:
				virtual Herbivore * createHerbivore()
				{
					return new Wildebeest();
				}
				virtual Carnivore * createCarnivore()
				{
					return new Lion();
				}

};

class AmericaFactory :public ContinentFactory
{
		public:
				virtual Herbivore * createHerbivore()
				{
					return new Bison();
				}
				virtual Carnivore * createCarnivore()
				{
					return new Wolf();
				}

};

class AnimalWorld
{
		public:
				AnimalWorld()
				{

				}
				AnimalWorld(ContinentFactory *cf)
				{
						herbivore=cf->createHerbivore();
						carnivore=cf->createCarnivore();
						
				}
				void action()
				{
						herbivore->drink();
						carnivore->eat();
				}
				~AnimalWorld()
				{
						if(!herbivore)
								delete herbivore;
						if(!carnivore)
								delete carnivore;
				}
		private:
				Herbivore * herbivore;
				Carnivore * carnivore;
				
};

int main()
{
	std::cout<<"抽象工厂模式具体的例子"<<std::endl;
	ContinentFactory * cf=new AmericaFactory;
	AnimalWorld *an=new AnimalWorld(cf);
	an->action();
	delete cf;
	delete an;
	return 0;
}

