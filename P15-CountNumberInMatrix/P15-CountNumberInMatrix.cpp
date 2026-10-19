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

int CountNumberInMatrix(int matrix[3][3], short rows, short cols, int numberToCount)
{
    short counter = 0;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (matrix[i][j] == numberToCount)
                counter++;
        }
    }
    return counter;
}

int main()
{
    srand((unsigned)time(NULL));

    int matrix[3][3];
    FillMatrixByRandomNumbers(matrix, 3, 3);
    PrintMatrix(matrix, 3, 3);
    int numberToCount = ReadNumber("Enter a number to count: ");
   
    cout << "Number " << numberToCount << " Count in Matrix is: " << CountNumberInMatrix(matrix, 3, 3, numberToCount) << "\n\n";
    system("pause");
}