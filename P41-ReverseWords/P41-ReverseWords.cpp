#include <iostream>
#include <vector>
#include <string>

using namespace std;

string ReadString(string message)
{
    string text = "";
    cout << message;
    getline(cin, text);
    return text;
}

vector<string> SplitString(string text, string delim = " ")
{
    vector<string> vWords;
    string word = "";
    short pos = 0;
    pos = text.find(delim);

    while ((pos) != std::string::npos)
    {
        word = text.substr(0, pos);
        if (word != "")
            vWords.push_back(word);
        text.erase(0, pos + delim.length());
        pos = text.find(delim);
    }
    if (text != "")
        vWords.push_back(text);
    return vWords;
}

string JoinString(vector<string>& vWords, string delim = " ")
{
    string text = "";
    for (string& word : vWords)
        text += word + delim;

    return text = text.substr(0, text.length() - delim.length());
}

string ReverseWords(string text, string delim = " ")
{
    vector<string> vWords = SplitString(text, delim);
    vector<string> vReversedWords;

    for (short i = 0; i < vWords.size(); i++)
        vReversedWords.push_back(vWords[vWords.size() - i - 1]);

    return JoinString(vReversedWords, delim);
}

int main()
{
    string text = ReadString("\n\nEnter the text: ");
    cout << "\n\nReversed Words: " << ReverseWords(text, " ") << "\n\n";
    system("pause");
}