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

string TrimLeft(string text)
{
    for (short i = 0; i < text.length(); i++)
        if (text[i] != ' ')
            return text.erase(0, i);
}

string TrimRight(string text)
{
    for (short i = text.length() - 1; i >= 0; i--)
        if (text[i] != ' ')
            return text.erase(i + 1, text.length() - 1 - i);
    
}

string Trim(string text)
{
    return TrimRight(TrimLeft(text));
}

int main()
{
    string text = ReadString("Enter the text: ");
    
    cout << "Trim Left: " << TrimLeft(text) << endl;
    cout << "Trim Right: " << TrimRight(text) << " test" << endl;
    cout << "Trim: " << Trim(text) << " test" << "\n\n";

    system("pause");
}