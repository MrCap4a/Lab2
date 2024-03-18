#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
using namespace std;

//  Организовать текстовый файл. Заменить в файле все маленькие латинские буквы на большие. (Создавая новый дополнительный файл)


int main()
{
	ifstream readfile("in.txt");
	ofstream writefile("res.txt");

	string inS = "";

	while (getline(readfile, inS)) {
		string outS = "";
		cout << "In: " << inS << endl;
		for (char c : inS) {
			if (isalpha(c)) {
				outS += toupper(c);
			}
			else {
				outS += c;
			}
		}
		writefile << outS << endl;
		cout << "Out: " << outS << endl;
	}
	readfile.close();
	writefile.close();
}
