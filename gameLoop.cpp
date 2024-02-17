#include <iostream>
#include <chrono>
#include <thread>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
using namespace std;

int jumpCounter = 200;
bool gameRun = true;

void gameLoop()
{
    while(gameRun)
    {
        //loops printing screen
        printScreen();

        //Check Col
        if ((headCol + 2 == carX + 1) && ( carY - 1 <= headRow && carY + 10 >= headRow))
            {
                //deletes gameboard and exits gameloop
                system("CLS");
                cout << "GAMEOVER" << endl;
                for (int i = 0; i < rows; i++) 
                {
                    delete[] gameBoard[i];
                }
                delete[] gameBoard;
                
                //ends game
                break;
                
            }

        //key inputs

        if (GetAsyncKeyState(VK_SPACE))
        {
            if(jumpCounter >= 100)
            {
                if (headCol < 2)
                {
                    break;
                }
                else
                {
                    headCol = headCol - 10; 
                }
                jumpCounter = 0;
            }
        }

        
        if (GetAsyncKeyState(VK_RIGHT))
        {
            if(headRow > cols)
            {
                break;
            }
            else
            {
                headRow =  headRow + 5;
            }
            
        }
        
        if (GetAsyncKeyState(VK_LEFT))
        {
            if(headRow < 0)
            {
                break;
            }
            else
            {
                headRow =  headRow - 3;
            }
            
        }
        if ( headCol < 11)
        {
            //Sleep(10);
            if (headCol % 2 == 0)
            {
                headCol = headCol + 3;
            }
            if (headCol % 2 != 0)
            {
                headCol = headCol + 2;
            }
        }

        //Car Y movement

        if(carY <= 0)
        {
            carY = 100;
        }
        srand(time(0));
        int random = rand() % 40;
        carY = carY - random;

        //Clears Screen to refresh with new array

        system("CLS");

        //Refreshes jump each screen refresh

        jumpCounter = jumpCounter + 20;

    }
}