#include <bits/stdc++.h>

using namespace std;

class BigNum
{
    string digits;

public:
     
    BigNum(unsigned long long n = 0);
    BigNum(string &);
    BigNum(const char *);
    BigNum(BigNum &);

     
    friend void divide_by_2(BigNum &a);
    friend bool Null(const BigNum &);
    friend int Length(const BigNum &);
    int operator[](const int) const;

     

     
    BigNum &operator=(const BigNum &);

     
    BigNum &operator++();
    BigNum operator++(int temp);
    BigNum &operator--();
    BigNum operator--(int temp);

     
    friend BigNum &operator+=(BigNum &, const BigNum &);
    friend BigNum operator+(const BigNum &, const BigNum &);
    friend BigNum operator-(const BigNum &, const BigNum &);
    friend BigNum &operator-=(BigNum &, const BigNum &);

     
    friend bool operator==(const BigNum &, const BigNum &);
    friend bool operator!=(const BigNum &, const BigNum &);

    friend bool operator>(const BigNum &, const BigNum &);
    friend bool operator>=(const BigNum &, const BigNum &);
    friend bool operator<(const BigNum &, const BigNum &);
    friend bool operator<=(const BigNum &, const BigNum &);

    friend ostream &operator<<(ostream &, const BigNum &);
    friend istream &operator>>(istream &, BigNum &);
 
};
