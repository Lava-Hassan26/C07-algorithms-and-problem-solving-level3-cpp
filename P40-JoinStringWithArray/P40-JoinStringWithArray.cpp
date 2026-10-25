#include <iostream>
#include <vector>
#include <string>

using namespace std;

string JoinString(vector<string>& vWords, string delim = " ")
{
    string text = "";
    for (string& word : vWords)
        text += word + delim;

    return text = text.substr(0, text.length() - delim.length());
}

string JoinString(string arrWords[], short length, string delim = " ")
{
    string text = "";
    for (short i = 0; i <= length; i++)
        text += arrWords[i] + delim;

    return text = text.substr(0, text.length() - delim.length());
}

int main()
{
    vector<string> vWords = { "Lava","Hassan","Syrian","Software","Developer" };
    string text = JoinString(vWords, "#//#");

    cout << "\n\nVector after join with #//# delim: " << text << "\n\n";

    string arrWords[] = { "Lava","Hassan","Syrian","Software","Developer" };
    text = JoinString(arrWords, arrWords->length(), "#//#");

    cout << "\n\nArray after join with #//# delim: " << text << "\n\n";

    system("pause");
}