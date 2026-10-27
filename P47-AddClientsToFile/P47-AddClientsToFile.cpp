#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

const string clientsFileName = "Clients.txt";
const string delim = "#//#";

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
    getline(cin >> ws, text);
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

string ConvertRecordToLine(stClient client, string delim)
{
    string line = "";
    line += client.accountNumber + delim;
    line += client.pinCode + delim;
    line += client.fullName + delim;
    line += client.phoneNo + delim;
    line += to_string(client.accountBalance);
    return line;
}

void AddClientToFile(stClient client, string fileName, string delim)
{
    fstream myFile;
    myFile.open(fileName, ios::out | ios::app);

    if (myFile.is_open())
    {
        string line = ConvertRecordToLine(client, delim);
        myFile << line << endl;
        myFile.close();
    }
}

void AddNewClient()
{
    stClient client = ReadClientInfo();
    AddClientToFile(client, clientsFileName, delim);
}

void AddClients()
{
    char addMore = 'y';
    while (tolower(addMore) == 'y')
    {
        system("cls");
        cout << "\n\nAdding New Client...\n";
        AddNewClient();
        cout << "\n\nClient added successfully\n";
        cout << "Do you want to add more client [Y/N]? ";
        cin >> addMore;
    }

}

int main()
{
    AddClients();

    return 0;
}