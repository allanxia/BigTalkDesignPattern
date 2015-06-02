#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;
/**
 *一个真实的例子：模拟一个图书馆中的的资源（书，视频），它们各自的特性（可借阅，可写入）
 *Component为LibraryItem
 *ConcreteComponent为Book,Video
 *Decorator为Decorator
 *ConcreteDecorator为Borrowable,Written
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
	std::cout<<"具体的装饰模式例子："<<std::endl;
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
