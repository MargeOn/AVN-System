#pragma once
#include<iostream>
#include<iomanip>
#include"AVN.h"
#include"Regrex.h"
using namespace std;

class Sound : public AVN
{
public:
	// Hàm khởi tạo đối tượng Sound
	Sound();
	// Constructor sao chép
	Sound(const Sound& other);
	// Phương thức nhập thông tin chức năng Sound
	void NhapAVN();
	// Phương thức xuất thông tin chức năng Sound
	void XuatAVN();	
	// Phương thức lấy các biến thành viên của đối tượng Sound của xe
	int get_media_level();
	int get_call_level();
	int get_navi_level();
	int get_notification_level();
	// Phương thức cài đặt giá trị cho các biến thành viên của đối tượng Sound của xe
	void set_media_level(int data);
	void set_call_level(int data);
	void set_navi_level(int data);
	void set_notification_level(int data);
	void swapSound(Sound& other);
private:
	int media_level;
	int call_level;
	int navi_level;
	int notification_level;
};
