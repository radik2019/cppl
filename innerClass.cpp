
#include <iostream>
#include <ctime>
#include <string>
#include <cmath>
#include <map>
#include <exception>
#include <fstream>
using namespace std;
#include "r_header.h"

class Image
{

private:
    class Pixel
    {
    private:
        int r, g, b;

    public:
        Pixel(int r, int g, int b)
        {
            this->r = r;
            this->g = g;
            this->b = b;
        }
        Pixel()
        {
            this->r = 12;
            this->g = 12;
            this->b = 12;
        }
        ~Pixel()
        {
            cout << "deleted Pixel(" << this->r << ", " << this->g << ", " << this->b << ")" << endl;
        }

        int getR(){return this->r;}
        int getG(){return this->g;}
        int getB(){return this->b;}
        void setR(int r){this->r = r;}
        void setG(int g){this->g = g;}
        void setB(int b){this->b = b;}
    };
    int len;
    Pixel *lst;
    const int rows = 3;

public:
    Image(int len, int **&lst);
    Image();
    ~Image();

    void info()
    {
        cout << "length:\t" << this->len << endl;
        for (int i = 0; i < this->len; i++)
        {
            cout << "r = " << this->lst[i].getR() << "\tg = " <<\
             this->lst[i].getG() << "\tb = " << this->lst[i].getB() << endl;
        }
        
    }
    
    void setPixel(int index, int r, int g, int b){
        cout << "Image setter...\n\n";
        this->lst[index].setR(r);
        this->lst[index].setG(g);
        this->lst[index].setB(b);
    }
};

Image::Image(int len, int **&lst)
{
    this->len = len;
    this->lst;
    this->lst = new Pixel [this->len];
    for (int i = 0; i < this->len; i++)
    {
        this->lst[i] = Pixel(lst[i][0], lst[i][1], lst[i][2]);  
    } 
}

Image::Image()
{
    this->len = 1;
}

Image::~Image()
{
    cout << "deleted  Image" << endl;
}

int main()
{
    int count = 36;
    int cols = 3;
    int **lst = new int *[count];
    for (int i = 0; i < count; i++){
        lst[i] = new int[cols];
        for (int k = 0; k < cols; k++){
            lst[i][k] = rand() % 250;
        }
    }
    Image img(count, lst);
    img.setPixel(2, 0, 0, 0);
    img.info();
    cout << 3333;

    return 0;
}
