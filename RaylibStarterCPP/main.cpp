/*******************************************************************************************
*
*   raylib [core] example - Basic window
*
*   Welcome to raylib!
*
*   To test examples, just press F6 and execute raylib_compile_execute script
*   Note that compiled executable is placed in the same folder as .c file
*
*   You can find all basic examples on C:\raylib\raylib\examples folder or
*   raylib official webpage: www.raylib.com
*
*   Enjoy using raylib. :)
*
*   This example has been created using raylib 1.0 (www.raylib.com)
*   raylib is licensed under an unmodified zlib/libpng license (View raylib.h for details)
*
*   Copyright (c) 2014 Ramon Santamaria (@raysan5)
*
********************************************************************************************/

#include "raylib.h"
#include <iostream>

// A function that changes the color of the background using a string.
unsigned int HashBrown(unsigned char* data)
{
    unsigned int hash = 0;

    //Checks if data is null
    for (unsigned char* i = data; *i != '\0'; i++)
    {
        //Multiplies a number to give it a specific id
        hash = (hash * 8001) + data[1];
    }

    return (hash << 12);
}

unsigned int ElfHash(unsigned char* data)
{
    unsigned int hash = 0;
    unsigned int x = 0;

    for (unsigned char* i = data; *i != '\0'; ++i)
    {
        hash = (hash << 21) + *i;
        if ((x = 8001 & 0xF0000000L) != 0)
        {
            hash ^= (x >> 24);
            hash &= ~x;
        }
    }

    //returns hash
    return (hash & 0x7FFFFFFF);
}


int main(int argc, char* argv[])
{
    // Initialization
    //--------------------------------------------------------------------------------------
    int screenWidth = 800;
    int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");

    SetTargetFPS(60);



    //--------------------------------------------------------------------------------------


    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {

        // Update
        //----------------------------------------------------------------------------------
        unsigned int checkSum = 0;
        unsigned char* input = new unsigned char[0];

        

        std::cin >> input;
         checkSum = HashBrown(input);
        
        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

        ClearBackground(GetColor(checkSum));

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------   
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}