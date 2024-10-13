#pragma once
#include<iostream>
#include<iomanip>
#include<vector>
#include"DataFile.h"
#include"AVN.h"
#include"Regrex.h"

using namespace std;

extern DataFile timezoneList[32];
extern DataFile languageList[30];

class General : public AVN
{
public:
	// Hàm khởi tạo đối tượng General
	General();
	// Constructor sao chép
	General(const General& other);
	// Phương thức nhập thông tin chức năng General
	void NhapAVN();
	// Phương thức xuất thông tin chức năng General
	void XuatAVN();
	// Phương thức lấy các biến thành viên của đối tượng General của xe
	string get_language();
	string get_timeZone();
	// Phương thức cài đặt giá trị cho các biến thành viên của đối tượng General của xe
	void set_timeZone(string data);
	void set_language(string data);
	// Phương thức sắp xếp theo bảng chữ cái Tiếng Anh
	void AlphabetSort(Type general);
	void swapGeneral(General& other);
private:
	string timeZone;
	string language;
};
