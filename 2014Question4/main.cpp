#include <iostream>

using namespace std;

const int  SIZE = 5;

void InitializeGrid(char grid[][SIZE], int x, int y)
{
    for(int i = 0; i < SIZE; i++)
    {
        for(int j = 0; j < SIZE; j++)
        {
            grid[i][j] = 'x';
        }
    }
    grid[x][y] = 'o';
}


void PrintGrid(char grid[][SIZE])
{
    for(int i = 0; i < SIZE; i++)
    {
        for(int j = 0; j < SIZE; j++)
        {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void moveRight(int &x)
{
    if(x < SIZE - 1)
    {
        x++;
    }
    else
    {
        x = 0;
    }
}

void moveLeft(int &x)
{
    if(x > 0)
    {
        x--;
    }
    else
    {
        x = SIZE - 1;
    }
}

void moveUp(int &y)
{
    if(y > 0)
    {
        y--;
    }
    else
    {
        y = SIZE - 1;
    }
}

void moveDown(int &y)
{
    if(y < SIZE - 1)
    {
        y++;
    }
    else
    {
        y = 0;
    }
}

void findPlayer(char grid[][SIZE], int& x, int& y)
{
    for(int i = 0; i < SIZE; i++)
    {
        for(int j = 0; j < SIZE; j++)
        {
            if(grid[i][j] == 'o')
            {
                x = i;
                y = j;
                break;
            }
        }
    }
}

int main()
{
    char grid[SIZE][SIZE];
    int xCordinate = 0;
    int yCordinate = 0;
    char direction;

    while(true)
    {
        InitializeGrid(grid, yCordinate, xCordinate);
        PrintGrid(grid);
        cin >> direction;
        findPlayer(grid, yCordinate, xCordinate);
        if(direction == 'r' || direction == 'R')
        {
            moveRight(xCordinate);
        }
        else if(direction == 'l' || direction == 'L')
        {
            moveLeft(xCordinate);
        }
        else if(direction == 'u' || direction == 'U')
        {
            moveUp(yCordinate);
        }
        else if(direction == 'd' || direction == 'D')
        {
            moveDown(yCordinate);
        }
        else
        {
            //We are going to quit.
            return 0;
        }
    }

    return 0;
}
