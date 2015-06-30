#include <iostream>
#include <map>
#include <string>


using namespace std;

class Participant;

class AbstractChatRoom
{
		public:
				virtual void registe(Participant * p)=0;
				virtual void send(string from,string to ,string message)=0;
};

class ChatRoom:public AbstractChatRoom
{
		public:
				void registe(Participant * p);

			    void send(string from,string to ,string message);
		private:
				map<Participant *,string> participants;

};


class Participant
{
		public:
				Participant(string n=""):name(n)
				{

				}

				string getName()
				{
					return name;
				}
				void setChatRoom(ChatRoom *c)
				{
					chatRoom=c;
				}
				void send(string to,string message)
				{
					chatRoom->send(name,to,message);
				}

				virtual void receive(string from,string message)
				{
					cout<<from<<" to "<<name<<" : "<<message<<endl;
				}
		private:
				string name;
				ChatRoom * chatRoom;

};


void ChatRoom::registe(Participant * p)
				{
					if(!participants.count(p))
					{
						participants.insert(pair<Participant *,string>(p,p->getName()));
					}
					p->setChatRoom(this);
				}
				

			    void ChatRoom::send(string from,string to ,string message)
				{
					map<Participant *,string>::iterator iter;
					for(iter=participants.begin();iter!=participants.end();iter++)
					{
						if(iter->second==to)
								break;
					}
					if(iter!=participants.end())
					{
						iter->first->receive(from,message);
					}
				}




class Beatle:public Participant
{
		public:
				Beatle(string n=""):Participant(n)
				{
					
				}
				void receive(string from,string message)
				{
					cout<<"to a beatle : ";
					Participant::receive(from,message);
				}

};

class NonBeatle:public Participant
{
		public:
				NonBeatle(string n=""):Participant(n)
				{
					
				}
				void receive(string from,string message)
				{
					cout<<"to a non-beatle : ";
					Participant::receive(from,message);
				}

};


int main()
{
	cout<<"聊天室中介者模式代码"<<endl;
	ChatRoom * chatRoom=new ChatRoom();

	Participant *george=new Beatle("George");
	Participant *paul=new Beatle("Paul");
	Participant *ringo=new Beatle("Ringo");
	Participant *john=new Beatle("John");
	Participant *yoko=new NonBeatle("Yoko");

	chatRoom->registe(george);
	chatRoom->registe(paul);
	chatRoom->registe(ringo);
	chatRoom->registe(john);
	chatRoom->registe(yoko);


	yoko->send("John","hi John!");
	paul->send("Ringo","All you need is love");
	ringo->send("George","My sweet Lord");
	paul->send("John","can not buy me love");
	john->send("Yoko","My sweet love");

	return 0;
}
