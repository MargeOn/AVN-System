#include"Car.h"

// Hàm khởi tạo đối tượng Car
Car::Car() : avn{ nullptr, nullptr, nullptr } {
	this->avn[0] = new Display();
	this->avn[1] = new Sound();
	this->avn[2] = new General();
}
Car::Car(const Car& temp) : User(temp) {
	this->avn[0] = nullptr;
	this->avn[1] = nullptr;
	this->avn[2] = nullptr;
	if (Display* d = dynamic_cast<Display*>(temp.avn[0])) {
		// Sao chép đối tượng Display
		this->avn[0] = new Display(*d);
	}
	if (Sound* s = dynamic_cast<Sound*>(temp.avn[1])) {
		// Sao chép đối tượng Sound
		this->avn[1] = new Sound(*s); 
	}
	if (General* g = dynamic_cast<General*>(temp.avn[2])) {
		// Sao chép đối tượng General
		this->avn[2] = new General(*g);
	}
}

Car& Car::operator=(const Car& temp) {
	// Giải phóng bộ nhớ hiện tại
	for (int i = 0; i < 3; ++i) {
		delete avn[i];
		this->avn[i] = nullptr;
	}
	if (Display* d = dynamic_cast<Display*>(temp.avn[0])) {
		this->avn[0] = new Display(*d);
	}
	if (Sound* s = dynamic_cast<Sound*>(temp.avn[1])) {
		this->avn[1] = new Sound(*s);  
	}
	if (General* g = dynamic_cast<General*>(temp.avn[2])) {
		this->avn[2] = new General(*g);
	}
	return *this;
}

AVN* Car::getAVN(int type) {
	if (type == 0) {
		return avn[0];
	}
	else if (type == 1) {
		return avn[1];
	}
	else {
		return avn[2];
	}
}

// Phương thức cập nhật thông tin chức năng của xe khi đã kiểm tra xe mới nhập
// trùng mã số cá nhân với List xe thì nhận biết được xe có tồn tại.
void Car::updateInfo(int typeOption, const Car& data) {
	// Cập nhật lại các thông tin chung của chủ xe như: tên chủ xe, tài khoản gmail, số km xe đi được và số km bảo dưỡng.
	this->car_name = data.car_name;
	this->email = data.email;
	this->odo = data.odo;
	this->service_remind = data.service_remind;
	// Cập nhật các giá trị của các chức năng Display, Sound, General tương ứng với các lựa chọn trong Menu2
	// mà người dùng muốn nhập.
	switch (typeOption)
	{
		// Trường hợp chọn nhập Display, cập nhật lại các mức sáng đèn trên xe
		case 1: 
			delete avn[0];
			this->avn[0] = nullptr;
			if (Display* d = dynamic_cast<Display*>(data.avn[0])) {
				this->avn[0] = new Display(*d);
			}
			break;
		// Trường hợp chọn nhập Sound, cập nhật lại các mức âm thanh trên xe
		case 2:
			delete avn[1];
			this->avn[1] = nullptr;
			if (Sound* s = dynamic_cast<Sound*>(data.avn[1])) {
				this->avn[1] = new Sound(*s);
			}
			break;
		// Trường hợp chọn nhập General, cập nhật lại các thông tin múi giờ và ngôn ngữ trên xe
		case 3:
			delete avn[2];
			this->avn[2] = nullptr;
			if (General* g = dynamic_cast<General*>(data.avn[2])) {
				this->avn[2] = new General(*g);
			}
			break;
		// Trường hợp người dùng chưa chọn nhập 3 chức năng thì không cập nhật
		default:
			break;
	}
}

void Car::swapCar(Car &temp){
	swap(this->car_name, temp.car_name);
	swap(this->odo, temp.odo);
	swap(this->email, temp.email);
	swap(this->personal_key, temp.personal_key);
	swap(this->service_remind, temp.service_remind);
	if (Display* d1 = dynamic_cast<Display*>(this->avn[0])) {
		if (Display* d2 = dynamic_cast<Display*>(temp.avn[0])) {
			d1->swapDisplay(*d2);  
		}
	}

	if (Sound* s1 = dynamic_cast<Sound*>(this->avn[1])) {
		if (Sound* s2 = dynamic_cast<Sound*>(temp.avn[1])) {
			s1->swapSound(*s2); 
		}
	}

	if (General* g1 = dynamic_cast<General*>(this->avn[2])) {
		if (General* g2 = dynamic_cast<General*>(temp.avn[2])) {
			g1->swapGeneral(*g2); 
		}
	}
}

// Hàm hủy đối tượng Car
Car::~Car(){
	// Hủy cấp phát động lần lượt cho 3 con trỏ avn[i]
	for (int i = 0; i < 3; ++i) {
		delete avn[i];
	}
}

