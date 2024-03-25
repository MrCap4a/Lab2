#include <iostream>
#include <fstream>
#include <vector>

//Ввести в Memo или в StringGrid некоторое количество целых чисел и
//записать их в бинарный файл.Переписать бинарный файл так, чтобы
//каждое значение, записанное в файле, было увеличено в два раза.
//Распечатать числа до и после изменения данных в файле.

using namespace std;

void writeDataToFile(const vector<int>& data, const string& filename) {
    ofstream file(filename, ios::binary);
    if (!file) {
        cerr << "Ошибка при открытии файла для записи." << endl;
        return;
    }

    for (int num : data) {
        file.write(reinterpret_cast<const char*>(&num), sizeof(int));
    }

    file.close();
}

void doubleValuesInFile(const string& filename) {
    ifstream file(filename, ios::binary);
    if (!file) {
        cerr << "Ошибка при открытии файла для чтения." << endl;
        return;
    }

    vector<int> data;
    int num;

    while (file.read(reinterpret_cast<char*>(&num), sizeof(int))) {
        data.push_back(num * 2);
    }

    file.close();

    ofstream outFile(filename, ios::binary | ios::trunc);
    for (int num : data) {
        outFile.write(reinterpret_cast<const char*>(&num), sizeof(int));
    }

    outFile.close();
}

int main() {
    setlocale(LC_ALL, "Ru");

    vector<int> numbers = { 10, 20, 30, 40, 50 };
    const string filename = "numbers.bin";

    writeDataToFile(numbers, filename);

    cout << "Числа до увеличения в два раза:" << endl;
    for (int num : numbers) {
        cout << num << " ";
    }
    cout << endl;

    doubleValuesInFile(filename);

    ifstream outFile(filename, ios::binary);
    cout << "Числа после увеличения в два раза:" << endl;
    int num;
    while (outFile.read(reinterpret_cast<char*>(&num), sizeof(int))) {
        cout << num << " ";
    }
    cout << endl;

    outFile.close();

    return 0;
}
