#include <iostream>
#include <fstream>
#include <vector>
#include <string>

//Создать бинарный файл, компонентами которого является структура,
//содержащая следующие поля :
//− фамилия и инициалы студентов;
//− номер группы;
//− успеваемость(массив из трех дисциплин);
//− размер стипендии.
//Переписать бинарный файл так, чтобы для студентов, не имеющих
//двоек, размер стипендии будет увеличен на 30 %.

using namespace std;

struct Student {
    string name;
    string groupNumber;
    int grades[3];
    float scholarship;
};

void writeStudentsToFile(const vector<Student>& students, const string& filename) {
    ofstream file(filename, ios::binary);
    if (!file) {
        cerr << "Ошибка при открытии файла для записи." << endl;
        return;
    }

    for (const Student& student : students) {
        file.write(reinterpret_cast<const char*>(&student), sizeof(Student));
    }

    file.close();
}

void increaseScholarship(const string& filename) {
    ifstream file(filename, ios::binary);
    if (!file) {
        cerr << "Ошибка при открытии файла для чтения." << endl;
        return;
    }

    vector<Student> updatedStudents;
    Student tempStudent;

    while (file.read(reinterpret_cast<char*>(&tempStudent), sizeof(Student))) {
        bool hasTwos = false;
        for (int grade : tempStudent.grades) {
            if (grade == 2) {
                hasTwos = true;
                break;
            }
        }

        if (!hasTwos) {
            tempStudent.scholarship *= 1.3;
        }

        updatedStudents.push_back(tempStudent);
    }

    file.close();

    ofstream outFile(filename, ios::binary | ios::trunc);
    for (const Student& student : updatedStudents) {
        outFile.write(reinterpret_cast<const char*>(&student), sizeof(Student));
    }

    outFile.close();

    cout << "Информация о студентах после увеличения стипендии:" << endl;
    for (const Student& student : updatedStudents) {
        cout << "Фамилия и инициалы: " << student.name << endl;
        cout << "Номер группы: " << student.groupNumber << endl;
        cout << "Успеваемость: ";
        for (int grade : student.grades) {
            cout << grade << " ";
        }
        cout << endl;
        cout << "Размер стипендии: " << student.scholarship << endl;
        cout << "---------------------" << endl;
    }
}

int main() {
    setlocale(LC_ALL, "Ru");

    vector<Student> students = {
        {"Иванов И.И.", "Группа 1", {85, 90, 88}, 150.0},
        {"Петров П.П.", "Группа 2", {75, 80, 92}, 120.0},
        {"Сидоров С.С.", "Группа 1", {90, 95, 87}, 170.0}
    };

    const string filename = "students.bin";

    writeStudentsToFile(students, filename);

    increaseScholarship(filename);

    return 0;
}
