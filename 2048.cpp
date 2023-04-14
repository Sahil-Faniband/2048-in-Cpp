#include<iostream>

#include<stdlib.h>
#include<iomanip>
#include<ctime>
using namespace std;

int board[4][4];
int dir_row[]={1,0,-1,0};
int dir_colum[]={0,1,0,-1};

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
void add_number(){
    pair<int,int>pos=random_unoccupied_pos();
    int temp;
    temp=1+(rand()%100);
    if(temp<90)
        board[pos.first][pos.second]=2;
    else
        board[pos.first][pos.second]=4;
}
void new_game(){
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            board[i][j]=0;
        }
    }
    add_number();
    add_number();  
}
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
bool can_do_move(int r,int c,int next_r,int next_c){
    if(next_r<0 || next_c<0 || next_r>=4 || next_c>=4 || board[r][c]!=board[next_r][next_c] && board[next_r][next_c]!=0)
        return false;
    return true;
}
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

