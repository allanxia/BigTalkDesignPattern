#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string>



int main(int argc,char ** argv)
{
	std::cout<<"switch��default����"<<std::endl;
	char str;
	//���������һ����������ô�������ĵ�һ���ַ���Ϊswitch��Ҫƥ����ַ�
	if(argc==2)
		str=argv[1][0];
	switch (str)
	{
		default:
				{
				std::cout<<"default"<<std::endl;
//				break;
				}
	
		case 'a':
				{
				std::cout<<"prefix a"<<std::endl;
				break;
				}
		case 'b':
				{
				std::cout<<"prefix b"<<std::endl;
				break;
				}
	

	}

	return 0;
}
