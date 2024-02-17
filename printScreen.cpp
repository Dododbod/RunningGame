#include <iostream>
#include <chrono>
#include <thread>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <cstring>
#include <string>
using namespace std;

int rows = 15;  //is actually cols
int cols = 100; //is actually rows

int headRow = 4;
int headCol = 11;

int carX = 12;
int carY = 100;

int pointCounter = 0;

//allocate memory for array
char** gameBoard = new char *[rows];

void printScreen()
{

    //initialize array
    
    //for (int i = 0; i < rows; i++) 
    //{
    //    gameBoard[i] = new char[cols];
   // }

    for (int i = 0; i < rows; i++)
    {
        gameBoard[i] = new char[cols];
        for (int j = 0; j < cols; j++)
        {
            //Creating score, top and body guidlines
            if (i == 0)
            {
                string scoreStr = "Score: " + to_string(pointCounter);
                strcpy(gameBoard[0], scoreStr.c_str());
            }
            if (i == rows-1)
            {
                gameBoard[i][j] = '-';  //Creating top line
            }
            else
            {
                gameBoard[i][j] = ' '; //Creating body
            }
        }
    }
    
    //add lines to array
    
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {

            //PLAYER

            if (i == headCol  && j == headRow) //headcol = 4, headrow = 5
            {
                gameBoard[i][j] = 'O'; //Player head
            }
            if ( i == headCol + 1 && j == headRow - 1)
            {
                gameBoard[i][j] = '/'; //Player arm
            }
            if ( i == headCol + 1 && j == headRow)
            {
                gameBoard[i][j] = '|'; //Player body
            }
            if ( i == headCol + 1 && j == headRow + 1)
            {
                gameBoard[i][j] = '\\'; //Player arm
            }
            if ( i == headCol + 2 && j == headRow)
            {
                gameBoard[i][j] = '^'; //Player torso
            }
            if ( i == headCol + 3 && j == headRow - 1)
            {
                gameBoard[i][j] = '/'; //Player leg
            }
            if ( i == headCol + 3 && j == headRow + 1)
            {
                gameBoard[i][j] = '\\'; //Player leg
            }

            //car start

            if ( i == carX && j == carY)
            {
                gameBoard[i][j] = '_';
            }
            if ( i == carX && j == carY + 1)
            {
                gameBoard[i][j] = '_';
            }
            if ( i == carX && j == carY + 2)
            {
                gameBoard[i][j] = '_';
            }
            if ( i == carX && j == carY + 3)
            {
                gameBoard[i][j] = '/';
            }
            if ( i == carX - 1 && j == carY + 4)
            {
                gameBoard[i][j] = '_';
            }
            if ( i == carX - 1 && j == carY + 5)
            {
                gameBoard[i][j] = '_';
            }
            if ( i == carX - 1 && j == carY + 6)
            {
                gameBoard[i][j] = '_';
            }
            if ( i == carX && j == carY + 7)
            {
                gameBoard[i][j] = '|';
            }
            if ( i == carX && j == carY + 8)
            {
                gameBoard[i][j] = '_';
            }
            if ( i == carX && j == carY + 9)
            {
                gameBoard[i][j] = '_';
            }
            if ( i == carX + 1 && j == carY + 9)
            {
                gameBoard[i][j] = '|';
            }
            if ( i == carX + 2 && j == carY + 9)
            {
                gameBoard[i][j] = '|';
            }
            if ( i == carX + 2 && j == carY + 8)
            {
                gameBoard[i][j] = '-';
            }
            if ( i == carX + 2 && j == carY + 7)
            {
                gameBoard[i][j] = ')';
            }
            if ( i == carX + 2 && j == carY + 6)
            {
                gameBoard[i][j] = '(';
            }
            if ( i == carX + 2 && j == carY + 5)
            {
                gameBoard[i][j] = '-';
            }
            if ( i == carX + 2 && j == carY + 4)
            {
                gameBoard[i][j] = '-';
            }
            if ( i == carX + 2 && j == carY + 3)
            {
                gameBoard[i][j] = ')';
            }
            if ( i == carX + 2 && j == carY + 2)
            {
                gameBoard[i][j] = '(';
            }
            if ( i == carX + 2 && j == carY + 1)
            {
                gameBoard[i][j] = '-';
            }
            if ( i == carX + 2 && j == carY)
            {
                gameBoard[i][j] = '-';
            }
            if ( i == carX + 1 && j == carY)
            {
                gameBoard[i][j] = '|';
            }


            //Col check

            //if ((headCol + 2 == carX + 1) && ( headRow < carY + 4 && headRow > carY))
            //{
            //    cout << "GAMEOVER" << endl;
            //    break;
            //}
            
        }
    }

    //accessing array to print

    for (int i = 0; i < rows; i++) 
    {
        for (int j = 0; j < cols; j++) 
        {
            cout << gameBoard[i][j] << " ";
        }
        cout << endl;
    }


}