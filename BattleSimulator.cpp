#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include "conio_yp.h"

using namespace std;

enum GameState
{
	MAIN_MENU = 0,
	CHARACTER_SELECTION,
	BATTLE,
	RESULT
};

GameState gamestate = MAIN_MENU;

int choice = -1;

enum CharacterAction
{
	ATTACK = 0,
	BLOCK,
	DODGE,
	STUN,
	CRITICAL,
	HEAL,
	TOTAL_CHAR_ACTION
};

enum HeroType
{
	WARRIOR = 0,
	RANGER,
	MAGE,
	TOTAL_HERO_TYPE
};

enum HeroAction
{
	
};

enum EnemyType
{
	WOLF = 0,
	TROLL,
	SERPENTMONSTER,
	ICEGIANT,
	TOTAL_ENEMY_TYPE
};

class Character
{
	public: 
	string name;
	int health = 0;
	int attack = 0;
	int defense = 0;
	int block = 0;
	int heal = 0;
	int critical = 0;
	bool dodge = false;
	bool stun = false;
	vector<CharacterAction> actionList;
	
	virtual void InitializeStats() = 0;
	
	virtual void CharArt() = 0;
	
	string GetCharActionName(CharacterAction charAction)
	{
		if(charAction == ATTACK)
		{
			return "Attack";
		}
		else if(charAction == BLOCK)
		{
			return "Block";
		}
		else if(charAction == DODGE)
		{
			return "Dodge";
		}
		else if(charAction == STUN)
		{
			return "Stun";
		}
		else if(charAction == CRITICAL)
		{
			return "Critical";
		}
		else if(charAction == HEAL)
		{
			return "Heal";
		}
	}
};

class Hero : public Character
{
	public: 
	HeroType type;
	
	Hero(string name)
	{
		this->name = name;
	}
	
	virtual void InitializeStats() = 0;
	
	virtual void CharArt() = 0;
	
	string GetHeroTypeName()
	{
		if(type == WARRIOR)
		{
			return "Warrior";
		}
		else if(type == RANGER)
		{
			return "Ranger";
		}
		else if(type == MAGE)
		{
			return "Mage";
		}
	}
	
	void DisplayStats(int x, int y)
	{
		CharArt();
		gotoxy(x,y);
		cout << "Name : " << name;
		gotoxy(x,y+1);
		cout << "Class : " << GetHeroTypeName();
		gotoxy(x,y+2);
		cout << "Health : " << health;
		gotoxy(x,y+3);
		cout << "Attack : " << attack;
		gotoxy(x,y+4);
		cout << "Defense : " << defense;
	}
};

class Warrior : public Hero
{
	public:
		Warrior(string name) : Hero(name)
		{
			type = WARRIOR;
			InitializeStats();
		}
		
		void CharArt()
		{
			cout <<	"  |:|      __ \n";
			cout <<	",_|:|_,   /  ) \n";
			cout <<	"  (Oo    / _I_ \n";
			cout <<	"   +\\ \\  || __| \n";
			cout <<	"      \\ \\||___| \n";
			cout <<	"        \\ /.:.\\-\\ \n";
			cout <<	"         |.:. /-----\\ \n";
			cout <<	"         |___|::oOo::| \n";
			cout <<	"         /   |:<_T_>:| \n";
			cout <<	"        |_____\\ ::: / \n";
			cout <<	"         | |  \\ \\:/ \n";
			cout <<	"         | |   | | \n";
			cout <<	"         \\ /   | \\___ \n";
		}
		
		void InitializeStats()
		{
				health = rand() % 20 + 80;
				attack = rand() % 20 + 30;
				defense = rand() % 20 + 10;
				
				actionList.push_back(ATTACK);
				actionList.push_back(BLOCK); 
				actionList.push_back(DODGE); 
				actionList.push_back(STUN);  
		}
};

class Ranger : public Hero
{
	public:
		Ranger(string name) : Hero(name)
		{
			type = RANGER;
			InitializeStats();
		}
		
		void CharArt()
		{
		
			cout << "              A \n";
            cout << "   ,==.      /\\\ \n";
   			cout << "  . ,-.    /( `|\\    /  \\\ \n";
 			cout << "     `-. `. /,+./,,)/___ )) \n";
   			cout << "      `-.:.( \\)----,A=====|E)-> \n";
    		cout << "         / \\ \\  ,'_3     || \n";
    		cout << "        / ,'\\/.','  \\    )) \n";
   			cout << "      ,' /   `.'     \\  // \n";
   			cout << "    ,-/  (             \\// \n";
   			cout << "     /    \\             V \n";
   			cout << "    '/^;^:^\\ \n";
  			cout << "._.._/ /   \\ \\  n;   \n";                  
		}
		
		void InitializeStats()
		{
			health = rand() % 20 + 70;
			attack = rand() % 20 + 30;
			defense = rand() % 20 + 40;
			
			actionList.push_back(ATTACK);
			actionList.push_back(BLOCK); 
			actionList.push_back(DODGE); 
			actionList.push_back(CRITICAL);  
		}
};

class Mage : public Hero
{
	public:
		Mage(string name) : Hero(name)
		{
			type = MAGE;
			InitializeStats();
		}
		
		void CharArt()
		{
            cout <<         "`\\\_  |     _//' \n";
            cout <<         " \\(  |\\    )/ \n";
            cout <<         "  //\\ |_\\  /\\\ \n";
            cout <<         " (/ /\\(**)/\\ \\) \n";
            cout <<         "  \\/\\ (  ) /\\/ \n";
            cout <<         "     |(  )| \n";
            cout <<         "     | \\( \\ \n";
            cout <<         "     |  )  \\ \n";
            cout <<         "     |      \\ \n";
            cout <<         "     |       \\ \n";
            cout <<         "     |        `.__, \n";
            cout <<         "     \\_________.-'Ojo/gnv \n"; 
		}
		
		void InitializeStats()
		{
		
				health = rand() % 20 + 60;
				attack = rand() % 20 + 10;
				defense = rand() % 20 + 60;
				
				actionList.push_back(ATTACK);
				actionList.push_back(BLOCK); 
				actionList.push_back(DODGE); 
				actionList.push_back(HEAL);  
		}
};

class Enemy : public Character
{
	public:
		EnemyType type;
	
	Enemy(string name)
	{
		this->name = name;
	}
	
	virtual void InitializeStats() = 0;
	
	virtual void CharArt() = 0;
	
	string GetEnemyTypeName()
	{
		if(type == WOLF)
		{
			return "Wolf";
		}
		else if(type == TROLL)
		{
			return "Troll";
		}
		else if(type == SERPENTMONSTER)
		{
			return "Serpent Monster";
		}
		else if(type == ICEGIANT)
		{
			return "Ice Giant";
		}
	}
	
	void DisplayStats(int x, int y)
	{
		CharArt();
		gotoxy(x,y);
		cout << "Name : " << name;
		gotoxy(x,y+1);
		cout << "Class : " << GetEnemyTypeName();
		gotoxy(x,y+2);
		cout << "Health : " << health;
		gotoxy(x,y+3);
		cout << "Attack : " << attack;
		gotoxy(x,y+4);
		cout << "Defense : " << defense;
	}
		
};

class Wolf : public Enemy
{
	public:
		Wolf(string name) : Enemy(name)
		{
			type = WOLF;
			InitializeStats();
		}
		
		void CharArt()
		{
			int x = 30;
			int y = 2;
			gotoxy(x,y);
			cout << ", ";
			gotoxy(x,y+1);
		    cout << "      ,,/( ,,,,,,,,,,___,, ";
		    gotoxy(x,y+2);
		    cout << "     )b     ,,,           '`,_, ";
		    gotoxy(x,y+3);
		    cout << "    /(     /                   `, ";
		    gotoxy(x,y+4);
		    cout << "   L/7_/\\,,|            /        \\ ";
		    gotoxy(x,y+5);
		    cout << "    ,`      `,  \\     ,|          \\ ";
		    gotoxy(x,y+6);
		    cout << "     ,      /  /``````||      |\\,  \\__,))) ";
		    gotoxy(x,y+7);
		    cout << "           /  / |      \\\     \\  \\,,,,,,/ ";
		    gotoxy(x,y+8);
		    cout << "          |  /  |       \\\   )/ ";
		    gotoxy(x,y+9);
		    cout << "         \\ (|  )     ,,//   / ";
		    gotoxy(x,y+10);
		    cout << "          `_)_/     ((___/'; ";
		}
		
		void InitializeStats()
		{
		
				health = rand() % 20 + 40;
				attack = rand() % 20 + 10;
				defense = rand() % 20 + 30;
				
				actionList.push_back(ATTACK);
				actionList.push_back(DODGE); 
				actionList.push_back(CRITICAL); 
				actionList.push_back(HEAL);  
		}
};

class Troll : public Enemy
{
	public:
		Troll(string name) : Enemy(name)
		{
			type = TROLL;
			InitializeStats();
		}
		
		void CharArt()
		{
			int x = 30;
			int y = 2;
			gotoxy(x,y);
            cout << "     ,      , ";
            gotoxy(x,y+1);
            cout << "     /(.-""-.)\\ ";
            gotoxy(x,y+2);
        	cout << "|\\  \\/      \\/  /| ";
        	gotoxy(x,y+3);
        	cout << "| \\ / =.  .= \\ / | ";
        	gotoxy(x,y+4);
        	cout << "\\( \\   o\\/o   / )/ ";
        	gotoxy(x,y+5);
        	cout << " \\_, '-/  \\-' ,_/ ";
        	gotoxy(x,y+6);
        	cout << "   /   \\__/   \\ ";
        	gotoxy(x,y+7);
        	cout << "   \\ \\__/\\__/ / ";
        	gotoxy(x,y+8);
        	cout << " ___\\ \\|--|/ /___ ";
        	gotoxy(x,y+9);
       		cout << "/`    \\      /    `\\ ";
       		gotoxy(x,y+10);
  			cout << "jgs /       '----'  \\; "; 
		}
		
		void InitializeStats()
		{
		
				health = rand() % 20 + 60;
				attack = rand() % 20 + 40;
				defense = rand() % 20 + 20;
				
				actionList.push_back(ATTACK);
				actionList.push_back(STUN); 
				actionList.push_back(CRITICAL);  
		}
};

class SerpentMonster : public Enemy
{
	public:
		SerpentMonster(string name) : Enemy(name)
		{
			type = SERPENTMONSTER;
			InitializeStats();
		}
		
		void CharArt()
		{
			int x = 30;
			int y = 2;
			gotoxy(x,y);
            cout << "       ___ ";
            gotoxy(x,y+1);
            cout << "     ,'---`. ";
            gotoxy(x,y+2);
            cout << "    /\\l^.^j/\\ ";
            gotoxy(x,y+3);
            cout << "       \\-/   Y ";
            gotoxy(x,y+4);
           	cout << "   /   j|l   \\ ";
           	gotoxy(x,y+5);
          	cout << "   \\, -. ,- ._/  ";
			gotoxy(x,y+6);   
          	cout << "    l    Y    j   ";  
          	gotoxy(x,y+7);
          	cout << "     \-'-^-'-/   ";  
			gotoxy(x,y+8); 
          	cout << "      Y`-^-'f ";    
			gotoxy(x,y+9); 
          	cout << "      |`-^-'|      _____ ";
          	gotoxy(x,y+10);
          	cout << "    ,'` -^- '`.,-'',  < '`-. ";
          	gotoxy(x,y+11);
          	cout << "   f`--------'|> <  > , > ' `-.     ";
          	gotoxy(x,y+12);
          	cout << "   l`--------'l < ' ,--.  < >  `--- ";
		}
		
		void InitializeStats()
		{
		
				health = rand() % 20 + 40;
				attack = rand() % 20 + 30;
				defense = rand() % 20 + 60;
				
				actionList.push_back(ATTACK);
				actionList.push_back(DODGE); 
				actionList.push_back(CRITICAL); 
				actionList.push_back(STUN);  
		}
};

class IceGiant : public Enemy
{
	public:
		IceGiant(string name) : Enemy(name)
		{
			type = ICEGIANT;
			InitializeStats();
		}
		
		void CharArt()
		{
			int x = 30;
			int y = 2;
			gotoxy(x,y);
            cout << "         _:-'      `'-: ";
            gotoxy(x,y+1);
            cout << "    _   /   _______    `\\ ";
            gotoxy(x,y+2);
            cout << " .-' \\  \\.-'       `'--./ ";
            gotoxy(x,y+3);
           	cout << ".'\\  \\ /  () ___ ()    \\ ";
           	gotoxy(x,y+4);
          	cout << "\ \\\\#  ||    (___)      | ";
          	gotoxy(x,y+5);
            cout << "\  #\\\_||   '.___.'     | ";
            gotoxy(x,y+6);
            cout << "\___|\\  \\_________.--./ ";
            gotoxy(x,y+7);
            cout << "     \\\ |         \\   \\--. ";
            gotoxy(x,y+8);
            cout << "      \\\/_________/   /   `\\       , ";
            gotoxy(x,y+9);
            cout << "      .\\\        /`--;`-.   `-.__.'/ ";
            gotoxy(x,y+10);
            cout << "     / _\\\   ,_.'   _/ \\ \\        / ";
            gotoxy(x,y+11);
            cout << "    |    `\\   \   /`    | '.___.-' ";
            gotoxy(x,y+12);
            cout << "    \____/\\   '--\\____/  ";
		}
		
		void InitializeStats()
		{
		
				health = rand() % 20 + 80;
				attack = rand() % 20 + 40;
				defense = rand() % 20 + 40;
				
				actionList.push_back(ATTACK);
				actionList.push_back(STUN); 
				actionList.push_back(CRITICAL); 
				actionList.push_back(HEAL);  
		}
};

Hero* player;
Enemy* enemy;

void DisplayMainMenu()
{
	cout << "==========================" << endl;
	cout << "	WELCOME\n";
	cout << "	  TO\n";
	textcolor(MAGENTA);
	cout << "    BATTLE SIMULATOR\n";
	textcolor(WHITE);
	cout << "==========================" << endl;
	
	system("pause");
	choice = 0;
	gamestate = CHARACTER_SELECTION;
}

void DisplayCharacterSelection()
{
	string name;
	cout << "==========================" << endl;
	cout << "Enter your chactacter name : " << endl;
	getline(cin, name);
	
	cout << "Choose your character class\n";
	cout << "1. Warrior\n";
	cout << "2. Ranger\n";
	cout << "3. Mage\n";
	cout << "==========================" << endl;
	cout << "Your input : ";
	do
	{
		cin >> choice;
	}while(choice > (TOTAL_HERO_TYPE));
	
	if(cin.good())
	{
		if(choice==1)
		{
			player = new Warrior(name);
		}
		else if(choice == 2)
		{
			player = new Ranger(name);
		}
		else if(choice == 3)
		{
			player = new Mage(name);
		}
		
		choice = rand() % TOTAL_ENEMY_TYPE + 1;
		
		if(choice==1)
		{
			enemy = new Wolf("HIMME");
		}
		else if(choice == 2)
		{
			enemy = new Troll("HIMME");
		}
		else if(choice == 3)
		{
			enemy = new SerpentMonster("HIMME");
		}
		else if(choice == 4)
		{
			enemy = new IceGiant("HIMME");
		}
		
		gamestate = BATTLE;
	}
	else
	{
		cout << "WRONG INPUT!!!" << endl;
		system("pause");
	}
	
	cin.clear();
	cin.ignore(1000, '\n');
}

void BattleSimulation(Character* actor, Character* target)
{
	actor->dodge = false;
	actor->block = 0;
	
	if(actor->stun == false && target->dodge == false)
	{
		if(actor->actionList[choice - 1] == ATTACK)
		{
			int tempDamage = actor->attack * (1.0f - rand()%target->defense/100.0f) - target->block;
			if(tempDamage > 0)
			{
				target->health -= tempDamage;
				cout << actor->name << " ATTACKED " << target->name << " WITH " << tempDamage << " DAMAGE" << endl;
			}
			else
			{
				cout << actor->name << " FAILED TO ATTACK " << target->name << endl;
			}
		}
		else if(actor->actionList[choice - 1] == BLOCK)
		{
			int tempBlock = actor->defense * (1.0f - rand()%target->attack/100.0f);
			actor->block = tempBlock;
			cout << actor->name << " BLOCKED " << tempBlock << " OF " << target->name << "'S DAMAGE'"<< endl;
		}
		else if(actor->actionList[choice - 1] == DODGE)
		{
			if(rand()%100 >= 50)
			{
				actor->dodge = true;
				cout << actor->name << " SUCCESSFULLY DODGED " << target->name << endl;
			}
			else
			{
				cout << actor->name << " FAILED TO DODGE" << endl;
			}
		}
		else if(actor->actionList[choice - 1] == STUN)
		{
			if(rand()%100 >= 50)
			{
				target->stun = true;
				cout << actor->name << " SUCCESSFULLY STUNNED " << target->name << endl;
			}
		}
		else if(actor->actionList[choice - 1] == CRITICAL)
		{
			int critChance = rand() % 100;
			int tempDamage = 0;
			if(critChance >= 75)
			{
				tempDamage = actor->attack * (1.0f - enemy->defense/200.0f);
				target->health -= tempDamage;
				cout << actor->name << " SUCCESSFULLY LANDED A CRITICAL HIT OF " << tempDamage << " DAMAGE" << endl;
			}
			else
			{
				tempDamage = actor->attack * (1.0f - rand()%target->defense/100.0f) - target->block;
				target->health -= tempDamage;
				cout << actor->name << " FAILED TO LAND A CRITICAL HIT AND ONLY INFLICTED " << tempDamage << " DAMAGE"<< endl;
			}
		}
		else if(actor->actionList[choice - 1] == HEAL)
		{
				actor->heal = rand() % (actor->health);
				actor->health += actor->heal;
				
				if(actor->health > 100)
				{
					actor->health = 100;
				}
				
				cout << actor->name << " HEALED " << actor->heal << " HP" << endl;
		}
	}
	cout << endl;
	actor->stun = false;
}

void ShowBattleResult()
{
	string resultText = "";
	if(player->health <= 0 && enemy->health <= 0)
	{
		resultText = "Both are dead. It is a draw\n";
	}
	else if(player->health <= 0)
	{
		resultText = "You are dead. You lose!\n";
	}
	else if(player->health <= 0)
	{
		resultText = "Enemy is dead. You win!\n";
	}
	
	cout << "==========================" << endl;
	cout << resultText << endl;
		cout << "1. Continue your journey" << endl;
		cout << "2. Exit" << endl;
		cin >> choice;
		
		if(cin.good())
		{
			if(choice == 1)
			{
				gamestate = CHARACTER_SELECTION;
			}
			else if(choice == 2)
			{
				choice = -1;
			}
		}
		else
		{
			cout << "WRONG INPUT!!!" << endl;
			system("pause");
		}
		
		cin.clear();
		cin.ignore(1000, '\n');
		
		cout << endl;
		
		system("pause");
}

void DisplayBattle()
{
	player->DisplayStats(1,15); 
	enemy->DisplayStats(30,15); 
	
	cout << "\n\n==========================" << endl;
	cout << "PLEASE CHOOSE AN ACTION : " << endl;
	cout << "==========================" << endl;
	for(int i=0; i <player->actionList.size(); i++)
	{
		cout << i+1 <<". " << player->GetCharActionName(player->actionList[i]) << endl;
	}
	
	cout << "==========================" << endl;
	cout << "Your input : " << endl;
	cin >> choice;
	
	BattleSimulation(player,enemy);
	
	choice = 1; 
	
	BattleSimulation(enemy,player);
	
	system("pause");
	
	if(player->health <= 0 || enemy->health <= 0)
	{
		ShowBattleResult();
	}
}

int main()
{
	system("mode con: cols=80 lines=35");
	
	srand(time(NULL));
	
	do
	{
		if(gamestate == MAIN_MENU)
		{
			DisplayMainMenu();
		}
		else if(gamestate == CHARACTER_SELECTION)
		{
			DisplayCharacterSelection();
		}
		else if(gamestate == BATTLE)
		{
			DisplayBattle();
		}
		system("CLS");
	}while(choice != -1);
	
	return 0;
}
