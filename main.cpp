#include <iostream>
#include "canvas.hpp"

int main () 
{
    Canvas c(60,30);
	while(true)
    {
        c.clear();

        c.rect(0, 0, 60, 30, 'a');
        //system("color a");
        //c.setChar(5,5,'a');

        c.draw();
    }
    return EXIT_SUCCESS;
}