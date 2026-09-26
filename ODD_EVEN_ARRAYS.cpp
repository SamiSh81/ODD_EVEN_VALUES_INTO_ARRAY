// ODD_EVEN_ARRAYS.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
enum enOddEven{ODD=1,EVEN=2};

int ReadPostiveNumber(string msg)
{
	int number;

	do
	{
		cout << msg << endl;
		cin >> number;

	} while (number <= 0);
	return number;
}
int Random_Number()
{
	int Rand_Number = rand() % (1 - 100 + 1) + 1;
	return Rand_Number;
}
enOddEven RETURN_ODD_VALUE(int number)
{
	if (number % 2 == 1)
		return enOddEven::ODD;
	
}
enOddEven RETURN_EVEN_VALUE(int number)
{
	if (number % 2 == 0)
		return enOddEven::EVEN;
}

void FillArray(int arr[100], int& Lenght_source)
{
	Lenght_source = ReadPostiveNumber("ENTER LENGHT OF ARRAY:");

	for (int i = 0; i < Lenght_source; i++)
	{
		arr[i] = Random_Number();
	}
}
void Print_Arreay(int arr[100], int Lenght)
{
	for (int i = 0; i < Lenght; i++)
	{
		cout << arr[i] << " ";
	}
}

void Return_Odd_Even_Arrays(int source_arr[100], int odd_arr[100],int even_arr[100],
	int Lenght_source, int &Lenght_odd,int &Lenght_even)
{
	int odd_count = 0;
	int even_count = 0;
	for (int count = 0; count < Lenght_source; count++)
	{
		if (RETURN_ODD_VALUE(source_arr[count])==enOddEven::ODD)
		{
			odd_arr[odd_count] = source_arr[count];
			odd_count++;
		}
		else if (RETURN_EVEN_VALUE(source_arr[count]) == enOddEven::EVEN)
		{
			even_arr[even_count] = source_arr[count];
			even_count++;
				
		}
	}
	Lenght_odd = odd_count--;
	Lenght_even = even_count--;
}

int main()
{
	srand((unsigned)time(NULL));
	int sourcr_arr[100];
	int Lenght_source;
	FillArray(sourcr_arr, Lenght_source);

	int odd_arr[100],even_arr[100];
	int Lenght_odd = 0,Lenght_even=0;

	Return_Odd_Even_Arrays(sourcr_arr, odd_arr,even_arr,Lenght_source, Lenght_odd,Lenght_even);

	cout << "Values Of The Source Array:" << endl;
	Print_Arreay(sourcr_arr, Lenght_source);

	cout << endl;
	cout << endl << "Odd Values:" << endl;
	Print_Arreay(odd_arr, Lenght_odd);
	cout << endl;

	cout << endl << "Even Values:" << endl;
	Print_Arreay(even_arr, Lenght_even);
	cout << endl;
}