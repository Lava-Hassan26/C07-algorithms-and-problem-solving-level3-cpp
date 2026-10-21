#include <iostream>

using namespace std;

void FibonacciSeries(int Number, int Prev2, int Prev1)
{
	if (Prev2 == 0)
		cout << "1 ";
	int FiboNumber = 0;

	if (Number > 1)
	{
		FiboNumber = Prev1 + Prev2;
		Prev2 = Prev1;
		Prev1 = FiboNumber;
		cout << FiboNumber << " ";
		FibonacciSeries(--Number, Prev2, Prev1);		
	}
}

int main()
{
	FibonacciSeries(10, 0, 1);
	cout << "\n\n";
	system("Pause");
}