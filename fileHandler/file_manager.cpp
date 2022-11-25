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
    string str_info()
    {   string temp;
        temp = "x:  " + to_string(this->x) +"\ny:  " + to_string(this->y) + "\n";
        return temp;
    }
    void changeData(int x, int y)
    {
        this->x = x;
        this->y = y;
    }
    int getX(){return this->x;}
    int getY(){return this->y;}
    void setX(int x){this->x = x;}
    void setY(int y){this->y = y;}
    friend ostream &operator<<(ostream &fs ,Point &obj);
    friend istream &operator>>(istream &fs ,Point &obj);
    
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


//////////////////////////////////////////////////////////
/////////// OVERRIDING OPERATOR  "<<" AND ">>"////////////
//////////////////////////////////////////////////////////


ostream &operator<<(ostream &fs ,Point &obj)
{
    cout << "   Operator: <<  \n";
    fs << obj.getX() << " "<< obj.getY() << "\n";
    return fs;
}

istream &operator>>(istream &fs ,Point &obj)
{
    fs >> obj.x >> obj.y;
    cout << "   Operator: >>  \n";
    return fs;
}

int test_operator()
{
    // fstreamLesson();
    Point pt(945, 463);
    fstream fs;
    
    fs.open("___FSTREAM_OBJ.txt", fstream::in | fstream::out | fstream::app);
    cout << "{  \nFile is opened!\n";
    fs << pt;
    cout << "   The data was writing successfully\n";
    fs.close();
    cout << "File is closed!\n}\n";

    
    fs.open("___FSTREAM_OBJ.txt", fstream::in | fstream::out | fstream::app);
    Point pt2;
    cout << pt2;
    fs >> pt2;
    pt2.info();
    fs.close();
    cout << pt2 << endl;

    return 0;
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

bool writeObjectToFile(const string path, Point &pt)
{

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

vector<Point> readObjectToFile(const string path)
{
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
        // r_file.read((char *)&pt, sizeof(Point)) // il metodo ritorna un bool
        //  se c'e` un dato nelliterazione, ritorna true
        //  altrimenti ritorna false
        while (r_file.read((char *)&pt, sizeof(Point)))
        {
            lst.push_back(pt);
        }
        return lst;
    }
    return lst;
}

void fstreamLesson(string path = "___TEST.txt", bool is_read_mode = true)
{
    string messages, temp_message;
    fstream fileManager;
    fileManager.open(path, fstream::in | fstream::out | fstream::app);

    if (fileManager.is_open())
    {
        if (!is_read_mode)
        {
            cout << "\n\nFile is open!\n\n";
            fileManager << "hello\n";
            fileManager.close();
        }
        else
        {
            cout << "Read mode\n\n";
            while (!fileManager.eof()) // 'object.eof()' ritorna true se e` la fine del file
            {
                fileManager >> temp_message;
                cout << "  =  " << temp_message << endl;
                messages += (temp_message + "\n");
            }
            cout << messages;
        }
    }
    else
    {
        cout << "\n\nError with opening file";
    }
}

/*
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
*/
