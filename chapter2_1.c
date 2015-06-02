#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string>



int main(int argc,char ** argv)
{
	std::cout<<"switch中default测试"<<std::endl;
	char str;
	//如果输入了一个参数，那么将参数的第一个字符作为switch需要匹配的字符
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
