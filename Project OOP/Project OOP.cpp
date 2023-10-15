// Project OOP.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
class  Team
{ 
	int totalTeams;
	int totalruns=0;
	int teamId;
	int nowickets=0;
	bool winning_Status;
	int totalovers = 2;
	
	const int distV = 50;
	const int distH = 12;
	const int distW = 3;
	int distspin;
	int distv;
	int disth;
	int distw;
public:
	void teamselct()
	{
		cout << "  Select the Team from the following :\n";
		cout << " 1.	Pakistan \n 2.	Australia \n 3.	New Zeland \n";
		cout << " 4.	Zimbabwe \n 5.	England \n";
		int tchoice;
		cin >> tchoice;
		switch (tchoice)
	  {
		case 1: 
			cout << " Your Team is 1 PAKISTAN ";
			break;
		case 2 :
			cout << " Your Team is 2 Australia ";
			break;
		case 3:
			cout << " Your Team is 3 New Zeland ";
			break;
		case 4:
			cout << " Your Team is 4 Zimbabwe ";
			break;
		case 5:
			cout << " Your Team is 5 England ";
			
	  }
	}
	bool toss()
	{
		int ts;
		cout << " \n HEAD OR TAILS \n";
		cout << "1.  Heads"<<endl<<"2. Tails"<<endl;
		cout << " Enter your Chocie : ";
		cin >>ts;
		srand(time(0));
		int r = (rand() % (2 - 1+ 1)) + 1;
		if (ts==r)
		{
			cout << "Conmgratulation you have won the Toss , \n Would you like to Bat or Bowl ??\n";
			cout << " 1. Bat\n 2. Bowl \n";
			cin >> ts;
			switch (ts)
			{
			case 1:
				cout << " You choice 1...BAT \n";
				// call the batting function here 
				break;
			case 2: 
				cout << " You choice 2...Bowl\n";
				break;
				// call the bowling function here 
			}
			return true;
		}
		else
		cout << " Sorry you lost the toss . The opponent has chosen to bat \n";
		// call the bowling function here 
		return false;
	}

	bool isStrike()
	{
		srand(time(NULL));
		int strike = (rand() % (1 - 0 + 1)) + 0;
		if (strike == 1)
		{
			return true;
		}
		else
			return false;
	}


	void bowling()
	{
		for ( int bowls = 0; bowls < (totalovers *6); bowls++)
		{
		  if (nowickets<=10)
		  {
			  cout << " Entered the Jump for bowl # " << bowls + 1 << "\n";
			  cin >> distv;
			  cout << " Enter the wide range of the  bowl # " << bowls + 1 << "\n";
			  cin >> distw;
			  cout << " Enter the point to pitch the bowl # "<< bowls+1 <<"\n";
			  cin >> disth;
			  cout << " Entered the Spin angle here: \n";
			  cin >> distspin;
			  if (distv > distV)
			  {
				  cout << " This is a No Ball \n";
				  bowls--;
				  if (isStrike())
				  {
					  srand(time(0));
					  int ran = (rand() % (6 - 4 + 1)) + 4;
					  totalruns = totalruns + ran;
					  cout << " runs added  " << "Total Runs become " << totalruns << endl;
				  }
				  else
				  {
					  totalruns = totalruns + 1;
					  cout << " runs added  " << "Total Runs become " << totalruns << endl;
				  }
			  }
			  else
				  if (distw >= distW)
				  {
					  cout << " The  is a wide Ball  \n";
					  bowls--;
					  if (isStrike())
					  {
						  totalruns = totalruns + 4;
						  cout << " runs added  " << "Total Runs become " << totalruns << endl;
					  }
					  else
					  {
						  totalruns = totalruns + 1;
						  cout << " runs added  " << "Total Runs become " << totalruns << endl;
					  }
				  }
				  else if (disth > distH)
				  {
					  cout << " This is a Bouncer  \n";
					  if (isStrike())
					  {
						  totalruns = totalruns + 6;
						  cout << " runs added  " << "Total Runs become " << totalruns << endl;
					  }
					  else
					  {
						  totalruns = totalruns + 0;
						  cout << " No run\n";
						  cout << " runs added  " << "Total Runs become " << totalruns << endl;
					  }

				  }
				  else if (distspin > 5 || distspin > -5)
				  {
					  cout << " This is a Spin Bowl \n";
					  if (isStrike())
					  {
						  srand(time(NULL));
						  int spn = (rand() % (6 - 0 + 1)) + 0;
						  totalruns = totalruns + spn;

						  cout << " runs added  " << "Total Runs become " << totalruns << endl;
					  }
					  else
					  {
						  totalruns = totalruns + 0;
						  cout << " No run\n";
						  cout << " runs added  " << "Total Runs become " << totalruns << endl;
					  }

				  }
				  else
					  cout << " Dead Bowl ";
			 
		  }
		}

	}

	

};
class Player
{ 
	int playerID;
	int score;
public:
	

};

int main()
{
	int choice;
	cout << "		** Welcome ** \n";
	cout << " Select an option (1-3): \n";
	cout << " 1. Play \n 2. Rules\n 3. Exit\n";
	cin >> choice;
	switch (choice)
	{
	case 1:
		cout << " Game Start \n";
		break;
	case 2:
		cout << " The rules of the game is here \n";
		
		break;
	case 3:
		cout << " You quit the Game \n";
		exit;

	}
	if (choice==1)
	{
		Team t1;
		t1.teamselct();
		t1.toss();
		t1.bowling();
	}
	
	
	
}
 
