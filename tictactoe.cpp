#include<iostream>
using namespace std;
bool WinloseDraw();
void Structure();
void CheckInvalid();


char space[3][3]={{'1','2','3'},{'4','5','6'},{'7','8','9'}};
int row;
int column;
bool tie=false;
char token='X';
string n1="";
string n2="";

 //checking the condition for winning and losing
bool WinLoseDraw()
{
    int i,j;
    for(i=0;i<3;i++)
    {
     if((space[i][0]==space[i][1] && space[i][1]==space[i][2]) || (space[0][i]==space[1][i] && space[1][i]==space[2][i]))
     {
      return true;
     }
    }

    if ((space[0][0]==space[1][1] && space[1][1]==space[2][2]) || (space[0][2]==space[1][1] && space[1][1]==space[2][0]))
    {
      return true;

    }

    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            if(space[i][j]!='X' && space[i][j]!='Y')
            {
               return false;
            }
        }
    }
    tie=true;
    return false;
}
    

// function for checking for condition for input value and
// invalid value and enterin 'X' and 'O' in respective place as per user
void CheckInvalid()
{
 int digit;
  start:
 if(token=='X')
  {
    cout<<n1<<"please enter\n";
    cin>>digit;
    
  }
  if(token=='O')
  {
    cout<<n2<<"please enter\n";
    cin>>digit;
  
  }
  if(digit==1)
  {
    row=0;
    column=0;
  }

  if(digit==2)
  {
    row=0;
    column=1;
  }
  if(digit==3)
  {
    row=0;
    column=2;
  }
  if(digit==4)
  {
    row=1;
    column=0;
  }
  if(digit==5)
  {
    row=1;
    column=1;
  }

  if(digit==6)
  {
    row=1;
    column=2;
  }
  if(digit==7)
  {
    row=2;
    column=0;
  }
  if(digit==8)
  {
    row=2;
    column=1;
  }

  if(digit==9)
  {
    row=2;
    column=2;
  }
  if  (!(digit<=9 && digit>=1))
  {
    cout<<"Invalid Value !!!"<<endl;
    goto start;
  }

  if(token=='X' && space[row][column]!='X'&& space[row][column]!='0')
  {
    space[row][column]='X';
    token='O';
  }
  else if(token=='O'&& space[row][column]!='O'&& space[row][column]!='0')
  {
    space[row][column]='O';
    token='X';
  }
  else
  {
    cout<<"There is no empty space "<<endl;
    CheckInvalid();
  }
 Structure(); 
}





//function for entering name of the player and forming structure.
void Structure()
{

   
     
    //Forming structure of game 

     cout<< "      |      |      \n";
     cout<<"  "<<space[0][0]<<"   |  "<<space[0][1]<<"   |  "<<space[0][2]<< "   \n";
     cout<< "______|______|______\n" ;
     cout<< "      |      |         \n";
     cout<<"  "<<space[1][0]<<"   |  "<<space[1][1]<<"   |  "<<space[1][2]<< "   \n";
     cout<< "______|______|______\n" ;
     cout<< "      |      |         \n";
     cout<<"  "<<space[2][0]<<"   |  "<<space[2][1]<<"   |  "<<space[2][2]<< "   \n";
     cout<< "      |      |      \n";
}
int main()
{

    //Entering the name of the player from user
    cout<<"Enter the name of the first player : \n";
    getline(cin,n1);
    cout<<"Enter the naem of the second player : \n";
    getline(cin,n2);
    //Assignin the turn in game
    cout<<n1<<" is player 1 so he/she will play first\n";
    cout<<n2<<" is player 2 so he/she will play secod\n";


    while(!WinLoseDraw())
    {
      Structure();
      CheckInvalid();  
      WinLoseDraw();
    }
    if(token=='X' && tie == false)
    {
        cout<<n1<<" Wins"<<endl;
    }
    else if(token=='O' && tie==false)
    {
        cout<<n2<<" Wins"<<endl;
    }
    else 
    {
        cout<<"It's Draw"<<endl;
    }
    return 0;
}