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

string LowerFirstLetterOfEachWord(string text)
{
    bool isFirstLetter = true;
    for (int i = 0; i < text.length(); i++)
    {
        if (text[i] != ' ' && isFirstLetter == true)
            text[i] = tolower(text[i]);

        isFirstLetter = (text[i] == ' ') ? true : false;
    }
    return text;
}

int main()
{
    string text = ReadString("Enter a text: ");
    text = LowerFirstLetterOfEachWord(text);
    cout << text << endl;
}