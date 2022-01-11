#include <iostream>
#include <ctime>
#include <stdlib.h>
using namespace std;

int main(){

/*

- Ammar Ahmed
- Muhammad Haseeb
- Prem Sagar

BSCS1 SEC 'A'
  
*/


srand (time(0));

int z = 1;

int pos_x, pos_y;

char sq = (char)z, c = '0', exitStatus = '0';

int grid[4][4];
do{

bool gameOver = false;

char showGrid[4][4] = { {sq,sq,sq,sq}, 
                        {sq,sq,sq,sq}, 
						{sq,sq,sq,sq}, 
						{sq,sq,sq,sq} };

int count = 0, mines = 0;

bool maxMines = false;

// Assigning -1 and 2 randomly, -1 represents a mine.

for (int i = 0; i < 4; i++)
{
	for (int j = 0; j < 4; j++)
    {
    	int randNum = rand()%8 + 1;
    	
    	if ((randNum == 1 || randNum == 2) && !maxMines) 
    	{
    		grid[i][j] = -1;
    		count++;
    		
    		if (count == 2)
    		{
    			maxMines = true;
			}
			
		}
		else
		{
			grid[i][j] = -2;
		}
	}
}
 
do{
	
	mines = 0;
	c = '0';

for (int i = 0; i < 4; i++)
{
	cout << i << " ";
	
	for (int j = 0; j < 4; j++)
	{
		cout << showGrid[i][j] << " ";
	}
	
	cout << endl;
}
//
{
cout << "  ";

for (int i = 0; i < 4; i++)
cout << i << " ";
cout << endl;
}

if (exitStatus == '0')
{
  cout << "Enter the coordinates of the cell you want to select, e.g. (1 0)" << endl;	
  cin >> pos_y >> pos_x;
  
}else 
{
	cin >> pos_y >> pos_x;
}

system("cls");

// This block is executed when mine is found

if (grid[pos_y][pos_x] == -1)
{
	showGrid[pos_y][pos_x] = '*';
	
	for (int i = 0; i < 4; i++)
    {
	 cout << i << " ";
	
	 for (int j = 0; j < 4; j++)
	 {
		cout << showGrid[i][j] << " ";
	 }
	
	cout << endl;
    }
    
cout << "  ";

for (int i = 0; i < 4; i++)
cout << i << " ";
cout << endl;

cout << endl << "Game Over" << endl;
gameOver = true;

}
/* Otherwise the rest of the blocks will find whether the adjacent cells contain any mines and show the 
appropraite number in the selected cell. */

else
{
	
if (pos_y == 0 && pos_x == 0)
{
	
	if(grid[pos_y][pos_x + 1] == -1)
	{
		mines++;
	}
	
	if (grid[pos_y + 1][pos_x] == -1)
	{
		mines++;
	}
	
	if (grid[pos_y + 1][pos_x + 1] == -1)
	{
		mines++;
	}
}
else if (pos_y == 4-1 && pos_x == 4-1)
{
	
	if (grid[pos_y - 1][pos_x] == -1)
	{
		mines ++;
	}
	
	if (grid[pos_y][pos_x - 1] == -1)
	{
		mines++;
	}
	
	if(grid[pos_y - 1][pos_x - 1] == -1)
	{
		mines++;
	}
}
else if (pos_y == 4-1 && pos_x == pos_x == 0)
{
	
	if (grid[pos_y][pos_x + 1] == -1)
	{
		mines++;
	}
	
	if (grid[pos_y - 1][pos_x] == -1)
	{
		mines++;
	}
	
	if (grid[pos_y - 1][pos_x + 1] == -1)
	{
		mines++;
	}
}
else if (pos_y == 0 && pos_x == 4-1)
{
	if (grid[pos_y][pos_x - 1] == -1)
	{
		mines++;
	}
	
	if (grid[pos_y + 1][pos_x - 1] == -1)
	{
		mines++;
	}
	
	if (grid[pos_y + 1][pos_x] == -1)
	{
		mines++;
	}
}
else if (pos_y == 0 && pos_x != 0 && pos_x != 4-1)
{
	if (grid[pos_y][pos_x - 1] == -1)
	{
		mines++;
	}
	
	if (grid[pos_y][pos_x + 1] == -1)
	{
		mines++;
	}
	
	if (grid[pos_y + 1][pos_x - 1] == -1)
	{
		mines++;
	}
	
	if (grid[pos_y + 1][pos_x] == -1)
	{
		mines++;
	}
	
	if (grid[pos_y + 1][pos_x + 1] == -1)
	{
		mines++;
	}
}
else if (pos_y == 4-1 && pos_x != 0 && pos_x != 4-1)
{
	if (grid[pos_y][pos_x - 1] == -1)
	{
		mines++;
	}
	
	if (grid[pos_y][pos_x + 1] == -1)
	{
		mines++;
	}
	
	if (grid[pos_y - 1][pos_x] == -1)
	{
		mines++;
	}
	
	if (grid[pos_y - 1][pos_x - 1] == -1)
	{
		mines++;
	}
	
	if (grid[pos_y - 1][pos_x + 1] == -1)
	{
		mines++;
	}
}
else if (pos_x == 0 && pos_y != 0 && pos_y != 4-1)
{
	if (grid[pos_y][pos_x + 1] == -1)
	{
		mines++;
	}
	
	if (grid[pos_y + 1][pos_x + 1] == -1)
	{
		mines++;
	}
	
	if (grid[pos_y - 1][pos_x] == -1)
	{
		mines++;
	}
	
	if (grid[pos_y - 1][pos_x + 1] == -1)
	{
		mines++;
	}
	
	if (grid[pos_y + 1][pos_x] == -1)
	{
		mines++;
	}
}
else if (pos_x == 4-1 && pos_y != 4-1 && pos_y != 0)
{
	if (grid[pos_y][pos_x - 1] == -1)
	{
		mines++;
	}
	
	if (grid[pos_y + 1][pos_x - 1] == -1)
	{
		mines++;
	}
	
	if (grid[pos_y + 1][pos_x] == -1)
	{
		mines++;
	}
	
	if (grid[pos_y - 1][pos_x] == -1)
	{
		mines++;
	}
	
	if (grid[pos_y - 1][pos_x - 1] == -1)
	{
		mines++;
	}
}
else if (pos_y != 0 && pos_y != 4-1 && pos_x != 4-1 && pos_x != 0)
{
	if (grid[pos_y - 1][pos_x] == -1)
	{
		mines++;
	}
	
	if (grid[pos_y - 1][pos_x - 1] == -1)
	{
		mines++;
	}
	
	if (grid[pos_y - 1][pos_x + 1] == -1)
	{
		mines++;
	}
	
	if (grid[pos_y][pos_x - 1] == -1)
	{
		mines++;
	}
	
	if (grid[pos_y][pos_x + 1] == -1)
	{
		mines++;
	}
	
	if (grid[pos_y + 1][pos_x] == -1)
	{
		mines++;
	}
	
	if (grid[pos_y + 1][pos_x - 1] == -1)
	{
		mines++;
	}
	
	if (grid[pos_y + 1][pos_x + 1] == -1)
	{
		mines++;
	}
}

c = c + mines;
		
showGrid[pos_y][pos_x] = c;
		
    
	
system("cls");	
}

}while (gameOver == false);

cout << endl << "Press 'y' to play the game again, 'n' to exit: ";
cin >> exitStatus;

system ("cls");

}while (exitStatus == 'y');

cout << "Thank you for playing the game :) " << endl;

system("PAUSE");
return 0;
}

