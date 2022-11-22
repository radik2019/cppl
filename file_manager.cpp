#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
/*
ifstream - modalita read
ofstream = modalita write
*/

class Point
{
private:
    int x;
    int y;

public:
    Point(int x, int y);
    Point();
    ~Point();
    void info()
    {
        cout << "x:  " << this->x << endl;
        cout << "y:  " << this->y << endl;
    }
    void changeData(int x, int y)
    {
        this->x = x;
        this->y = y;
    }
    
};

Point::Point()
{
    this->x = 0;
    this->y = 0;
}

Point::Point(int x, int y)
{
    this->x = x;
    this->y = y;
}

Point::~Point()
{
}

void writeDataToFile(const string file, string data)
{
    ofstream input_file;
    input_file.open(file);
    // input_file.app;
    if (input_file.is_open())
    {
        input_file << data << endl;
        input_file.close();
    }
}

string read(string file)
{
    // Create a text string, which is used to output the text file
    string myText;

    // Read from the text file
    ifstream MyReadFile(file);

    if (MyReadFile.is_open())
    {
        string temp;

        // Use a while loop together with the getline() function to read the file line by line
        while (getline(MyReadFile, myText))
        {
            // Output the text from the file
            cout << myText << endl;
            temp += myText;
        }
        // Close the file
        MyReadFile.close();
        return temp;
    }
    cout << "\n\n[ ERROR! ]\n\tSomething is wrong I have a problems at opening your file\n";
    return "";
}

bool writeObjectToFile(const string path, Point &pt ){

    ofstream wr_file;

    // string path = "my_object_file.dat";

    // si apre il file
    // path = percorso del file
    // fstream::app = modalita append
    wr_file.open(path, fstream::app);
    if (wr_file.is_open())
    {
        wr_file.write((char *)&pt, sizeof(Point));
        cout << "\nWrited! \n";
        wr_file.close();
        return true;
    }
    cout << "\nSomething wrong!\n";
    return false;
}

vector<Point> readObjectToFile(const string path){
    ifstream r_file;
    vector<Point> lst;

    // string path = "my_object_file.dat";

    // si apre il file
    // path = percorso del file
    // fstream::app = modalita append
    r_file.open(path);
    Point pt;
    if (r_file.is_open())
    {
        //r_file.read((char *)&pt, sizeof(Point)) // il metodo ritorna un bool
        // se c'e` un dato nelliterazione, ritorna true
        // altrimenti ritorna false
        while (r_file.read((char *)&pt, sizeof(Point)))
        {   
            lst.push_back(pt);
        }
        return lst;
    }
    return lst;
}


int main()
{
    // Point pt(2, 3);
    // pt.info();
    // cout << read("fissle.cpp") << endl;

    //                          SCRITTURA DI UN OGETTO SU UN FILE
    // Creazione dell'ogetto Point
    Point pt(211122, 888873);

    // creazione dell'ogetto scrittura su file "ofstream"
    ofstream wr_file;

    string path = "my_object_file.dat";
    // for (int i = 0; i < 10; i++)
    // {
    //     pt.changeData((i + 1) * (rand() % 10), (i + 34) * (rand() % 10));
    //     writeObjectToFile(path, pt);
    // }
    vector<Point> lst = readObjectToFile(path);
    lst[45].info();
    // si apre il file
    // path = percorso del file
    // fstream::app = modalita append
    // wr_file.open(path, fstream::app);
    // if (wr_file.is_open())
    // {
    //     wr_file.write((char *)&pt, sizeof(Point));
    //     cout << "\nWrited! \n";
    // }
    // else
    // {
    //     cout << "\nSomething wrong!\n";
    // }

    return 0;
}
