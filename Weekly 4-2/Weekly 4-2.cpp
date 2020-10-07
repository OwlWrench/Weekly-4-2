#include <iostream>
#include <iterator>
#include <ctime>
#include <cstdlib>
#include <conio.h>

int printBoard(int);
int getRandomNumber(int max);


char board[100];


const char player = '*';
const char upstair = '/';
const char downstair = '\\';
const char goalpole = 'G';


int main()
{
    srand(time(nullptr));

    bool over = 0;

    //placing ---------------------------------------------
    int place = getRandomNumber(std::size(board));

    board[place] = player;

    bool valid = 0;
    int up;

    do
    {
        up = getRandomNumber(std::size(board));
        if (board[up] != player)
        {
            valid = 1;
        }
    } while (valid == 0);
    board[up] = upstair;
    
    valid = 0;
    int down;
    do
    {
        down = getRandomNumber(std::size(board));
        if (board[down] != player && board[down] != upstair)
        {
            valid = 1;
        }
    } while (valid == 0);
    board[down] = downstair;

    valid = 0;
    int goal;
    do
    {
        goal = getRandomNumber(std::size(board));
        if (board[goal] != player && board[goal] != upstair && board[goal] != downstair)
        {
            valid = 1;
        }
    } while (valid == 0);
    board[goal] = downstair;
   // placing done -----------------------------------------
    
    int level = 1;


    do 
    {
        

        
        // print correct level -------------------
        switch (level)
        {
        case 1:
            board[down] = downstair;
            board[up] = upstair;
            board[goal] = ' ';
            break;
        case 2:
            board[down] = ' ';
            board[up] = downstair;
            board[goal] = goalpole;
            break;
        case 0:
            board[down] = upstair;
            board[up] = ' ';
            board[goal] = ' ';
            break;
        }
        // print correct level done -------------------

        // change level ----------------
        switch (board[place])
        {
        case downstair:
            if (level >= 0)
            {
                level -= 1;
            }    
            break;
        case upstair:
            if (level <= 2)
            {
                level += 1;
            }
            break;
        case goalpole:
            over = 1;
            break;
        }
        //change level done ----------------------

        board[place] = player;

        printBoard(0);
        //std::cout << place;
       

        char move = _getch();

        
        // moving ----------------------------------------------------
        switch (move)
        {
        case 'a':
            if (place - 1 > -1)
            {
                board[place] = ' ';
                place -= 1;

                if ((place + 1) % 10 == 0 && place != 0)
                {
                    place += 10;
                }
            }
            else 
            {
                board[place] = ' ';
                place += 9;
            }
            break;

        case 'd':
            if (place + 1 < 100)
            {
                board[place] = ' ';
                place += 1;

                if (place % 10 == 0 && place != 0)
                {
                    
                    place -= 10;
                }
            }
            else
            {
                board[place] = ' ';
                place -= 9;
            }
            break;

        case 'w':
            if (place - 10 > -1)
            {
                board[place] = ' ';
                place -= 10;
                
            }
            else
            {
                board[place] = ' ';
                place += 90;
            }
            break;

        case 's':
            if (place + 10 < 100)
            {
                board[place] = ' ';
                place += 10;
            }
            else
            {
                board[place] = ' ';
                place -= 90;
            }
            break;
        }
            //moving end -----------------------------------
        

        

    } while (over == false);
    


}

int printBoard(int)
{
    system("CLS");

    for (int i = 0; i < std::size(board) ; i++)
    {
      
        if (i % 10 == 0 && i != 0)
        {
            std::cout << "\n";
        }

        std::cout << board[i];
        
    }
    return 0;


}


int getRandomNumber(int max)
{
    int randomNumber = rand() % max + 1;
    return randomNumber;
}