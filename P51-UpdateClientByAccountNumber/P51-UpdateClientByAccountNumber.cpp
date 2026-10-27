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
    double accountBalance = 0.0;
    bool isMarkedForDelete = false;
};

string ReadInputString(string message)
{
    string text = "";
    cout << message;
    getline(cin >> ws, text);
    return text;
}

double ReadInputNumber(string message)
{
    double number = 0;
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

string ReadAccountNumberInput()
{
    string accountNumber = "";
    accountNumber = ReadInputString("Enter the account number: ");
    return accountNumber;
}

vector<string> SplitStringByDelimiter(string inputText, string delim = " ")
{
    vector<string> vWords;
    string word = "";
    short delimiterPosition = 0;
    delimiterPosition = inputText.find(delim);

    while ((delimiterPosition) != std::string::npos)
    {
        word = inputText.substr(0, delimiterPosition);
        if (word != "")
            vWords.push_back(word);
        inputText.erase(0, delimiterPosition + delim.length());
        delimiterPosition = inputText.find(delim);
    }
    if (inputText != "")
        vWords.push_back(inputText);
    return vWords;
}

string ConvertClientRecordToDataLine(stClient client, string delim)
{
    string line = "";
    line += client.accountNumber + delim;
    line += client.pinCode + delim;
    line += client.fullName + delim;
    line += client.phoneNumber + delim;
    line += to_string(client.accountBalance);
    return line;
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

void SaveAllClientsToFile(vector<stClient>& vClients, string fileName, string delim)
{
    fstream clientsFile;
    clientsFile.open(fileName, ios::out);

    if (clientsFile.is_open())
    {
        string currentLline = "";
        for (stClient& client : vClients)
        {
            if (!client.isMarkedForDelete)
            {
                currentLline = ConvertClientRecordToDataLine(client, delim);
                clientsFile << currentLline << endl;
            }
        }
        clientsFile.close();
    }
}

vector<stClient> LoadAllClientsFromFile(string fileName, string delim)
{
    vector<stClient> vClients;
    fstream clientsFile;
    clientsFile.open(fileName, ios::in);

    if (clientsFile.is_open())
    {
        stClient client;
        string currentLline = "";
        while (getline(clientsFile, currentLline))
        {
            client = ConvertDataLineToClientRecord(currentLline, delim);
            vClients.push_back(client);
        }
        clientsFile.close();
    }
    return vClients;
}

void PrintClientCardDetails(const stClient& client)
{
    cout << "\n***************************************";
    cout << "\nAccount Number : " << client.accountNumber;
    cout << "\nPin Code       : " << client.pinCode;
    cout << "\nFull Name      : " << client.fullName;
    cout << "\nPhone Number   : " << client.phoneNumber;
    cout << "\nAccount Balance: " << client.accountBalance;
    cout << "\n***************************************\n\n";
}

bool IsClientExistByAccountNumber(string accountNumber, vector<stClient>& vClients, stClient& client)
{
    for (stClient& c : vClients)
    {
        if (c.accountNumber == accountNumber)
        {
            client = c;
            return true;
        }
    }
    return false;
}

stClient ReadClientInfoByAccountNumber(string accountNumber)
{
    stClient client;
    client.accountNumber = accountNumber;
    client.pinCode = ReadInputString("\nEnter Pin Code: ");
    client.fullName = ReadInputString("\nEnter Full Name: ");
    client.phoneNumber = ReadInputString("\nEnter Phone No: ");
    client.accountBalance = ReadInputNumber("\nEnter Account Balance: ");

    return client;
}

void UpdateClientByAccountNumberInteractive(string accountNumber)
{
    vector<stClient> vClients = LoadAllClientsFromFile(clientsFileName, delim);
    stClient client;
    char userChoice = 'y';
    if (IsClientExistByAccountNumber(accountNumber, vClients, client))
    {
        PrintClientCardDetails(client);
        cout << "Are you sure to update the client [Y/N]? ";
        cin >> userChoice;
        if (tolower(userChoice) == 'y')
        {
            for (stClient& c : vClients)
            {
                if (c.accountNumber == accountNumber)
                {
                    c = ReadClientInfoByAccountNumber(accountNumber);
                    break;
                }
            }
            SaveAllClientsToFile(vClients, clientsFileName, delim);
            cout << "\nClient Updated successfully\n\n";
        }
        else
            cout << "\nUpdating Cancelled\n\n";
    }
    else
        cout << "\nClient with account number " << accountNumber << " not found!\n\n";
}

int main()
{
    UpdateClientByAccountNumberInteractive(ReadAccountNumberInput());

    return 0;
}