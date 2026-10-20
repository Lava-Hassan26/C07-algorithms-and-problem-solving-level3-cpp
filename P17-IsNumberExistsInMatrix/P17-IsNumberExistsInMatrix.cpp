#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <iomanip>

using namespace std;

int GetRandomNumber(int from, int to)
{
    int randNumber = rand() % (to - from + 1) + from;
    return randNumber;
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

void FillMatrixByRandomNumbers(int matrix[3][3], short rows, short cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            matrix[i][j] = GetRandomNumber(1, 10);
        }
    }
}

void PrintMatrix(int matrix[3][3], short rows, short cols)
{
    cout << "\nThe following are the matrix elements:\n";
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << left << setw(5) << matrix[i][j];
        }
        cout << endl;
    }
    cout << "\n\n";
}

bool IsNumberExistsInMatrix(int matrix[3][3], short rows, short cols, int numberToCheck)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (matrix[i][j] == numberToCheck)
                return true;
        }
    }
    return false;;
}

int main()
{
    srand((unsigned)time(NULL));

    int matrix[3][3];
    FillMatrixByRandomNumbers(matrix, 3, 3);
    PrintMatrix(matrix, 3, 3);
    int numberToCheck = ReadNumber("Enter a number to check: ");

    if (IsNumberExistsInMatrix(matrix, 3, 3, numberToCheck))
        cout << "Number " << numberToCheck << " Is Exists in Matrix\n\n";
    else
        cout << "Number " << numberToCheck << " Is Not Exists in Matrix\n\n";
    system("pause");
}