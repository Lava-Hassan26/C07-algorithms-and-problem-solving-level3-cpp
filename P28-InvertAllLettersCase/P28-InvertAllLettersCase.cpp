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

char InvertLetterCase(char C)
{
    return isupper(C) ? tolower(C) : toupper(C);
}

string InvertAllLettersCase(string text)
{
    for (int i = 0; i < text.length(); i++)
        text[i] = InvertLetterCase(text[i]);
    return text;
}

int main()
{
    string text = ReadString("Enter the text: ");

    cout << InvertAllLettersCase(text) << endl;
}