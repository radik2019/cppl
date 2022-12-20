
#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

void foo(){
    while (true)
    {
        cout<< this_thread::get_id() << " hello my world\n";
        this_thread::sleep_for(chrono::milliseconds(334));
        
    }
}
void foo2(){
    while (true)
    {
        this_thread::sleep_for(chrono::milliseconds(509));
        cout<< this_thread::get_id() << " ciao from foo2\n";
    }
}

int main(){
    thread th(foo);
    thread th2(foo2);

    int a;
    // cin >> a;
    
    cout << cin.get();
    cout << "FINE\n";
    return 0;
}


