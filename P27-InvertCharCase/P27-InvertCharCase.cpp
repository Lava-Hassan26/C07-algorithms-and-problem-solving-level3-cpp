#include <iostream>
#include <string>
using namespace std;

char InvertLetterCase(char C)
{
    return isupper(C) ? tolower(C) : toupper(C);
}

int main()
{
    cout << InvertLetterCase('a') << endl;
}