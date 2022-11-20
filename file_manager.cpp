#include <fstream>
#include <iostream>
#include <string>
using namespace std;

void write(string file, string data)
{
    ofstream input_file;
    input_file.open(file);
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

int main()
{
    cout << read("file.cpp") << endl;
    return 0;
}