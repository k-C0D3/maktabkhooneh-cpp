#include "BigNum.hpp"


BigNum::BigNum(string &s)
{
    digits = "";
    int n = s.size();
    for (int i = n - 1; i >= 0; i--)
    {
        if (!isdigit(s[i]))
            throw("ERROR");
        digits.push_back(s[i] - '0');
    }
}
BigNum::BigNum(unsigned long long nr)
{
    do
    {
        digits.push_back(nr % 10);
        nr /= 10;
    } while (nr);
}
BigNum::BigNum(const char *s)
{
    digits = "";
    for (int i = strlen(s) - 1; i >= 0; i--)
    {
        if (!isdigit(s[i]))
            throw("ERROR");
        digits.push_back(s[i] - '0');
    }
}
BigNum::BigNum(BigNum &a)
{
    digits = a.digits;
}

bool Null(const BigNum &a)
{
    if (a.digits.size() == 1 && a.digits[0] == 0)
        return true;
    return false;
}
int Length(const BigNum &a)
{
    return a.digits.size();
}
int BigNum::operator[](const int index) const
{
    if (digits.size() <= index || index < 0)
        throw("ERROR");
    return digits[index];
}
bool operator==(const BigNum &a, const BigNum &b)
{
    return a.digits == b.digits;
}
bool operator!=(const BigNum &a, const BigNum &b)
{
    return !(a == b);
}
bool operator<(const BigNum &a, const BigNum &b)
{
    int n = Length(a), m = Length(b);
    if (n != m)
        return n < m;
    while (n--)
        if (a.digits[n] != b.digits[n])
            return a.digits[n] < b.digits[n];
    return false;
}
bool operator>(const BigNum &a, const BigNum &b)
{
    return b < a;
}
bool operator>=(const BigNum &a, const BigNum &b)
{
    return !(a < b);
}
bool operator<=(const BigNum &a, const BigNum &b)
{
    return !(a > b);
}

BigNum &BigNum::operator=(const BigNum &a)
{
    digits = a.digits;
    return *this;
}

BigNum &BigNum::operator++()
{
    int i, n = digits.size();
    for (i = 0; i < n && digits[i] == 9; i++)
        digits[i] = 0;
    if (i == n)
        digits.push_back(1);
    else
        digits[i]++;
    return *this;
}
BigNum BigNum::operator++(int temp)
{
    BigNum aux;
    aux = *this;
    ++(*this);
    return aux;
}

BigNum &BigNum::operator--()
{
    if (digits[0] == 0 && digits.size() == 1)
        throw("UNDERFLOW");
    int i, n = digits.size();
    for (i = 0; digits[i] == 0 && i < n; i++)
        digits[i] = 9;
    digits[i]--;
    if (n > 1 && digits[n - 1] == 0)
        digits.pop_back();
    return *this;
}
BigNum BigNum::operator--(int temp)
{
    BigNum aux;
    aux = *this;
    --(*this);
    return aux;
}

BigNum &operator+=(BigNum &a, const BigNum &b)
{
    int t = 0, s, i;
    int n = Length(a), m = Length(b);
    if (m > n)
        a.digits.append(m - n, 0);
    n = Length(a);
    for (i = 0; i < n; i++)
    {
        if (i < m)
            s = (a.digits[i] + b.digits[i]) + t;
        else
            s = a.digits[i] + t;
        t = s / 10;
        a.digits[i] = (s % 10);
    }
    if (t)
        a.digits.push_back(t);
    return a;
}
BigNum operator+(const BigNum &a, const BigNum &b)
{
    BigNum temp;
    temp = a;
    temp += b;
    return temp;
}

BigNum &operator-=(BigNum &a, const BigNum &b)
{
    if (a < b)
        throw("UNDERFLOW");
    int n = Length(a), m = Length(b);
    int i, t = 0, s;
    for (i = 0; i < n; i++)
    {
        if (i < m)
            s = a.digits[i] - b.digits[i] + t;
        else
            s = a.digits[i] + t;
        if (s < 0)
            s += 10,
                t = -1;
        else
            t = 0;
        a.digits[i] = s;
    }
    while (n > 1 && a.digits[n - 1] == 0)
        a.digits.pop_back(),
            n--;
    return a;
}
BigNum operator-(const BigNum &a, const BigNum &b)
{
    BigNum temp;
    temp = a;
    temp -= b;
    return temp;
}
istream &operator>>(istream &in, BigNum &a)
{
    string s;
    in >> s;
    int n = s.size();
    for (int i = n - 1; i >= 0; i--)
    {
        if (!isdigit(s[i]))
            throw("INVALID NUMBER");
        a.digits[n - i - 1] = s[i];
    }
    return in;
}

ostream &operator<<(ostream &out, const BigNum &a)
{
    for (int i = a.digits.size() - 1; i >= 0; i--)
        cout << (short)a.digits[i];
    return cout;
}
