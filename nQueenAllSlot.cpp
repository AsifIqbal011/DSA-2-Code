#include<iostream>
using namespace std;

void printBoard(int n,int board[][20])
{
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
}

bool canPlace(int board[][20],int n,int x,int y)
{
//check column
    for(int k=0; k<x; k++)
    {
        if(board[k][y]==1)
        {
            return false;
        }
    }

//left diagonal
    int i=x,j=y;
    while(i>=0&&j>=0)
    {
        if(board[i][j]==1)
        {
            return false;
        }
        i--;
        j--;
    }
//right diagonal
    i=x,j=y;
    while(i>=0&&j<n)
    {
        if(board[i][j]==1)
        {
            return false;
        }
        i--;
        j++;
    }
    return true;
}

int solveQueen(int n,int board[][20],int i)
{
    if(i==n)
    {
       printBoard(n,board);
       cout<<endl;
        return 1;
    }
    int ways = 0;

    for(int j=0; j<n; j++){      //Q place in row

        if(canPlace(board,n,i,j)){
            board[i][j]=1;
            ways += solveQueen(n,board,i+1);

            board[i][j]=0;      //backtrack
        }
    }
    return ways;
}

int main()
{
    int n;
    cin>>n;
    int board[20][20]= {0};
    solveQueen(n,board,0);
    return 0;
}

