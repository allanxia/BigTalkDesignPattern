#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;
/**
 *һ����ʵ�����ӣ�ģ��һ��ͼ����еĵ���Դ���飬��Ƶ�������Ǹ��Ե����ԣ��ɽ��ģ���д�룩
 *ComponentΪLibraryItem
 *ConcreteComponentΪBook,Video
 *DecoratorΪDecorator
 *ConcreteDecoratorΪBorrowable,Written
 */

class LibraryItem
{
	public:
				virtual void show()=0;
};

class Book:public LibraryItem
{
	public:
			Book()
			{

			}
			Book(string str):name(str)
			{

			}
			void show()
			{
				std::cout<<"book:"<<name<<std::endl;
			}
	private:
			string name;
};


class Video:public LibraryItem
{
	public:
			Video()
			{

			}
			Video(string str):name(str)
			{

			}
			void show()
			{
				std::cout<<"Video:"<<name<<std::endl;
			}
	private:
			string name;
};

class Decorator:public LibraryItem
{
	public:
			Decorator()
			{

			}
			Decorator(LibraryItem * item)
			{
				libraryItem=item;
			}
			void show()
			{
				if(libraryItem!=NULL)
						libraryItem->show();
			}

	private:
			LibraryItem * libraryItem;

};

class Written:public Decorator
{
	public:
			Written()
			{

			}
			Written(LibraryItem* item):Decorator(item)
			{
			}
			void show()
			{
				Decorator::show();
				std::cout<<"written"<<std::endl;	
			}
};

class Borrowable:public Decorator
{
	public:
			Borrowable()
			{

			}
			Borrowable(LibraryItem* item):Decorator(item)
			{
			}
			void show()
			{
				Decorator::show();
				std::cout<<"borrowable"<<std::endl;	
			}
};

int main()
{
	std::cout<<"�����װ��ģʽ���ӣ�"<<std::endl;
	std::cout<<"-----------------------"<<std::endl;
	Book *book=new Book("BigTalkDesignPattern");
	Borrowable* borrowableBook=new Borrowable(book);
	Written* writtenBook=new Written(borrowableBook);
	writtenBook->show();

	std::cout<<"-------------------------"<<std::endl;
	Video* video=new Video("Walking Death");
	Borrowable* borrowableVideo=new Borrowable(video);
	borrowableVideo->show();

	delete book;
	delete borrowableBook;
	delete writtenBook;
	delete video;
	delete borrowableVideo;



	return 0;
}
