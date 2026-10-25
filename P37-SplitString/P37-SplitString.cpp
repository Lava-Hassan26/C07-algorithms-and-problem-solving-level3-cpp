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

void PrintVectorOfWords(vector<string>& vWords)
{
    for (string& word : vWords)
        cout << word << endl;
    cout << "\n\n";
}

int main()
{
    string text = ReadString("Enter the text: ");
    vector<string> vWords = SplitString(text, " ");

    PrintVectorOfWords(vWords);

    system("pause");
}