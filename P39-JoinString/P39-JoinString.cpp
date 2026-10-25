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

int main()
{
    vector<string> vWords = { "Lava","Hassan","Syrian","Software","Developer" };
    string text = JoinString(vWords, "#//#");

    cout << "\n\nVector after join with #//# delim: " << text << "\n\n";

    system("pause");
}