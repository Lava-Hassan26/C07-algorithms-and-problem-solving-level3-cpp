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

string ReplaceWords(string text, string currentWord, string replacementWord, string delim = " ")
{
    vector<string> vWords = SplitString(text, delim);

    for (string& word : vWords)
        if (word == currentWord)
            word = replacementWord;
   
    return JoinString(vWords, delim);
}

int main()
{
    string text = ReadString("\n\nEnter the text: ");
    string currentWord = ReadString("\nEnter the word to replace: ");
    string replacementWord = ReadString("\nEnter the new word: "); 

    cout << "\n\nText after replacement:" << ReplaceWords(text, currentWord, replacementWord, " ") << "\n\n";

    system("pause");
}