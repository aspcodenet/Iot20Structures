// Iot20Structures.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <ctime>
#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <string>
using namespace std;



class StringQueue
{
	vector<string> items;

public:
	string front()
	{
		if (items.empty())
			return "";
		return items[0];
	}

	void pop()
	{
		items.erase(items.begin());
	}

	void push(string s)
	{
		items.push_back(s);
	}

	void empty()
	{
		items.clear();
	}

};


void Lab5()
{
	StringQueue s;
	s.push("Stefan");
	s.push("Kalle");
	string s2 = s.front();
	s.push("Nisse");
	s.pop();
	cout << s.front();
}




class Patient
{
	time_t arrivedInQueue;
	int queueNo;
public:
	Patient(int queueNo)
	{
		this->queueNo = queueNo;
		arrivedInQueue = time(NULL);
	}
	int GetQueueNo()
	{
		return queueNo;
	}
	int SecondsInQueue()
	{
		return time(NULL) - arrivedInQueue;
	}

};


int Lab3()
{
	int queueNo = 1;
	string commando;
	queue<Patient> theQueue;
	while (1)
	{
		cout << "Antal i kön " << theQueue.size() << endl;
		cout << "1. Stoppa in en ny patient i väntekön" << endl;
		cout << "2. Ropa in nästa patient" << endl;
		getline(cin, commando);
		if (commando == "1")
		{
			Patient p(queueNo);
			theQueue.push(p);
			queueNo++;
		}
		if (commando == "2")
		{
			Patient p = theQueue.front();
			cout << "Ny patient ! Nr " << p.GetQueueNo() << endl;
			cout << "Patienten: Jag har väntat hela " << p.SecondsInQueue() << " sekunder...vad f-n får jag för skattepengarna" << endl;
			theQueue.pop();
		}
	}
	return 0;
}


void Lab1()
{
	stack<string> allCommands;
	while (true)
	{
		string command;
		cout << "Ange kommando - eller UNDO:";
		cin >> command;

		if (command == "UNDO")
		{
			allCommands.pop();
		}
		else
			allCommands.push(command);


		cout << "Nu finns " << allCommands.size() << endl;
		cout << "Om du UNDOar nu så tar du bort:" << allCommands.top() << std::endl;

	}


}


string Reverse(string s)
{
	stack<char> chars;
	for_each(s.begin(), s.end(), [&chars](char ch)
		{
			chars.push(ch);
		});

	string ret;
	while (chars.size() > 0)
	{
		ret += chars.top();
		chars.pop();
	}
	return ret;
}

void Lab15()
{
	string sa = "Hejsan hoppsan";
	cout << Reverse(sa) << endl;
}



class StringStack
{
	vector<string> items;

	public:
	string top()
	{
		if (items.empty())
			return "";
		return items[items.size()-1];
	}
	
	void pop()
	{
		items.pop_back();
	}
	
	void push(string s)
	{
		items.push_back(s);
	}
	
	void empty()
	{
		items.clear();
	}

};
void Lab175()
{
	StringStack s;
	s.push("Apa");
	s.push("Test");
	cout << s.top();
	s.pop();
	cout << s.top();
}

bool IsBalanced(string code)
{
	stack<char> brackets;
	
	for(char ch : code )
	{
		if (ch == '{' || ch == '[' || ch == '(')
			brackets.push(ch);

		else if(ch == ')')
		{
			auto c = brackets.top();
			brackets.pop();
			if (c != '(')
				return false;
		}
	
		else if (ch == '}')
		{
			auto c = brackets.top();
			brackets.pop();
			if (c != '{')
				return false;
		}
		else if (ch == ']')
		{
			auto c = brackets.top();
			brackets.pop();
			if (c != '[')
				return false;
		}

	};
	return brackets.empty();
}

void Lab2()
{
	cout << IsBalanced("{ hej ()   }");
	cout << IsBalanced("{ hej ()   }{");
	cout << IsBalanced("{ hej ([)   }");
}











void Bankomat()
{
	map<string, float> konton;
	while(true)
	{
		string sel, kontonummer;
		cout << "1. Nytt konto" << endl;
		cout << "2. Edit konto" << endl;
		cout << "3. Quit" << endl;
		cin >> sel;

		if (sel == "3") break;
		
		if(sel == "2")
		{
			cout << "Ange kontonummer";
			cin >> kontonummer;
			if (konton.find(kontonummer) == konton.end())
			{
				cout << "Ogiltigt konto" << endl;
				continue;
			}
			string kontoSel = "";
			while(kontoSel != "3")
			{
				cout << "Konto " << kontonummer << endl << "SALDO:" << konton[kontonummer] << endl;
				cout << "1. Deposit" << endl << "2. Withdrawal" << endl << "3. Back";
				cin >> kontoSel;
				if(kontoSel == "1" || kontoSel == "2")
				{
					float belopp;
					cout << "Ange belopp:";
					cin >> belopp;
					if (kontoSel == "1")
						konton[kontonummer] = konton[kontonummer] + belopp;
					else
					{
						if (belopp < konton[kontonummer])
							konton[kontonummer] = konton[kontonummer] - belopp;
						else
							cout << "Too much withdrawal" << endl;
					}
						
				}
				
			}
			
		}

		if(sel == "1")
		{
			cout << "Ange kontonummer";
			cin >> kontonummer;
			if(konton.find(kontonummer) != konton.end())
			{
				cout << "Konto finns redan" << endl;
				continue;
			}
			konton[kontonummer] = 0;
		}
	}
}



class Player
{
	string _name;
	int _jerseyNumber;
public:
	Player(string name, int jerseyNumber)
	{
		_name = name;
		_jerseyNumber = jerseyNumber;
	}

	int Jersey()
	{
		return _jerseyNumber;
	}
	

};

template <typename T>
void move_range(size_t start, size_t length, size_t dst, std::vector<T>& v)
{
	typename std::vector<T>::iterator first, middle, last;
	if (start < dst)
	{
		first = v.begin() + start;
		middle = first + length;
		last = v.begin() + dst;
	}
	else
	{
		first = v.begin() + dst;
		middle = v.begin() + start;
		last = middle + length;
	}
	std::rotate(first, middle, last);
}


class LRUCache
{
	vector<Player> cachedItems;
public:
	Player* GetFromCache(int jerseyNumber)
	{
		//int index = -1;
		//for(int i  = 0; i < cachedItems.size(); i++)
		//{
		//	if(cachedItems[i].Jersey() == jerseyNumber)
		//	{
		//		index = 1;
		//	}
		//}
		//
		auto iter = find_if( cachedItems.begin(), cachedItems.end(), [jerseyNumber](Player p)
		{
				return p.Jersey() == jerseyNumber;
		});
		if (iter == cachedItems.end()) return nullptr;
		////Move to front
		int index = iter - cachedItems.begin();
		move_range(index, 1, 0, cachedItems);

		
		return &cachedItems[0];
	}

	void AddToCache(Player p)
	{
		cachedItems.insert(cachedItems.begin(), p);
		while (cachedItems.size() > 3)
			cachedItems.pop_back();
	}

};

void LRU()
{
	LRUCache c;
	Player *p = c.GetFromCache(13);
	if (p == nullptr)
		c.AddToCache(Player("Sudden", 13));
	p = c.GetFromCache(13);
	if (p == nullptr)
		c.AddToCache(Player("Sudden", 13));
	p = c.GetFromCache(21);
	if (p == nullptr)
		c.AddToCache(Player("Foppa", 21));

	p = c.GetFromCache(5);
	if (p == nullptr)
		c.AddToCache(Player("Lidas", 5));

	p = c.GetFromCache(21);
	if (p == nullptr)
		c.AddToCache(Player("Foppa", 21));

	p = c.GetFromCache(2);
	if (p == nullptr)
		c.AddToCache(Player("Eldebrink", 2));
	

	
}



int main()
{
	LRU();
	Bankomat();
	Lab5();
	Lab3();
	Lab2();
	Lab175();
	Lab15();
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
