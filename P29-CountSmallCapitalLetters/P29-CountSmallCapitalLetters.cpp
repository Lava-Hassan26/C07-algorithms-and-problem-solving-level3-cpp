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

int CountSmallLetters(string text)
{
    int counter = 0;
    for (int i = 0; i < text.length(); i++)
        if (islower(text[i]))
            counter++;
    return counter;
}

int CountCapitalLetters(string text)
{
    int counter = 0;
    for (int i = 0; i < text.length(); i++)
        if (isupper(text[i]))
            counter++;
    return counter;
}

int main()
{
    string text = ReadString("Enter the text: ");

    cout << "All Letters Count: " << text.length() << endl;
    cout << "Capital Letters Count: " << CountCapitalLetters(text) << endl;
    cout << "Small Letters Count: " << CountSmallLetters(text) << endl;
}