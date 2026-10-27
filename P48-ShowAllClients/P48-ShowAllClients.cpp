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

stClient ConvertDataLineToClientRecord(string lineData, string delim = "#//#")
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
    fstream clientsFile;
    clientsFile.open(fileName, ios::in);

    if (clientsFile.is_open())
    { 
        stClient client;
        string line = "";
        while (getline(clientsFile, line))
        {
            client = ConvertDataLineToClientRecord(line, delim);
            vClients.push_back(client);
        }
        clientsFile.close();
    }
    return vClients;
}

void PrintClientsInfoHeader()
{
    cout << "\n__________________________________________________________________________________________________________\n\n";
    cout << "| " << left << setw(20) << "Account Number";
    cout << "| " << left << setw(15) << "Pin Code";
    cout << "| " << left << setw(25) << "Client Name";
    cout << "| " << left << setw(20) << "Phone Number";
    cout << "| " << left << setw(15) << "Account Balance";
    cout << "\n__________________________________________________________________________________________________________\n";
}

void ShowClientsInfo()
{
    vector<stClient> vClients = LoadAllClientsFromFile(clientsFileName, delim);
    cout << "\n\n\t\t\t\t\tList Of (" << vClients.size() << ") Clients\n";
    PrintClientsInfoHeader();
   
    for (stClient& client : vClients)
    {
        cout << "| " << left << setw(20) << client.accountNumber;
        cout << "| " << left << setw(15) << client.pinCode;
        cout << "| " << left << setw(25) << client.fullName;
        cout << "| " << left << setw(20) << client.phoneNumber;
        cout << "| " << left << setw(15) << client.accountBalance << endl;
    }
    cout << "__________________________________________________________________________________________________________\n\n";
}

int main()
{
    ShowClientsInfo();
    return 0;
}