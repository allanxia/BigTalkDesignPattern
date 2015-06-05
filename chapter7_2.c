#include <stdlib.h>
#include <stdio.h>
#include <iostream>


/**һ����ʵ�Ĵ���ģʽ������
 * ProxyΪMathProxy���ͻ��˿ɼ��������������Ķ���
 * SubjectΪIMath,����Ǵ��������ʵ�����������ѭ�Ľӿ�
 * RealSubjectΪMath��������ɹ��������������
 */
class IMath
{
	public:
			virtual double add(double lhs,double rhs)=0;
			virtual double sub(double lhs,double rhs)=0;
			virtual double div(double lhs,double rhs)=0;
			virtual double mul(double lhs,double rhs)=0;

};

class Math:public IMath
{
	public:
			double add(double lhs,double rhs)
			{
				return lhs+rhs;
			}
		    double sub(double lhs,double rhs)
			{
				return lhs-rhs;
			}
			double div(double lhs,double rhs)
			{
				return lhs/rhs;
			}
			double mul(double lhs,double rhs)
			{
				return lhs*rhs;
			}

};


class MathProxy:public IMath
{
	public:
			MathProxy()
			{
				math=new Math();
			}
			~MathProxy()
			{
				if(math!=NULL)
				{
					delete math;
					math=NULL;
				}
			}
			double add(double lhs,double rhs)
			{
				return math->add(lhs,rhs);
			}
			double sub(double lhs,double rhs)
			{
				return math->sub(lhs,rhs);
			}
			double div(double lhs,double rhs)
			{
				return math->div(lhs,rhs);
			}
			double mul(double lhs,double rhs)
			{
				return math->mul(lhs,rhs);
			}

	private:
			Math * math;

};

int main()
{
	std::cout<<"��ʵ�Ĵ���ģʽ������"<<std::endl;
	MathProxy* proxy=new MathProxy();
	std::cout<<"lhs:1 rhs:2"<<std::endl;
	std::cout<<"proxy->add:"<<proxy->add(1,2)<<std::endl;
	std::cout<<"proxy->sub:"<<proxy->sub(1,2)<<std::endl;
	std::cout<<"proxy->div:"<<proxy->div(1,2)<<std::endl;
	std::cout<<"proxy->mul:"<<proxy->mul(1,2)<<std::endl;
	return 0;
}
