#include <iostream>

using namespace std;

class Game
{
	public:
	virtual void play()=0;
};

class NeedForSpeed :public Game
{
	public:
	virtual void play()
	{
		cout<<"need for speed play"<<endl;
	}
};

class QQGame :public Game
{
	public:
	virtual void play()
	{
		cout<<"QQGame play"<<endl;
	}
};

class FruitNinjia:public Game
{
	public:
	virtual void play()
	{
		cout<<"Fruit Ninjia play"<<endl;
	}
};

class Phone
{
	public:
	virtual void run()=0;
	void setGame(Game *g)
	{	
		game=g;
	}	
	Game * getGame()
	{
		return game;
	}
	protected:
	Game *game;
};


class Samsung:public Phone
{
	public:
	virtual void run()
	{
		cout<<"Samsung :";
		game->play();
	}
};

class HuaWei:public Phone
{
	public:
	virtual void run()
	{
		cout<<"HuaWei :";
		game->play();
	}

};

int main()
{
	cout<<"桥接模式真实的例子，不同的手机品牌和手机游戏"<<endl;
	Phone *samsung=new Samsung();
	Phone *huawei=new HuaWei();
	Game * needForSpeed=new NeedForSpeed();
	Game * qqGame=new QQGame();
	Game * fruit=new FruitNinjia();
	samsung->setGame(qqGame);
	samsung->run();
	huawei->setGame(needForSpeed);
	huawei->run();
	samsung->setGame(fruit);
	samsung->run();
	delete samsung;
	delete huawei;
	delete needForSpeed;
	delete qqGame;
	delete fruit;
	return 0;

}
