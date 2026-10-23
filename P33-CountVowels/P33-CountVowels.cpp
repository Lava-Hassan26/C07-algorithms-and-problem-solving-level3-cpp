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

bool IsVowel(char c)
{
    c = tolower(c);
    return (c == 'a' || c == 'e' || c == 'o' || c == 'u' || c == 'i');
}

int CountVowels(string text)
{
    int counter = 0;
    for (int i = 0; i < text.length(); i++)
        if (IsVowel(text[i]))
            counter++;
    return counter;
}

int main()
{
    string text = ReadString("Enter the text: ");
    
    cout << "\nNumber of vowels in the text= " << CountVowels(text) << endl;
    return 0;
}