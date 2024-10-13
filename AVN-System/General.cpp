#include "General.h"

// Hàm khởi tạo đối tượng General
General::General()
{
	// Khởi tạo các biến thành viên với một chuỗi trống ban đầu khi có đối tượng General được khởi tạo
	timeZone = "GMT-12:00";
	language = "English";
}

// Constructor sao chép
General::General(const General& other) {
	timeZone = other.timeZone;
	language = other.language;
}
// Phương thức nhập thông tin chức năng General
void General::NhapAVN() {
	string select_time, select_language;
	// Hiển thị menu timezone trước. Khi đó, ta phải sắp xếp danh sách mà ta mong muốn. Ở đây, được sắp xếp
	// theo Alphabet
	AlphabetSort(Timezone);
	// Xuất bảng các khu vực múi giờ thế giới
	for (int i = 0; i < 32; i++) {
		timezoneList[i].printData(Timezone, i);
	}
	// Nhập lựa chọn timezone
	do
	{
		cout << "Your selection: ";
		getline(cin, select_time);
		if (!Regrex(Timezone, select_time))
		{
			cout << "\nLua chon phai la mot so tu 1 den 32! " << endl;
			system("pause");
		}
	} while (!Regrex(Timezone, select_time));
	// Lựa chọn hợp lệ và gán khu vực múi giờ tương ứng với lựa chọn 
	int i = stoi(select_time);
	timeZone = timezoneList[i - 1].getNumber();
	timeZone.erase(remove(timeZone.begin(), timeZone.end(), ' '), timeZone.end());
	timeZone.erase(remove(timeZone.begin(), timeZone.end(), '('), timeZone.end());
	timeZone.erase(remove(timeZone.begin(), timeZone.end(), ')'), timeZone.end());	
	// Tiếp theo hiển thị menu language trước. Khi đó, ta phải sắp xếp danh sách mà ta mong muốn. Ở đây, được 
	// sắp xếp theo Alphabet
	system("cls");
	AlphabetSort(Language);
	// Xuất bảng các ngôn ngữ trên thế giới
	for (int i = 0; i < 30; i++) {
		languageList[i].printData(Language, i);
	}
	// Nhập lựa chọn language
	do
	{
		cout << "Your selection: ";
		getline(cin, select_language);
		if (!Regrex(Language, select_language))
		{
			cout << "\nLua chon phai la mot so tu 1 den 30! " << endl;
			system("pause");
		}
	} while (!Regrex(Language, select_language));
	// Lựa chọn hợp lệ và gán ngôn ngữ tương ứng với lựa chọn 
	int j = stoi(select_language);
	language = languageList[j - 1].getName();
	language.erase(0,1);
}

// Phương thức xuất thông tin chức năng General
void General::XuatAVN() {
	cout << setw(30) << this->timeZone
		<< setw(20) << this->language;
}

// Phương thức lấy các biến thành viên của đối tượng General của xe
string General::get_language() {
	return language;
}
string General::get_timeZone() {
	return timeZone;
}

// Phương thức cài đặt giá trị cho các biến thành viên của đối tượng General của xe
void General::set_language(string data) {
	this->language = data;
}
void General::set_timeZone(string data) {
	this->timeZone = data;
}

// Phương thức sắp xếp theo bảng chữ cái Tiếng Anh trong các bảng lựa chọn timezone và language
void General::AlphabetSort(Type general) {
	bool swapped;
	switch (general) {
	case Timezone: {
		for (int i = 0; i < 32; ++i) {
			swapped = false;
			for (int j = 0; j < 32 - i - 1; ++j) {
				if (timezoneList[j].getName() > timezoneList[j + 1].getName()) {
					swap(timezoneList[j], timezoneList[j + 1]);
					swapped = true;
				}
			}
			// Nếu không có sự hoán đổi nào xảy ra trong một vòng lặp, mảng đã được sắp xếp
			if (!swapped) {
				break;
			}
		}
		break;
	}
	case Language:
	{
		for (int i = 0; i < 30; ++i) {
			swapped = false;
			for (int j = 0; j < 30 - i - 1; ++j) {
				if (languageList[j].getName() > languageList[j + 1].getName()) {
					swap(languageList[j], languageList[j + 1]);
					swapped = true;
				}
			}
			// Nếu không có sự hoán đổi nào xảy ra trong một vòng lặp, mảng đã được sắp xếp
			if (!swapped) {
				break;
			}
		}
		break;
	}
	default:
		break;
	}	
}

void General::swapGeneral(General& other) {
	swap(this->timeZone, other.timeZone);
	swap(this->language, other.language);
}