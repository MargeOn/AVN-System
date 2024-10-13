#include "Sound.h"

// Hàm khởi tạo đối tượng Sound
Sound::Sound() {
	// Khởi tạo các biến thành viên một giá trị ban đầu bằng 0 khi có đối tượng Sound được khởi tạo
	media_level = 0;
	call_level = 0;
	navi_level = 0;
	notification_level = 0;
}

// Constructor sao chép
Sound::Sound(const Sound& other) {
	media_level = other.media_level;
	call_level = other.call_level;
	navi_level = other.navi_level;
	notification_level = other.notification_level;
}
// Phương thức lấy các biến thành viên của đối tượng Sound của xe
int Sound::get_media_level() {
	return media_level;
}
int Sound::get_call_level() {
	return call_level;
}
int Sound::get_navi_level() {
	return navi_level;
}
int Sound::get_notification_level() {
	return notification_level;
}

// Phương thức cài đặt giá trị cho các biến thành viên của đối tượng Sound của xe
void Sound::set_media_level(int data) {
	this->media_level = data;
}
void Sound::set_call_level(int data) {
	this->call_level = data;
}
void Sound::set_navi_level(int data) {
	this->navi_level = data;
}
void Sound::set_notification_level(int data) {
	this->notification_level = data;
}

// Phương thức nhập thông tin chức năng Sound
void Sound::NhapAVN() {
	string media_level = ""
		, call_level = ""
		, navi_level = ""
		, notification_level = "";
	// Nhập mức media_level
	do
	{
		cout << "Media volume level: ";
		getline(cin, media_level);
		// Kiểm tra nhập thông tin có hợp lệ hay không
		if (!Regrex(Media, media_level))
		{
			cout << "\nMedia volume level phai la 1 so khong vuot qua 100%!" << endl;
			system("pause");
		}
		// Nếu không hợp lệ, cho phép nhập lại lần nữa
	} while (!Regrex(Media, media_level));
	this->media_level = stoi(media_level);
	// Nhập mức call_level
	do
	{
		cout << "Call volume level: ";
		getline(cin, call_level);
		// Kiểm tra nhập thông tin có hợp lệ hay không
		if (!Regrex(Call, call_level))
		{
			cout << "\nCall volume level phai la 1 so khong vuot qua 100%!" << endl;
			system("pause");
		}
		// Nếu không hợp lệ, cho phép nhập lại lần nữa
	} while (!Regrex(Call, call_level));
	this->call_level = stoi(call_level);
	// Nhập mức navi_level
	do
	{
		cout << "Navigation volume level: ";
		getline(cin, navi_level);
		// Kiểm tra nhập thông tin có hợp lệ hay không
		if (!Regrex(Navi, navi_level))
		{
			cout << "\nNavigation volume level phai la 1 so khong vuot qua 100%!" << endl;
			system("pause");
		}
		// Nếu không hợp lệ, cho phép nhập lại lần nữa
	} while (!Regrex(Navi, navi_level));
	this->navi_level = stoi(navi_level);
	// Nhập mức notification_level
	do
	{
		cout << "Notification volume level: ";
		getline(cin, notification_level);
		// Kiểm tra nhập thông tin có hợp lệ hay không
		if (!Regrex(Notification, notification_level))
		{
			cout << "\nNotification volume level phai la 1 so khong vuot qua 100%!" << endl;
			system("pause");
		}
		// Nếu không hợp lệ, cho phép nhập lại lần nữa
	} while (!Regrex(Notification, notification_level));
	this->notification_level = stoi(notification_level);
}

// Phương thức xuất thông tin chức năng Sound
void Sound::XuatAVN() {
	cout << setw(10) << this->media_level
		<< setw(10) << this->call_level
		<< setw(10) << this->navi_level
		<< setw(10) << this->notification_level;
}

void Sound::swapSound(Sound& other) {
	swap(this->media_level, other.media_level);
	swap(this->call_level, other.call_level);
	swap(this->navi_level, other.navi_level);
	swap(this->notification_level, other.notification_level);
}