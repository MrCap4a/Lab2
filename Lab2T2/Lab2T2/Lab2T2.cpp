#include <iostream>
#include <fstream>
#include <string>
using namespace std;

//Дано 2 файла вещественных чисел а1.txt и а2.txt. Найти сумму положительных элементов в двух файлов.

int main()
{
    setlocale(LC_ALL, "Ru");

    ifstream fileA("a1.txt");
    ifstream fileB("a2.txt");

    string line = "";
    int sum = 0;

    while (getline(fileA, line)) {
        cout << line << endl;
        int num = stoi(line);
        if (num > 0) {
            sum += num;
        }
    }
    cout << endl;

    while (getline(fileB, line)) {
        cout << line << endl;
        int num = stoi(line);
        if (num > 0) {
            sum += num;
        }
    }
    cout << endl;

    cout << "Сумма положительных чисел: " << sum;

    fileA.close();
    fileB.close();
}
