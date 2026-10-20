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

bool IsPalindromeMatrix(int matrix[3][3], short rows, short cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols / 2; j++)
        {
            if (matrix[i][j] != matrix[i][cols - j - 1])
                return false;
        }
    }
    return true;;
}

int main()
{
    srand((unsigned)time(NULL));

    int matrix[3][3] = { {1,2,1},{2,2,2},{3,2,3} };
    PrintMatrix(matrix, 3, 3);

    if (IsPalindromeMatrix(matrix, 3, 3))
        cout << "It is palindrome matrix\n\n";
    else
        cout << "It is not palindrome matrix\n\n";
    system("pause");
}