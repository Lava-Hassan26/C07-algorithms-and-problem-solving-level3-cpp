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

void PrintFirstLetterOfEachWord(string text)
{
    bool isFirstLetter = true;
    for (int i = 0; i < text.length(); i++)
    {
        if (text[i] != ' ' && isFirstLetter == true)
        {
            cout << text[i] << endl;
        }
        if (text[i] == ' ')
            isFirstLetter = true;
        else
            isFirstLetter = false;
    }
}

int main()
{
    string text = ReadString("Enter a text: ");
    PrintFirstLetterOfEachWord(text);

}