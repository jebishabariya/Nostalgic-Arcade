#include "Game.h"
#include<iostream>
#include<conio.h>
#include<windows.h>
using namespace std;
/*Game:: Game(QWidget* parent)    : QDialog(parent)
    , ui(new Ui::Game)
{
    ui->setupUi(this);
}
Game::~Game()
{
    delete ui;
}*/


//initialize variables
bool gameRun;
const int width = 25;
const int height = 25;
int x,y,spd=1;
int tailX[100], tailY[100],tailLength;
int tailcX1, tailcY1, tailcX2, tailcY2;
int fruitX, fruitY;
int score;
enum directions { STOP = 0,UP,DOWN,LEFT,RIGHT };
directions dir;


void gameSetup(){
    gameRun = true;
    dir = STOP;
    x = rand() % width;
    y = rand() % height;
    fruitX= rand() % width;
    fruitY = rand() % height;
    //Error when target and player are on top
    while (x==fruitX && y==fruitY){
        x = rand() % width;
        y = rand() % height;
        fruitX= rand() % width;
        fruitY = rand() % height;
    }
    score = 0;
}

void gameWindow(){
    system("cls");
    //top border
    for (int i =0; i<width ;i++){
        cout<<"*";
    }
    cout<<"\n";
    //body
    for(int i = 0;i < height ; i++){
        for(int j=0;j<width ;j++){
            if(j==0 || j==(width-1)){
                cout<<"#";
            }
            else if(i==y && j==x){
                cout<<"O";
            }
            else if (i==fruitY && j==fruitX){
                cout<<"F";
            }
            else {
                bool tail = false;
                for (int k =0; k<tailLength;k++){
                    if(j==tailX[k] && i==tailY[k]){
                        cout <<"o";
                        tail = true;
                    }

                }
                if(!tail){
                    cout<<" ";
                }
            }
        }
        if(i<height-1){
            cout<<"\n";}
    }
    cout<<endl;
    //bottom border
    for (int i =0; i<width ;i++){
        cout<<"*";}
    cout<<"\nScore:"<<score;
}

void userInput(){
    if(_kbhit()){
        switch(_getch()){
        case 'a':
            if(dir != RIGHT){
                dir=LEFT;
            }
            break;
        case 's':
            if(dir != UP){
                dir = DOWN;
            }
            break;
        case 'd':
            if(dir != LEFT){
                dir=RIGHT;
            }
            break;
        case 'w':
            if(dir != DOWN){
                dir = UP;
            }
            break;
        case '0':
            gameRun = false;
            break;
        }
    }
}

void gameWork(){
    tailcX1=tailX[0];
    tailcY1=tailY[0];
    tailX[0]=x;
    tailY[0]=y;
    for(int i=1;i<tailLength;i++){
        tailcX2=tailX[i];
        tailcY2=tailY[i];
        tailX[i]=tailcX1;
        tailY[i]=tailcY1;
        tailcX1=tailcX2;
        tailcY1=tailcY2;
    }
    switch(dir){
    case LEFT:
        x-=spd;
        break;
    case RIGHT:
        x+=spd;
        break;
    case UP:
        y-=spd;
        break;
    case DOWN:
        y+=spd;
        break;
    case STOP:
        break;
    }
    if(x<=0 || x>=width-1 || y <0|| y>height-1){
        gameRun=false;
    }
    if(x==fruitX && y== fruitY){
        fruitX= rand() % width;
        fruitY = rand() % height;
        score++;
        tailLength++;
    }
}

int main(){
    gameSetup();
    while(gameRun==true){
        gameWindow();
        userInput();
        gameWork();
        Sleep(150);
    }
    return 0;
}
