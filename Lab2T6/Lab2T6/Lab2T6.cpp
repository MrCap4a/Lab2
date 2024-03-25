#include <iostream>
#include <fstream>
#include <string>


//Дан файл f, компоненты которого являются действительными числами.
//Найти произведение компонент файла.

using namespace std;

int main() {
    setlocale(LC_ALL, "Ru");

    ifstream inputFile("a.txt");

    double num, product = 1.0;
    string line = "";

    while (getline(inputFile, line)) {
        num = stof(line);
        product *= num;
        cout << product << " " << num << endl;
    }

    inputFile.close();

    ofstream outputFile("result.txt");

    outputFile << "Произведение чисел из файла a.txt: " << product;

    outputFile.close();

    cout << "Произведение чисел успешно найдено и записано в файл result.txt\n";

    return 0;
}
