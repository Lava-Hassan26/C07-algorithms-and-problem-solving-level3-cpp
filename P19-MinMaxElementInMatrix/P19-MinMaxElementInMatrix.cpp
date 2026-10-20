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
            matrix[i][j] = GetRandomNumber(1, 100);
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

int MaxElementInMatrix(int matrix[3][3], short rows, short cols)
{
    int maxElement = matrix[0][0];
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (matrix[i][j] > maxElement)
                maxElement = matrix[i][j];
        }
    }
    return maxElement;
}

int MinElementInMatrix(int matrix[3][3], short rows, short cols)
{
    int minElement = matrix[0][0];
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (matrix[i][j] < minElement)
                minElement = matrix[i][j];
        }
    }
    return minElement;
}

int main()
{
    srand((unsigned)time(NULL));
    int matrix[3][3];
    FillMatrixByRandomNumbers(matrix, 3, 3);
    PrintMatrix(matrix, 3, 3);

    int maxElement = MaxElementInMatrix(matrix, 3, 3);
    cout << "Min Element in Matris= " << maxElement << "\n\n";

    int minElement = MinElementInMatrix(matrix, 3, 3);
    cout << "Min Element in Matris= " << minElement << "\n\n";

    system("pause");
}