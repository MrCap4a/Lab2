#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Дан файл вещественных чисел a.txt Найти количество отрицательных и количество положительных элементов.

int main()
{
	setlocale(LC_ALL, "Ru");

	int num;
	int negative_count = 0;
	int positiove_count = 0;
	string snum;
	ifstream file("a.txt");
	while ( getline(file, snum) ) {
		cout << snum << endl;
		num = stoi(snum);
		if (num > 0) {
			positiove_count += 1;
		}
		else {
			if (num < 0) {
				negative_count += 1;
			}
		}
	}
	file.close();
	cout << "Положительных чисел: " << positiove_count << endl;
	cout << "Отрицательных чисел: " << negative_count << endl;

	return 0;
}