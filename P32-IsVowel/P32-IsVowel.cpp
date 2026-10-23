#include <iostream>
#include <string>
using namespace std;

char ReadChar(string message)
{
    char C = ' ';
    cout << message;
    cin >> C;
    return C;
}

bool IsVowel(char c)
{
    c = tolower(c);
    return (c == 'a' || c == 'e' || c == 'o' || c == 'u' || c == 'i');
}

int main()
{
    char c = ReadChar("\nEnter a char: ");
    if (IsVowel(c))
        cout << "Vowel\n";
    else
        cout << "Not Vowel\n";
}