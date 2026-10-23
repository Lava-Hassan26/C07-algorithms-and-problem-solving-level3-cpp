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

void PrintEachWordInString(string text, string delim = " ")
{
    string word = "";
    short pos = 0;

    while ((pos = text.find(delim)) != std::string::npos)
    {
        word = text.substr(0, pos);

        if (word != "")
            cout << word << endl;

        text.erase(0, pos + delim.length());
    }
    if (text != "")
        cout << text << endl;
}

int main()
{
    string text = ReadString("Enter the text: ");

    PrintEachWordInString(text);
    return 0;
}