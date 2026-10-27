#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

const string clientsFileName = "Clients.txt";
const string delim = "#//#";

struct stClient
{
    string accountNumber = "";
    string pinCode = "";
    string fullName = "";
    string phoneNumber = "";
    float accountBalance = 0.0;
};

string ReadInputString(string message)
{
    string text = "";
    cout << message;
    getline(cin >> ws, text);
    return text;
}

string ReadAccountNumberInput()
{
    string accountNumber = "";
    accountNumber = ReadInputString("Enter the account number: ");
    return accountNumber;
}

vector<string> SplitStringByDelimiter(string text, string delim = " ")
{
    vector<string> vWords;
    string word = "";
    short delimiterPosition = 0;
    delimiterPosition = text.find(delim);

    while ((delimiterPosition) != std::string::npos)
    {
        word = text.substr(0, delimiterPosition);
        if (word != "")
            vWords.push_back(word);
        text.erase(0, delimiterPosition + delim.length());
        delimiterPosition = text.find(delim);
    }
    if (text != "")
        vWords.push_back(text);
    return vWords;
}

stClient ConvertDataLineToClientRecord(string lineData, string delim)
{
    vector<string> vClient = SplitStringByDelimiter(lineData, delim);
    stClient client;
    client.accountNumber = vClient[0];
    client.pinCode = vClient[1];
    client.fullName = vClient[2];
    client.phoneNumber = vClient[3];
    client.accountBalance = stof(vClient[4]);

    return client;
}

vector<stClient> LoadAllClientsFromFile(string fileName, string delim)
{
    vector<stClient> vClients;
    fstream myFile;
    myFile.open(fileName, ios::in);

    if (myFile.is_open())
    {
        stClient client;
        string line = "";
        while (getline(myFile, line))
        {
            client = ConvertDataLineToClientRecord(line, delim);
            vClients.push_back(client);
        }
        myFile.close();
    }
    return vClients;
}

void PrintClientCardDetails(stClient client)
{
    cout << "\n***************************************";
    cout << "\nAccount Number : " << client.accountNumber;
    cout << "\nPin Code       : " << client.pinCode;
    cout << "\nFull Name      : " << client.fullName;
    cout << "\nPhone Number   : " << client.phoneNumber;
    cout << "\nAccount Balance: " << client.accountBalance;
    cout << "\n***************************************\n\n";
}

bool IsClientExistByAccountNumber(vector<stClient> vClients,stClient& foundClient, string accountNumber)
{
    for (stClient& client : vClients)
    {
        if (client.accountNumber == accountNumber)
        {
            foundClient = client;
            return true;
        }
    }
    return false;
}

void ShowClientDetailsByAccountNumber(string accountNumber)
{
    vector<stClient> vClients = LoadAllClientsFromFile(clientsFileName, delim);
    stClient client;
    if (IsClientExistByAccountNumber(vClients, client, accountNumber))
    {
        PrintClientCardDetails(client);
    }
    else
    {
        cout << "\nClient with account number " << accountNumber << " not found!\n\n";
    }
}

int main()
{
    ShowClientDetailsByAccountNumber(ReadAccountNumberInput());

    return 0;
}