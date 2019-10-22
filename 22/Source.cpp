#include <iostream>
#include "Header.h"

using namespace std;

unsigned indication();

int main()
{
	cout << "Gavryliuk Oksana\n" << "Calculation by an array\n";

	const int N = 100;
	int M = 0;
	int arr[N];
	bool ok = 1;

	do
	{
		switch (indication())
		{
			case 1: 
			{
				try {ok = file_array(arr, N, M); }
				catch (int)
				{
					cout << "<<<INCORRECT FILE>>>" << endl;
					cout << "Try again" << endl;
					cin.clear();
					cin.sync();
					ok = 0;
				}
				catch (char)
				{
					cout << "<<<RANGE CHECK ERROR>>>" << endl;
					cout << "Try again" << endl;
					cin.clear();
					cin.sync();
					ok = 0;
				}
			}; break;
			case 2:ok = entered_array(arr, N, M); break;
			case 9:cout << "End of work" << endl; system("pause"); return 0;
		}
	} while (!ok);

		edit_array(arr, N, M);

	system("pause");
	return 0;
}
unsigned indication()
{
	unsigned a;
	do
	{
		cout << "Enter 1 to fill the array with numbers from a file\n" << "Enter 2 to enter number with keyboard\n" << "Enter 9 to quit\n";
		cout << "Enter your number of choice(1, 2, or 9):" << endl;
		cin >> a;
	} while (a != 1 && a != 2 && a != 9);
	return a;
}