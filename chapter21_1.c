#include <iostream>

class Singleton
{
	public:
			//����Ҫ�������������ɾ�̬��
			static Singleton * getInstance();
	private:
			Singleton()
			{

			}
	private:
			//��̬��Ա����ֻ�ܲ�����̬��Ա����������instanceҲӦ���Ǿ�̬��
			static Singleton * instance;

};

//��̬��Ա�����ĳ�ʼ��
Singleton * Singleton::instance=NULL;

Singleton * Singleton::getInstance()
{
				if(instance==NULL)
						instance=new Singleton();
				return instance;	
}

int main()
{
	Singleton *s1=Singleton::getInstance();
	Singleton *s2=Singleton::getInstance();
	if(s1==s2)
			std::cout<<"s1 and s2 are the same object"<<std::endl;

	return 0;
}
