#ifndef _INF_INT_H_
#define _INF_INT_H_

#include <iostream>

using namespace std;

class inf_int{
private:
    char *digits;
    unsigned int length;
    bool thesign; // Positive is true, Negative is false

    void Add(int num, unsigned int index); // Function for Multiply Logic
    void Add(char num, unsigned int index); // public members
    void Sub(char num, unsigned int index); // void inf_int::Add(~~~) <-> void Add(~~~)

public:
    inf_int();                // Assign 0 as Default Value
    explicit inf_int(int);
    explicit inf_int(const char *);
    inf_int(const inf_int &); // Copy Constructor
    ~inf_int();               // Destructor

    inf_int &operator=(const inf_int &); // Assignment Operator

    friend bool operator==(const inf_int &, const inf_int &);
    friend bool operator!=(const inf_int &, const inf_int &);
    friend bool operator>(const inf_int &, const inf_int &);
    friend bool operator<(const inf_int &, const inf_int &);

    friend inf_int operator+(const inf_int &, const inf_int &);
    friend inf_int operator-(const inf_int &, const inf_int &);
    friend inf_int operator*(const inf_int &, const inf_int &);
    friend inf_int operator/(const inf_int &, const inf_int &);
    friend inf_int operator%(const inf_int &, const inf_int &);
    friend ostream &operator<<(ostream &, const inf_int &);

    inf_int subInfInt(unsigned int startIndex, unsigned int endIndex);
    inf_int pow(unsigned int exponent);

    string getResultChar();
};

#endif