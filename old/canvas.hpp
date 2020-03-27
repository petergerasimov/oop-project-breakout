#ifndef __CANVAS_HPP
#define __CANVAS_HPP

class Canvas
{
    private:
        int width = 100;
        int height = 50;
        char** frameBuffer;
        char** allocBuffer(int width, int height);
        void deleteBuffer(char** buff, int size);
        void fitWindow();
        void setCharColor(char c);

    public:
        Canvas();
        Canvas(int width, int height);
        ~Canvas();
        
        void draw();
        void clear();
        //void clear(Color c);
        void resize(int width, int height);
        void setChar(int x, int y, char color);
        void rect(int x, int y, int w, int h ,char c = 'f');
};

#endif //__CANVAS_HPP