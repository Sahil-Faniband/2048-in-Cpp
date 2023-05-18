#include<iostream>

#include<stdlib.h>
#include<iomanip>
#include<ctime>
using namespace std;

int board[4][4];
int dir_row[]={1,0,-1,0};
int dir_colum[]={0,1,0,-1};
/**
 * This function generates a random unoccupied position on a 4x4 board.
 * 
 * @return a pair of integers, where the first integer represents the row and the second integer
 * represents the column of a randomly selected unoccupied position on the board.
 */
pair<int,int>random_unoccupied_pos(){
    int occupied=1,row,colum;
    while(occupied){
        row=rand()%4;
        colum=rand()%4;
        if(board[row][colum]==0)
            occupied=0;
    }
    return make_pair(row,colum);
}
/**
 * The function adds a randomly generated number (either 2 or 4) to an unoccupied position on the game
 * board.
 */
void add_number(){
    pair<int,int>pos=random_unoccupied_pos();
    int temp;
    temp=1+(rand()%100);
    if(temp<90)
        board[pos.first][pos.second]=2;
    else
        board[pos.first][pos.second]=4;
}
/**
 * The function initializes a new game board by setting all elements to 0 and adding two random
 * numbers.
 */
void new_game(){
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            board[i][j]=0;
        }
    }
    add_number();
    add_number();  
}
/**
 * The function prints the current state of the game board and instructions for the user to play the
 * game.
 */
void printUI(){
    system("cls");
    cout<<"\n";
     for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            if(board[i][j]==0){
                cout<<"|"<< setw(2) <<"*"<< setw(2) <<"|";
            }
            else{
                cout<<"|"<< setw(2) <<board[i][j]<< setw(2) <<"|";
            }
            if(board[i][j]==2048){
                        cout<<"--------------> CONGRATULATIONS <----------------\n";
                        cout<<"-------------->  YOU WIN....!!  <------------------\n";
                        exit(0);
            }
            
        }
        cout<<"\n";
    }
    cout<<"\n";
    
    cout<<"\nUse keys:\n";
    cout<<" N:New Game | W:Up | S:Down | D:Right | A:Left | Q:Quit\n";
}
/**
 * The function checks if a move is valid on a 4x4 board.
 * 
 * @param r The current row index of the piece on the game board.
 * @param c The parameter `c` most likely represents the column index of a cell on a 2D board.
 * @param next_r `next_r` is the row index of the next position on the board where the player wants to
 * move their game piece.
 * @param next_c `next_c` is the column index of the next position on the board where the current game
 * piece is being moved to.
 * 
 * @return The function `can_do_move` returns a boolean value (`true` or `false`).
 */
bool can_do_move(int r,int c,int next_r,int next_c){
    if(next_r<0 || next_c<0 || next_r>=4 || next_c>=4 || board[r][c]!=board[next_r][next_c] && board[next_r][next_c]!=0)
        return false;
    return true;
}
/**
 * The function "move" moves the tiles in a 2048 game board in a specified direction and adds a new
 * tile if possible.
 * 
 * @param diraction The direction in which the tiles on the game board should be moved. It can be
 * either 0 (up), 1 (right), 2 (down), or 3 (left).
 */
void move(int diraction){
    int start_row=0,start_colum=0,row_step=1,colum_step=1;
    if(diraction==0){
        start_row=3;
        row_step=-1;
    }
    if(diraction==1){
        start_colum=3;
        colum_step=-1;
    }
    int move_possible,can_add_number=0;
    do{
        move_possible=0;
        for(int i=start_row;i>=0 && i<4;i=i+row_step){
            for(int j=start_colum;j>=0 && j<4;j= j + colum_step){
                int next_i=i+dir_row[diraction],next_j= j + dir_colum[diraction];
                if(board[i][j]!=0 && can_do_move(i,j,next_i,next_j)){
                    board[next_i][next_j] = board[next_i][next_j] + board[i][j];
                    board[i][j]=0;
                    move_possible=can_add_number=1;
                }
               
            }
        }
        printUI();//For Transmission effect,
    }while(move_possible);
    if(can_add_number)
        add_number();
}
/**
 * This is the main function of a C++ program that allows the user to play the game 2048 by inputting
 * commands to move tiles on a game board.
 */
int main(){
    srand(time(0));
    char diraction_commends[128];
    diraction_commends['s']=0;
    diraction_commends['d']=1;
    diraction_commends['w']=2;
    diraction_commends['a']=3;
    cout<<"\nJoin the tiles, get to 2048!\n";
    new_game();
    while(true){
        printUI();
        char command;
        cin>>command;
        if(command=='n')
            new_game();   
        else if(command=='q')
            break;
        else{
            int current_diraction=diraction_commends[command];
            move(current_diraction);
        }
    }
}

