#pragma once
#include"Display.h"
#include"Sound.h"
#include"General.h"
#include"User.h"
#include<iostream>
#include<fstream>
#include<vector>

using namespace std;

class Car : public User
{
public:
	// Phương thức khởi tạo đối tượng Car
	Car();
	// Phương thức thiết lập sao chép
	Car(const Car& temp);
	// Nạp chồng toán tử gán
	Car& operator=(const Car& temp);
	AVN* getAVN(int type);
	// Phương thức cập nhật thông tin chức năng của xe
	void updateInfo(int typeOption, const Car& data);
	void swapCar(Car& temp);
	// Hàm hủy đối tượng Car
	~Car();
private:
	AVN* avn[3];
};
