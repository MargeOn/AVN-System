#include "Display.h"

// Hàm khởi tạo đối tượng Display
Display::Display()
{
	// Khởi tạo các biến thành viên một giá trị ban đầu bằng 0 khi có đối tượng Display được khởi tạo
	light_level = 0;
	screen_light_level = 0;
	taplo_light_level = 0;
}
// Constructor sao chép
Display::Display(const Display& other) {
	light_level = other.light_level;
	screen_light_level = other.screen_light_level;
	taplo_light_level = other.taplo_light_level;
}
// Phương thức nhập thông tin chức năng Display
void Display::NhapAVN() {
	string light_level = "";
	string screen_light_level = "";
	string taplo_light_level = "";
	// Nhập mức light_level
	do
	{
		cout << "Light level: ";
		getline(cin, light_level);
		// Kiểm tra nhập thông tin có hợp lệ hay không
		if (!Regrex(Light, light_level))
		{
			cout << "\nLight level phai la 1 so khong vuot qua 100%!" << endl;
			system("pause");
		}
		// Nếu không hợp lệ, cho phép nhập lại lần nữa
	} while (!Regrex(Light, light_level));
	this->light_level = stoi(light_level);
	// Nhập mức screen_light_level
	do
	{
		cout << "Screen light level: ";
		getline(cin, screen_light_level);
		// Kiểm tra nhập thông tin có hợp lệ hay không
		if (!Regrex(Screen, screen_light_level))
		{
			cout << "\nScreen light level phai la 1 so khong vuot qua 100%!" << endl;
			system("pause");
		}
		// Nếu không hợp lệ, cho phép nhập lại lần nữa
	} while (!Regrex(Screen, screen_light_level));
	this->screen_light_level = stoi(screen_light_level);
	// Nhập mức taplo_light_level
	do
	{
		cout << "Taplo light level: ";
		getline(cin, taplo_light_level);
		// Kiểm tra nhập thông tin có hợp lệ hay không
		if (!Regrex(Taplo, taplo_light_level))
		{
			cout << "\nTaplo light level phai la 1 so khong vuot qua 100%!" << endl;
			system("pause");
		}
		// Nếu không hợp lệ, cho phép nhập lại lần nữa
	} while (!Regrex(Taplo, taplo_light_level));
	this->taplo_light_level = stoi(taplo_light_level);
}

void Display::XuatAVN() {
	cout << setw(10) << this->light_level
		<< setw(10) << this->screen_light_level
		<< setw(10) << this->taplo_light_level;
}

// Phương thức lấy các biến thành viên của đối tượng Display của xe
int Display::get_light_level() {
	return light_level;
}
int Display::get_screen_light_level() {
	return screen_light_level;
}
int Display::get_taplo_light_level() {
	return taplo_light_level;
}

// Phương thức cài đặt giá trị cho các biến thành viên của đối tượng Display của xe
void Display::set_light_level(int data) {
	this->light_level = data;
}
void Display::set_screen_light_level(int data) {
	this->screen_light_level = data;
}
void Display::set_taplo_light_level(int data) {
	this->taplo_light_level = data;
}

void Display::swapDisplay(Display& other) {
	swap(this->light_level, other.light_level);
	swap(this->screen_light_level, other.screen_light_level);
	swap(this->taplo_light_level, other.taplo_light_level);
}