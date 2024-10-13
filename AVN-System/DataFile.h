#pragma once
#include <iostream>
#include <string>
#include"Regrex.h"

using namespace std;

class DataFile {
public:
	// Phương thức lấy chuỗi đầu tiên của file
	string getNumber() {
		return number;
	}
	// Phương thức lấy chuỗi thứ hai của file
	string getName() {
		return name;
	}
	// Phương thức cài đặt giá trị chuỗi đầu tiên của file
	void setNumber(string data) {
		number = data;
	}
	// Phương thức cài đặt giá trị chuỗi thứ hai của file
	void setName(string data) {
		name = data;
	}
	// Phương thức xuất thông tin có trong đối tượng DataFile
	void printData(Type general, int i) {
		switch (general) {
			case Timezone: {
				cout << i + 1 << ": " << this->getNumber() << "  " << this->getName() << endl;
				break;
			}
			case Language:
			{
				cout << i + 1 << ": " << this->getName() << endl;
				break;
			}
			default:
				break;
		}
	}
private:
	string number;
	string name;
};


