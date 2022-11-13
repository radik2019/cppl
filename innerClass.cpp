
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
                Pixel(int r, int g, int b){
                    this->r = r;
                    this->g = g;
                    this->b = b;
                }
                Pixel()
                {
                    this->r = 1;
                    this->g = 1;
                    this->b = 1;
                }
                ~Pixel(){
                    cout << "kjhkjhkjhkjhkjh\n";
                }
                string info(){
                    string s = "";
                    s += "Pixel(" + to_string(this->r) + ", " + to_string(this->g) + ", " + to_string(this->b) + ")\n";
                    return  s;
                }
        };
        Pixel *PixelLst;
        int len;
    public:
        void get_info(){
            for (int i = 0; i < this->len; i++)
            {
                cout << PixelLst[i].info();
            }
            
        }
        Image(int a);
        Image();
        ~Image();
        
};

Image::Image(int len)
{
    this->len = len;
    this->PixelLst = new Pixel[this->len];
}

Image::~Image()
{
    this->len = 0;
    this->PixelLst = new Pixel[this->len];
}



int main () {
    Image fg(2);
    fg.get_info();

    return 0;
}


