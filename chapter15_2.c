#include <stdlib.h>
#include <stdio.h>
#include <iostream>

//ʳ�ݶ���
class Herbivore
{
		public:
				virtual void drink()=0;
};

//�����һ�֣����ڷ���
class Wildebeest:public Herbivore
{
		public:
				void drink()
				{
					std::cout<<"wildbeest drink"<<std::endl;
				}
};

//����Ұţ
class Bison:public Herbivore
{
		public:
				void drink()
				{
					std::cout<<"bison drink"<<std::endl;
				}
};

//ʳ�⶯��
class Carnivore
{
	public:
			virtual void eat()=0;
};

//����ʨ��
class Lion:public Carnivore
{
	public:
			void eat()
			{
				std::cout<<"lion eat"<<std::endl;
			}
};

//��
class Wolf:public Carnivore
{
		public:
			void eat()
			{
				std::cout<<"wolf eat"<<std::endl;
			}
};

//��½����
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
	std::cout<<"���󹤳�ģʽ���������"<<std::endl;
	ContinentFactory * cf=new AmericaFactory;
	AnimalWorld *an=new AnimalWorld(cf);
	an->action();
	delete cf;
	delete an;
	return 0;
}

