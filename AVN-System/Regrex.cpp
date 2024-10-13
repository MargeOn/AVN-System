
#include "Regrex.h"

// Kiểm tra hợp lệ lựa chọn có tiếp tục nhập xe hay không.
bool isValidCharacter(string c) {
	// Lựa chọn phải là 'y' hoặc 'n'
	regex pattern("^[yn]$"); 
	// Chuyển đổi ký tự thành chuỗi và kiểm tra xem chuỗi có khớp với mẫu regex hay không
	return regex_match(c, pattern);
}

// Định nghĩa hàm kiểm tra nhập hợp lệ  của các lựa chọn trong các MenuIO, MenuIn, MenuOut và thông 
// tin chung và chức năng của xe
bool Regrex(Type type, string input) {
	switch (type)
	{
	// Kiểm tra nhập lựa chọn Menu nhập xuất có hợp lệ không
	case MenuIO:
	{
		// Số hợp lệ là số từ 1 đến 5
		regex pattern("^[1-5]$");
		if (!regex_match(input, pattern))
		{
			return false;
		}
		return true;
	}
	// Kiểm tra nhập lựa chọn Menu nhập có hợp lệ không
	case MenuIn:
	{
		// Số hợp lệ là số từ 1 đến 4
		regex pattern("^[1-4]$");
		if (!regex_match(input, pattern))
		{
			return false;
		}
		return true;
	}
	// Kiểm tra nhập lựa chọn Menu xuất có hợp lệ không
	case MenuOut:
	{
		// Số hợp lệ là số từ 1 đến 5
		regex pattern("^[1-5]$");
		if (!regex_match(input, pattern))
		{
			return false;
		}
		return true;
	}
	// Kiểm tra nhập lựa chọn Menu tìm kiếm có hợp lệ không
	case MenuFind:
	{
		// Số hợp lệ là số từ 1 đến 3
		regex pattern("^[1-3]$");
		if (!regex_match(input, pattern))
		{
			return false;
		}
		return true;
	}
	// Kiểm tra nhập lựa chọn Menu xuất có hợp lệ không
	case MenuXoa:
	{
		// Số hợp lệ là số từ 1 đến 2
		regex pattern("^[1-2]$");
		if (!regex_match(input, pattern))
		{
			return false;
		}
		return true;
	}
	// Nếu nhập tên xe, kiểm tra rằng tên chủ xe có hợp lệ chưa.
	case Name:
	{
		// Tên hợp lệ là tên có 2 từ trở lên và các từ phải có 2 chữ cái trở lên
		regex pattern("^[A-Za-z]{2,}(\\s[A-Za-z]{2,})+$");
		if (!regex_match(input, pattern))
		{
			return false;
		}
		return true;
	}
	// Nếu nhập tài khoản gmail của chủ xe, kiểm tra rằng thông tin có hợp lệ chưa.
	case Email:
	{
		// Email hợp lệ là email có định dạng "abc@xyz.def"
		regex pattern("^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\\.[a-zA-Z]{2,}$");
		if (!regex_match(input, pattern))
		{
			return false;
		}
		return true;
	}
	// Nếu nhập mã số cá nhân, kiểm tra rằng thông tin có hợp lệ chưa.
	case Key:
	{
		// Mã số cá nhân hợp lệ là mã số cá nhân có số có đủ chữ số
		regex pattern("^[0-9][0-9]{7}$");
		if (!regex_match(input, pattern))
		{
			return false;
		}
		return true;
	}
	// Nếu nhập số km xe chạy được, kiểm tra rằng thông tin có hợp lệ chưa.
	case Odo:
	{
		// Số km đi được hợp lệ là số km không phải là 0 và không vượt quá 1.000.000km
		regex pattern("^([1-9][0-9]{0,5}|1000000)$");
		if (!regex_match(input, pattern))
		{
			return false;
		}
		return true;
	}
	// Nếu nhập số km cần bảo dưỡng, kiểm tra rằng thông tin có hợp lệ chưa.
	case Service:
	{
		// Số km bảo dưỡng định kì hợp lệ là số km từ 1.000km đến 5.000km 
		regex pattern("^(100[0-9]|10[1-9][0-9]|1[1-9][0-9]{2}|[2-4][0-9]{3}|5000)$");
		if (!regex_match(input, pattern))
		{
			return false;
		}
		return true;
	}
	// Nếu nhập mức sáng đèn, kiểm tra rằng lựa chọn có hợp lệ chưa.
	case Light:
	{
		// Mức sáng đèn hợp lệ phải từ 0-100%
		regex pattern("^([0-9]|[1-9][0-9]|100)$");
		if (!regex_match(input, pattern))
		{
			return false;
		}
		return true;
	}
	// Nếu nhập mức sáng màn hình, kiểm tra rằng lựa chọn có hợp lệ chưa.
	case Screen:
	{
		// Mức sáng màn hình hợp lệ phải từ 0-100%
		regex pattern("^([0-9]|[1-9][0-9]|100)$");
		if (!regex_match(input, pattern))
		{
			return false;
		}
		return true;
	}
	// Nếu nhập mức sáng đèn taplo, kiểm tra rằng lựa chọn có hợp lệ chưa.
	case Taplo:
	{
		// Mức sáng đèn taplo hợp lệ phải từ 0-100%
		regex pattern("^([0-9]|[1-9][0-9]|100)$");
		if (!regex_match(input, pattern))
		{
			return false;
		}
		return true;
	}
	// Nếu nhập độ lớn hệ thống âm thanh, kiểm tra rằng lựa chọn có hợp lệ chưa.
	case Media:
	{
		// Độ lớn hệ thống âm thanh hợp lệ phải từ 0-100%
		regex pattern("^([0-9]|[1-9][0-9]|100)$");
		if (!regex_match(input, pattern))
		{
			return false;
		}
		return true;
	}
	// Nếu nhập độ lớn âm thanh cuộc gọi, kiểm tra rằng lựa chọn có hợp lệ chưa.
	case Call:
	{
		// Độ lớn âm thanh cuộc gọi hợp lệ phải từ 0-100%
		regex pattern("^([0-9]|[1-9][0-9]|100)$");
		if (!regex_match(input, pattern))
		{
			return false;
		}
		return true;
	}
	// Nếu nhập độ lớn âm thanh định vị, kiểm tra rằng lựa chọn có hợp lệ chưa.
	case Navi:
	{		
		// Độ lớn âm thanh định vị hợp lệ phải từ 0-100%
		regex pattern("^([0-9]|[1-9][0-9]|100)$");
		if (!regex_match(input, pattern))
		{
			return false;
		}
		return true;
	}
	// Nếu nhập độ lớn âm thanh thông báo, kiểm tra rằng lựa chọn có hợp lệ chưa.
	case Notification:
	{
		// Độ lớn âm thanh thông báo hợp lệ phải từ 0-100%
		regex pattern("^([0-9]|[1-9][0-9]|100)$");
		if (!regex_match(input, pattern))
		{
			return false;
		}
		return true;
	}
	// Nếu nhập lựa chọn khu vực múi giờ, kiểm tra rằng lựa chọn có hợp lệ chưa.
	case Timezone:
	{
		// Lựa chọn khu vực múi giờ hợp lệ là lựa chọn từ 1 đến 32
		regex pattern("^([1-9]|[1-2][0-9]|32)$");
		if (!regex_match(input, pattern))
		{
			return false;
		}
		return true;
	}
	// Nếu nhập lựa chọn ngôn ngữ, kiểm tra rằng lựa chọn có hợp lệ chưa.
	case Language:
	{
		// Lựa chọn ngôn ngữ hợp lệ là lựa chọn từ 1 đến 30
		regex pattern("^([1-9]|[1-2][0-9]|30)$");
		if (!regex_match(input, pattern))
		{
			return false;
		}
		return true;
	}
	// Kiểm tra nhập lựa chọn sắp xếp chức năng General có hợp lệ chưa
	case GenSort:
	{
		// Số hợp lệ là số từ 1 đến 2
		regex pattern("^[1-2]$");
		if (!regex_match(input, pattern))
		{
			return false;
		}
		return true;
	}
	// Kiểm tra nhập lựa chọn sắp xếp thông tin của xe có hợp lệ chưa
	case CarSort:
	{
		// Số hợp lệ là số từ 1 đến 3
		regex pattern("^[1-2]$");
		if (!regex_match(input, pattern))
		{
			return false;
		}
		return true;
	}
	// Nếu không kiểm tra các trường hợp trên thì thông báo chưa kiểm tra regrex và trả về false
	default:
		cout << "He thong chua kiem tra hop le";
		system("pause");
		return false;
	}
}


