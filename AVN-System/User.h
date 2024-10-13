#pragma once
#include<iostream>
#include<iomanip>
#include"Regrex.h"

using namespace std;

class User
{
public:
	User();
	// Phương thức sao chép
	User(const User& other);
	// Phương thức nhập thông tin chủ xe
	void inputInfoCom();
	// Phương thức xuất thông tin chủ xe
	void outputInfoCom();
	// Phương thức lấy cho các thông tin của  chủ xe
	string getCarName();
	string getEmail();
	string getPersonalKey() const;
	int getODO();
	int getServiceRemind();
	// Phương thức cài đặt giá trị cho các thông tin của chủ xe
	void setCarName(string data);
	void setEmail(string data);
	void setPersonalKey(string data);
	void setODO(int data);
	void setServiceRemind(int data);
protected:
	string car_name;
	string email;			// email format abc@xyz.com
	string personal_key; 	// Chuoi 8 ky tu so
	int odo;
	int service_remind;
};