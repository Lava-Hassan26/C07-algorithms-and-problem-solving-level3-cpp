#include <iostream>
#include <string>
using namespace std;

string ReadString(string message)
{
    string text = "";
    cout << message;
    getline(cin, text);
    return text;
}

bool IsVowel(char c)
{
    c = tolower(c);
    return (c == 'a' || c == 'e' || c == 'o' || c == 'u' || c == 'i');
}

void PrintAllVowels(string text)
{
    cout << "Vowels in text: ";
    int counter = 0;
    for (int i = 0; i < text.length(); i++)
        if (IsVowel(text[i]))
            cout << text[i] << "  ";
}

int main()
{
    string text = ReadString("Enter the text: ");

    PrintAllVowels(text);
    return 0;
}