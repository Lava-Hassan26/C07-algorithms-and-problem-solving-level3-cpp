#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct stClient
{
    string accountNumber = "";
    string pinCode = "";
    string fullName = "";
    string phoneNo = "";
    float accountBalance = 0.0;
};

string ReadString(string message)
{
    string text = "";
    cout << message;
    getline(cin, text);
    return text;
}

int ReadNumber(string message)
{
    int number = 0;
    cout << message;
    cin >> number;

    while (cin.fail())
    {
        cin.clear(); // resets the error state
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        cout << "INVALIDE! Enter a valide number: ";
        cin >> number;
    }
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return number;
}

stClient ReadClientInfo()
{
    stClient client;
    client.accountNumber = ReadString("\nEnter Account Number: ");
    client.pinCode = ReadString("\nEnter Pin Code: ");
    client.fullName = ReadString("\nEnter Full Name: ");
    client.phoneNo = ReadString("\nEnter Phone No: ");
    client.accountBalance = ReadNumber("\nEnter Account Balance: ");

    return client;
}

string ConvertRecordToLine(stClient client, string delim = "#//#")
{
    string line = "";
    line += client.accountNumber + delim;
    line += client.pinCode + delim;
    line += client.fullName + delim;
    line += client.phoneNo + delim;
    line += to_string(client.accountBalance);
    return line;
}

int main()
{
    stClient client = ReadClientInfo();

    cout << "\n\nClient info in one line: " << ConvertRecordToLine(client) << "\n\n";
}