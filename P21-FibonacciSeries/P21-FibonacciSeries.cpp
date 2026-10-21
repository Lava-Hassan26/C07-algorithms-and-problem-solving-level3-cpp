#include <iostream>

using namespace std;

void FibonacciSeries(int Number)
{
	int Prev2 = 0;
	int Prev1 = 1;
	int FiboNumber = 1;
	cout << "1 ";
	while (Number > 1)
	{
		FiboNumber = Prev2 + Prev1;
		cout << FiboNumber << " ";
		Prev2 = Prev1;
		Prev1 = FiboNumber;
		Number--;
	}
	cout << "\n\n";
}

int main()
{
	FibonacciSeries(10);

	system("pause");
}