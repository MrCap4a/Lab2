#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
	ifstream readfile("in.txt");
	ofstream odd("odd.txt");
	ofstream even("even.txt");

	string line = "";
	bool isOdd = true;

	while (getline(readfile, line)) {
		if (isOdd) {
			odd << line << endl;
		}
		else {
			even << line << endl;
		}
		isOdd = !isOdd;
	}
	readfile.close();
	odd.close();
	even.close();

	cout << "Completed!";
}