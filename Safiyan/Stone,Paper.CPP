#include <cstdlib>
#include<conio.h>
#include <iostream>
#include <string>
#include <ctime>
using namespace std;
string Winner(string User1, string Computer1) 
{
	if (User1 == Computer1) 
	{
		return "Tie";
	} else if ((User1 == "Rock" || User1 == "rock") && (Computer1 == "Scissors" || Computer1 == "scissors") || 
	          (User1 == "Scissors" || User1 == "scissors") && (Computer1 == "Paper" || Computer1 == "paper") || 
			  (User1 == "Paper" || User1 == "paper") && (Computer1 == "Rock" || Computer1 == "rock")) 
	{
		return "Player 1";
	} 
	else 
	{
		return "Player 2";
	}
}
int main() 
{
	srand(time(NULL)); 
	static int Score1 = 0;
	static int Score2 = 0;
	while (true) 
	{
		cout<<"\t\t\t-----------------------------------\n"<<endl;
		cout << "\t\t\tEnter your choice : "<<endl;
		cout << "\t\t\t1) Rock : "<<endl;
		cout << "\t\t\t2) Paper : "<<endl;
		cout << "\t\t\t3) Scissors : "<<endl;
		cout << "\t\t\t4) Exit: "<<endl;
		cout<<"\t\t\t------------------------------------\n\t\t"<<endl;
		string User;
		cin >>User;
		if(User == "Exit" || User == "4")
		{
			break;	
		}
 else if(User != "Rock" && User != "rock" && User != "Paper" && User != "paper" &&
          User != "Scissors" && User != "scissors") 
{
    cout << "Please Enter a Valid Choice : " << endl;
    continue;
}
}
		string Computer;
		int random = rand() % 6;
//		if (random == 0){		
		switch(random)
		{
		case '0':
		Computer = "Rock";
		case '1':
		Computer = "Paper";
		case '2':
		Computer = "Scissors";
		case '3':
		Computer = "rock";
		case '4':
		Computer = "scissors";
		case '5':
		Computer = "paper"; 	
		}
//			player2 = "Rock";
//		} else if (random == 1) {
//			player2 = "Paper";
//		} else if(random==2){
//			player2 = "Scissors"  ;
//		}
//		else if (random == 3) {
//			player2 = "paper";
//		} else if(random==4){
//			player2 = "scissors"  ;
//			player2 = "rock";
//		}
		cout << "\t\tPlayer 2 chose: " << Computer << endl;
string winner=Winner(User,Computer);
		cout << "\t\tWinner: " << winner << endl;

		if (winner == "User") {
			Score1++;
		} else if (winner == "Computer") {
			Score2++;
		}
		cout << "\t\tScore : "<<endl ;
		cout<<"\t\tUser's Score : "<< Score1 <<endl; 
		cout<<"\t\tComputer's Score : " <<Score2 << endl;
	}
	getch();
	return 0;
}
