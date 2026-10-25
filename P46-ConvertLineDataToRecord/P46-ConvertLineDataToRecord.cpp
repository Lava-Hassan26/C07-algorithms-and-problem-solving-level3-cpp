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

vector<string> SplitString(string text, string delim = " ")
{
    vector<string> vWords;
    string word = "";
    short pos = 0;
    pos = text.find(delim);

    while ((pos) != std::string::npos)
    {
        word = text.substr(0, pos);
        if (word != "")
            vWords.push_back(word);
        text.erase(0, pos + delim.length());
        pos = text.find(delim);
    }
    if (text != "")
        vWords.push_back(text);
    return vWords;
}

stClient ConvertLineDataToRecord(string lineData, string delim = "#//#")
{
    vector<string> vClient = SplitString(lineData, delim);
    stClient client;   
    client.accountNumber = vClient[0];
    client.pinCode = vClient[1];
    client.fullName = vClient[2];
    client.phoneNo = vClient[3];
    client.accountBalance = stof(vClient[4]);

    return client;
}

void PrintClientInfo(stClient client)
{
    cout << "\n***************************************";
    cout << "\nAccount Number : " << client.accountNumber;
    cout << "\nPin Code       : " << client.pinCode;
    cout << "\nFull Name      : " << client.fullName;
    cout << "\nPhone Number   : " << client.phoneNo;
    cout << "\nAccount Balance: " << client.accountBalance;
    cout << "\n***************************************\n\n";
}

int main()
{
    stClient client = ConvertLineDataToRecord("A150#//#1234#//#Lava Hassan#//#09876543#//#50000");
    PrintClientInfo(client);
    return 0;
}