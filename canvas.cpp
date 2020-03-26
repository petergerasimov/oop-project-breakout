#include "canvas.hpp"
#include <iostream>
#include <string>
#include <cstring>


Canvas::Canvas()
{
    frameBuffer = allocBuffer(width, height);
    fitWindow();
}

Canvas::Canvas(int width, int height)
{
    this->width = width;
    this->height = height;
    frameBuffer = allocBuffer(width, height);
    fitWindow();
}

Canvas::~Canvas()
{
    deleteBuffer(frameBuffer, width);
}

//Allocate memory for a 2D char matrix
char** Canvas::allocBuffer(int width, int height)
{
    char** buff = new (std::nothrow) char* [width];
    if (!buff)
        return buff;

    for (int i = 0; i < width; i++)
    {
        buff[i] = new (std::nothrow) char[height];
        if (!buff[i])
        {
            deleteBuffer(buff, i);
            return nullptr;
        }
    }

    return buff;
}

//Delete the 2D char matrix
void Canvas::deleteBuffer(char** buff, int size)
{
    for (int i = 0; i < size; i++) {
        delete[] buff[i];
    }
    delete[] buff;
}

//Fits the makes the window the size of width and height
void Canvas::fitWindow()
{
    //Windows only
    std::string cmd = "mode CON: COLS=" + 
                      std::to_string(width) +
                      " LINES=" +
                      std::to_string(height);
    system(cmd.c_str());
}

//currently only sets foreground color
void Canvas::setCharColor(char c)
{
    //Windows only
    std::string a = {c};
    std::string cmd = "color " + a;
    system(cmd.c_str());
}

void Canvas::draw()
{
    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
        {
            if(frameBuffer[j][i] != 0)
            {
                //setCharColor(frameBuffer[j][i]);
                std::cout << 'X';
            }
            else
            {
                std::cout << ' ';
            }
            
        }
        std::cout << std::endl;
    }   
}

void Canvas::clear()
{
    system("cls"); //Windows only

    for(int i = 0; i < width; i++)
    {
        memset(frameBuffer[i], 0, height);
    }
}

void Canvas::resize(int width, int height)
{
    deleteBuffer(frameBuffer, this->width);
    frameBuffer = allocBuffer(width, height);
    fitWindow();
}

void Canvas::setChar(int x, int y, char color)
{
    //Add e test so you don't go out of the array
    frameBuffer[x][y] = color;
}

void Canvas::rect(int x, int y, int w, int h ,char c)
{
    for(int i = x; i < x + w; i++)
    {
        memset(frameBuffer[i] + y, c, h);
    }
}