#include "BigNum.cpp"

int main()
{
    BigNum a("5421312354321321345313215");
    BigNum b("5421312354321321345313215");
    BigNum c;
    c = a + b;
    cout << "a: "<< a << " b: "<< b << " C:"<< c << endl;
    c -= "12125456413254";
    cout << "a: "<< a << " b: "<< b << " C:"<< c << endl;
    if (!(a > b || a < b))
    {
        cout << "a = b" << endl;
    }
    }
