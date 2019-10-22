#include <iostream>
#include <iomanip>
#include <fstream>
#include <stdexcept>
#include "Header.h"

using namespace std;

bool file_array(int arr[], const int N, int &M)
{
	ifstream fin("text.txt");

	if (!fin)
	{	
		throw 1;
		return 0;
	}
	else
	{
		int i = 0;
		int size = 0;
		fin.seekg(0, std::ios_base::end);
		size = fin.tellg();
		fin.seekg(0, std::ios_base::beg);

		if (size == 0)
		{
			cout << "File is empty!" << endl;
			cout << "Try again" << endl;
			fin.close();
			return 0;
		}
		
		while (!fin.eof())
		{
			if (M > N)
			{
				fin.close();
				throw 'a';
			}
			fin >> arr[i];
			M++;
			i++;
		}
		if (fin.eof())
			return 1;
		else return 0;
	}
}
bool entered_array(int arr[], const int N, int &M)
{
	int i;
	for (i = 0; i < N; ++i)
	{
		cout << "Enter arr[" << i << "] element of the array: " << endl;
		cin >> arr[i];
		if (!(cin.good()))
		{
			cout << endl;
			cout << "End of entering\n" << endl;
			cin.clear();
			cin.sync();
			break;
		}
	}
	if (i == 0)
	{
		cout << "Array is empty" << endl;
		cout << "Try again\n" << endl;
		return 0;
	}
	else
	{
		M = i;
		return 1;
	}
}
void edit_array(int arr[], const int N, int &M)
{
	if (M > 3)
	{
		int a = 0;
		int beg = -1, en = -1, k = 0, l = 0;
		bool ok = 1;
		int i = 1, j = 2;
		while (ok)
		{
			for (; i < M - 2; i++, j++)
				if (arr[i] == arr[j])
				{
					a = i;
					break;
				}
				else if (i == M - 3)
				{
					cout << "Absence of such sequence" << endl;
					ok = 0;
					break;
				}

			for (k = a, l = a - 1; k > 0; k--, l--)
				if (arr[k] >= arr[l])
					break;

			beg = -1;

			if (k != a)
				beg = k;

			if (beg != -1)
			{
				en = -1;
				k = a + 1;
				l = a + 2;

				for (; k < M - 2; k++, l++)
					if (arr[k] != arr[l])
						break;

				a = k;

				for (; k < M - 1; k++, l++)
					if (arr[k] >= arr[l])
						break;

				en = -1;
				if (k != a)
					en = k;

				if (en != -1)
				{
					cout << "Sequence: " << endl;
					for (int i = beg; i <= en; i++)
						cout << arr[i] << ' ';
					cout << endl;
					break;
				}
				else
					i = a + 1; j = a + 2;
			}
			else
				i = a + 1; j = a + 2;

			if ((beg == -1 || en == -1) && (i == M - 2 || i == M - 1))
			{
				cout << "Absence of such sequence" << endl;
				break;
			}
		}
	}
	else 
		cout << "Absence of such sequence" << endl;
}		
