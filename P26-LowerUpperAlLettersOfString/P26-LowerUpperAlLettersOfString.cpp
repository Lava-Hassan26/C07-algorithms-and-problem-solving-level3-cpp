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

string LowerAllLetters(string text)
{
    for (int i = 0; i < text.length(); i++)
      text[i] = tolower(text[i]);
    return text;
}

string UpperAllLetters(string text)
{
    for (int i = 0; i < text.length(); i++)
        text[i] = toupper(text[i]);
    return text;
}

int main()
{
    string text = ReadString("Enter a text: ");
    cout << LowerAllLetters(text) << endl;
    cout << UpperAllLetters(text) << endl;
}