#include <stdlib.h>
#include <stdio.h>
#include <iostream>


/**一个真实的代理模式的例子
 * Proxy为MathProxy，客户端可见的是这个代理类的对象
 * Subject为IMath,这个是代码类和真实的主题必须遵循的接口
 * RealSubject为Math，真正完成工作的类是这个类
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
	std::cout<<"真实的代理模式的例子"<<std::endl;
	MathProxy* proxy=new MathProxy();
	std::cout<<"lhs:1 rhs:2"<<std::endl;
	std::cout<<"proxy->add:"<<proxy->add(1,2)<<std::endl;
	std::cout<<"proxy->sub:"<<proxy->sub(1,2)<<std::endl;
	std::cout<<"proxy->div:"<<proxy->div(1,2)<<std::endl;
	std::cout<<"proxy->mul:"<<proxy->mul(1,2)<<std::endl;
	return 0;
}
