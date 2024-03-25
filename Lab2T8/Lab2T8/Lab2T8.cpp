#include <iostream>
#include <fstream>
#include <string>

using namespace std;

//Создать бинарный файл со списком о студентах :
//− фамилия и инициалы студентов;
//− номер группы;
//− успеваемость(массив из трех дисциплин по 100 - бальной систе - ме);
//− размер стипендии.
//Вывести список студентов, имеющих по всем предметам положительныеоценки
//и распечатать все сведения о них.

struct Student {
    string name;
    string groupNumber;
    int grades[3];
    float scholarship;
};

int main() {
    setlocale(LC_ALL, "Ru");

    ofstream file("students.bin", ios::binary);

    Student students[] = {
        {"Иванов И.И.", "Группа 1", {85, 90, 88}, 150.0},
        {"Петров П.П.", "Группа 2", {75, 80, 92}, 120.0},
        {"Сидоров С.С.", "Группа 1", {90, 95, 87}, 170.0}
    };

    for (const auto& student : students) {
        file.write(reinterpret_cast<const char*>(&student), sizeof(Student));
    }

    file.close();


    ifstream readFile("students.bin", ios::binary);

    cout << "Студенты с положительными оценками:" << endl;
    Student tempStudent;

    while (readFile.read(reinterpret_cast<char*>(&tempStudent), sizeof(Student))) {
        if (tempStudent.name.empty()) {
            break;
        }

        bool allPositive = true;
        for (int grade : tempStudent.grades) {
            if (grade < 0 || grade > 100) {
                allPositive = false;
                break;
            }
        }

        if (allPositive) {
            cout << "Фамилия и инициалы: " << tempStudent.name << endl;
            cout << "Номер группы: " << tempStudent.groupNumber << endl;
            cout << "Успеваемость: ";
            for (int grade : tempStudent.grades) {
                cout << grade << " ";
            }
            cout << endl;
            cout << "Размер стипендии: " << tempStudent.scholarship << endl;
            cout << "---------------------" << endl;
        }
    }

    if (readFile.eof()) {
        cout << "Данные прочитаны до конца файла." << endl;
    }
    else {
        cout << "Ошибка при чтении данных из файла." << endl;
    }

    readFile.close();

    return 0;
}
