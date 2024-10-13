#pragma once
#include<iostream>
#include<string>
#include<regex>
#include<sstream>
using namespace std;

// Định nghĩa kiểu dữ liệu mang các tên thông tin trong xe để kiểm tra các thông tin mà người dùng nhập vào có hợp lệ hay không?
enum Type {
	// Lựa chọn Menu nhập xuất
	MenuIO,
	// Lựa chọn Menu nhập
	MenuIn,
	// Lựa chọn Menu xuất
	MenuOut,
	MenuFind,
	MenuXoa,
	// Thuộc tính chung
	Name,
	Email,
	Key,
	Odo,
	Service,
	// Thuộc tính Display
	Light,
	Screen,
	Taplo,
	// Thuộc tính Sound
	Media,
	Call,
	Navi,
	Notification,
	// Thuộc tính General
	Timezone,
	Language,
	// Lựa chọn sắp xếp
	GenSort,
	CarSort
};

// Khai báo hàm kiểm tra nhập kí tự hợp lệ khi lựa chọn có tiếp tục nhập thêm xe hay không
bool isValidCharacter(string);
// Khai báo hàm kiểm tra nhập hợp lệ của các lựa chọn trong các MenuIO, MenuIn, MenuOut và thông 
// tin chung và chức năng của xe
bool Regrex(Type, string);




