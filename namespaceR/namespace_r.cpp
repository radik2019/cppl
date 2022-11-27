#include "../r_header.h"


namespace z{
    namespace x
    {
        void foo(){
            cout << "\n\nFunction x\n\n";
        }
    }

    namespace y
    {
        void foo(){
            cout << "\n\nFunction y\n\n";
        }

    }
}

int main()

{
    using namespace z;
    y::foo();
    z::x::foo();
    return 0;
}
