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

int CountWords(string text, string delim = " ")
{
    string word = "";
    short pos = 0;
    short counter = 0;

    pos = text.find(delim);
    while ((pos) != std::string::npos)
    {
        word = text.substr(0, pos);
        if (word != "")
            counter++;
        text.erase(0, pos + delim.length());
        pos = text.find(delim);
    }
    if (text != "")
        counter++;
    return counter;
}

int main()
{
    string text = ReadString("Enter the text: ");
    cout << "Words Count= " << CountWords(text) << "\n\n";

    system("pause");
}