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

char ReadChar(string message)
{
    char C = ' ';
    cout << message;
    cin >> C;
    return C;
}

int CountLetter(string text, char letterToCount)
{
    int counter = 0;
    for (int i = 0; i < text.length(); i++)
        if (text[i]==letterToCount)
            counter++;
    return counter;
}

int main()
{
    string text = ReadString("Enter the text: ");
    char letterToCount = ReadChar("\nEnter a letter to count: ");
 
    cout << "\nLetter '" << letterToCount << "' Count= " << CountLetter(text, letterToCount) << endl;
}