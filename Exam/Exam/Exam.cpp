#include <iostream>
#include <bitset>
#include <cstdlib>

#define MAX_MASK_LENGTH 32

using namespace std;

bool NeprerivnyMask(const string& binaryMask)
{
	if (binaryMask.length() > MAX_MASK_LENGTH) 
	{
		cout << "Ошибка: Маска не может быть длиннее, чем " << MAX_MASK_LENGTH << " символов!" << endl;
		return false;
	}

	for (char ch : binaryMask) {
		if (ch != '0' && ch != '1')
		{
			cout << "Ошибка: Маска не содержать символов, кроме '1' и '0'!" << endl;
			return false;
		}
	}

	size_t firstZero = binaryMask.find("0");

	if (firstZero != string::npos && binaryMask.find('1', firstZero) != string::npos)
	{
		return false;
	}

	return true;
}

int main()
{
	setlocale(0, "Rus");

	string mask;

	cout << "Введите маску: ";
	cin >> mask;

	if (NeprerivnyMask(mask))
		cout << "Это правильная маска!";
	else
		cout << "Это маска содержит ошибки!";

	return 0;
}
