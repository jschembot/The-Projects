/********************************************************
*  PROGRAMMER: Edward Moon
*  Date: 08/25/16
*  Purpose: This is a simple rock,paper,scissor program.
*  Notes:         
*
*********************************************************/

#include <iostream>
#include <iomanip>
#include <limits>
#include <ctime>
#include <cstdlib>

using namespace std;


int main()
{
	
	int choice;
	int again;
	int comp;
	char res;
	
	unsigned seed;
	
	cout << "Welcome to this simple game of Rock/Paper/Scissors. Obviously the rules are simple:\n\nRock beats scissors. \nScissors beats Paper.  \nPaper beats Rock.\n" <<endl;
	cout << "Do you have what it takes to defeat me(The Comp, The Destroyer)?!\n" << endl;
    //The choices
    cout << "Choose your destiny!\n\n";
    cout << "1. Rock\n";
    cout << "2. Paper\n";
    cout << "3. Scissor\n";
    cout << "4. Exit out of game.\n\n";
    cin >> choice;
    
    
    //The battle against the comp
    
    //The Rock
    if(choice == 1)	
	{
		cout << "Rock...Paper...Scissor...shoot!.\n";
		//cout << "Well I choose this.\n";
		
	}
	//The Paper
	else if( choice == 2)
	{
		cout << "Rock...Paper..Scissor...shoot!.\n";
		//cout << "Well I choose this.\n";
	}
	
	//The Scissor
	else if(choice == 3)
	{
		cout << "Rock...Paper...Scissor...shoot!.\n";
		//cout << "Well I choose this.\n";
	}
	
	//Quit
	else if(choice == 4)
	{
		cout << "Till next time";
		return 0;
	}
	
/*	
   This here is where the random generation happens	
	
*/

 seed = time(0);
        srand(seed); //For the random generator.
        
  comp = rand() % 3 + 1; //Computers pick.
  
  if (comp==1) //Computer rock
        {
        res = 1;
        cout << "Rock!\n";
        }
  
  else if (comp==2) //Computer paper
       {
        res = 2;
        cout << "Paper!\n";
        }
  else if (comp==3)  // Computer scissors
        {
        res = 3;
        cout << "Scissors!\n";
        }
  
  /*
     The outcome if user or comp wins,loses, or draws
   
  */
    //If user beats the comp
    if((choice == 1 && comp == 3) || (choice==2 && comp==2) || (choice==3 && comp ==2))
    {
    	cout << "GG you win!" << endl;
    	
	}
	
	//If user and comp get draw
     else if ((choice == 1 && comp == 1) || (choice==2 && comp==2) || (choice==3 && comp==3))
     {
     	cout << "Hmm, it seems like you are good at this" << endl;
     	
	 }
     
     //If comp beats you
     else
     {
     	cout << "HAHA you lose!" << endl;
	 }
	 
	 do{
	 	
	 	cout << "Want another go at this (y/n)?"<< endl;
	 	cin >> again;
        break;
	 } while(again !='y');
	   {
	   	//This is not working at the moment
	   	if(again == 'y' || again == 'Y')
	   	   {
	   	   //This and other missing code will start the program again from top
	   	    	cout << "heh it's not even working at the moment!!!!" << endl; //If user selects n or N after input
			 }
			 else
			 {
			 	cout << "At least the n button works!!!!!" << endl; //If user selects n or N after input
			 }
	    }
	
	 
    system("pause");
       return 0;
   }
	

