#include <iostream>
#include <vector>
#include <string>
#include <cctype>

using namespace std;

string ReadString(string message)
{
    string text = "";
    cout << message;
    getline(cin, text);
    return text;
}

string RemovePunctuations(string text)
{
    string newText = "";

    for (short i = 0; i < text.length(); i++)
        if (!ispunct(text[i]))
            newText += text[i];

    return newText;
}

int main()
{
    string text = ReadString("\n\nEnter the text: ");
    
    cout << "\n\nText after removing punctuations: " << RemovePunctuations(text) << "\n\n";

    system("pause");
}