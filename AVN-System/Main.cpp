#include"Car.h"

// Khởi tạo mảng vector chứa các phần tử Car
vector<Car> ListVehicle;
// Khai báo 2 mảng timezoneList vàlanguageList có kiểu DataFile
DataFile timezoneList[32];
DataFile languageList[30];
// Khai báo các hàm nhập thông tin chức năng của xe
void NhapThongTinCaiDat_Display();
void NhapThongTinCaiDat_Sound();
void NhapThongTinCaiDat_General();
// Khai báo các hàm xuất thông tin chức năng của xe
void XuatThongTinCaiDat_Display();
void XuatThongTinCaiDat_Sound();
void XuatThongTinCaiDat_General();
void XuatTatCaThongTinCaiDat();
// Khai báo hàm tách chuỗi thông tin của file txt
const vector<string> explode(const string&, const char&);
// Khai báo các hàm tải các thông tin của file txt
void downloadTimeZone();
void downloadLanguage();
// Màn hình 1 hiển thị chức năng nhập, xuất thông tin của xe
void Menu();
// Màn hình 2 hiển thị chức năng nhập các thông tin của xe
void MenuInput();
// Màn hình 3 hiển thị chức năng xuất các thông tin của xe
void MenuOutput();
// Màn hình 4 cho phép tìm kiếm các thông tin của xe
void MenuSearch();
// Màn hình 5 cho phép xóa các thông tin của xe
void MenuErase();
// Khai báo hàm kiểm tra thông tin cá nhân của xe đang nhập và thông tin của xe trong danh sách hiện
// có. Nó có trùng nhau không? 
int checkCarExit(const Car&);
// Hàm sắp xếp nổi bọt
void bubblesort(Type);
// Hàm sắp xếp xe trong mảng ListVehicle
void carSort(Type);
// Menu lựa chọn sắp xếp thông tin của các xe
void carSort_Menu();
// Tìm kiếm nhị phân với độ phức tạp Ologn
int binary_Search(Type, string);
// Ghi đối tượng Xe vào file Setting.txt
void writeSetting();
// Đọc đối tượng Xe từ file Setting.txt
void readSetting();

int main(int argc, char** argv) {
	// Đầu tiên đọc thông tin chung: timezone, language trong file rồi đưa vào mảng.
	downloadLanguage();
	downloadTimeZone();
	// Sau đó, đọc thông tin trong file để đưa các xe có trong file vào trong mảng. Nếu không có thông
	// tin gì thì không cập nhật. Nếu có lỗi không thể đọc file được thì in ra màn hình
	readSetting();
	// Sau khi update dữ liệu sẵn có của các xe ( hoặc không ) thì đi vào menu chính để người dùng nhập thông tin
	// cho các xe khác.
	Menu();
	return 0;
}

// Định nghĩa hàm nhập thông tin chức năng Display của xe
void NhapThongTinCaiDat_Display()
{
	string continues = "n";
	do {
		system("cls");
		cout << " --- INPUT DISPLAY SETTING --- " << endl;
		cout << " NHAP THONG TIN DISPLAY, XE SO " << ListVehicle.size() + 1 << endl;
		Car NewVeh;
		// Nhập thông tin chung của xe. Class Car được kế thừa trực tiếp từ lớp Setting nên có thể dùng 
		// hàm thành viên của Setting.
		NewVeh.User::inputInfoCom();
		// Check xe có tồn tại hay không
		int FoundIdx = checkCarExit(NewVeh);
		// Nếu xe không tồn tại, nhập tiếp thông tin chức năng của xe và thêm vào danh sách xe. 
		// Sau đó, cộng biến đếm Xe lên 1.
		if (FoundIdx == -1) {
			cout << "--> Xe chua ton tai " << endl;
			// Nhập thông tin Display của xe
			NewVeh.getAVN(0)->NhapAVN();
			// Đưa thông tin của xe vào List
			ListVehicle.push_back(NewVeh);
		}
		// Nếu xe đã tồn tại, nhập tiếp thông tin chức năng của xe và ghi đè tất cả thông tin chung đã nhập vào 
		// xe có trong danh sách xe. Khi này, biến đếm vẫn không thay đổi và đang chỉ đến sau phần tử cuối cùng của List.
		else {
			cout << "--> Xe da ton tai " << endl;
			// Nhập thông tin Display của xe
			NewVeh.getAVN(0)->NhapAVN();
			// Update thông tin xe
			ListVehicle[FoundIdx].updateInfo(1, NewVeh);
		}
		// Vòng lặp khi nhập không hợp lệ lựa chọn yêu cầu
		do
		{
			// Có muốn nhập thêm xe không, nếu không thì thoát khỏi chế độ nhập thông tin Display.
			cout << "--> TIEP TUC XE SO " << ListVehicle.size() + 1 << " ? (y/n): ";
			getline(cin, continues);
			// Kiểm tra nhập thông tin có hợp lệ hay không
			if (!isValidCharacter(continues))
			{
				cout << "\nLua chon phai la 'y' hoac 'n'! " << endl;
				system("pause");
			}
			// Nếu nhập không hợp lệ, cho phép nhập lại lần nữa
		} while (!isValidCharacter(continues));
		cout << endl;
		// Nếu nhập 'y', quay lại vòng lặp và tiếp tục nhập thông tin chung và chức năng Display của xe tiếp theo
	} while (continues == "y");
	// Cập nhật thông tin các xe trong mảng vào file (ghi các thông tin của các xe vào file)
	writeSetting();
}
// Định nghĩa hàm nhập thông tin chức năng Sound của xe
void NhapThongTinCaiDat_Sound()
{
	string continues = "n";
	do {
		system("cls");
		cout << " --- INPUT SOUND SETTING --- " << endl;
		cout << " NHAP THONG TIN SOUND, XE SO " << ListVehicle.size() + 1 << endl;
		Car NewVeh;
		// Nhập thông tin chung của xe
		NewVeh.User::inputInfoCom();
		// Check xe có tồn tại hay không
		int FoundIdx = checkCarExit(NewVeh);
		// Nếu xe không tồn tại, nhập tiếp thông tin chức năng của xe và thêm vào danh sách xe. 
		// Sau đó, cộng biến đếm Xe lên 1.
		if (FoundIdx == -1) {
			cout << "--> Xe chua ton tai " << endl;
			// Nhập thông tin Sound của xe
			NewVeh.getAVN(1)->NhapAVN();
			// Đưa thông tin của xe vào List
			ListVehicle.push_back(NewVeh);
		}
		// Nếu xe đã tồn tại, nhập tiếp thông tin chức năng của xe và ghi đè tất cả thông tin chung đã nhập vào 
		// xe có trong danh sách xe. Khi này, biến đếm vẫn không thay đổi và đang chỉ đến sau phần tử cuối cùng của List.
		else {
			cout << "--> Xe da ton tai " << endl;
			// Nhập thông tin Display của xe
			NewVeh.getAVN(1)->NhapAVN();
			// Update thông tin xe
			ListVehicle[FoundIdx].updateInfo(2, NewVeh);
		}
		// Vòng lặp khi nhập không hợp lệ lựa chọn yêu cầu
		do
		{
			// Có muốn nhập thêm xe không, nếu không thì thoát khỏi chế độ nhập thông tin Sound.
			cout << "--> TIEP TUC XE SO " << ListVehicle.size() + 1 << " ? (y/n): ";
			getline(cin, continues);
			// Kiểm tra nhập thông tin có hợp lệ hay không
			if (!isValidCharacter(continues))
			{
				cout << "\nLua chon phai la 'y' hoac 'n'! " << endl;
				system("pause");
			}
			// Nếu nhập không hợp lệ, cho phép nhập lại lần nữa
		} while (!isValidCharacter(continues));
		cout << endl;
		// Nếu nhập 'y', quay lại vòng lặp và tiếp tục nhập thông tin chung và chức năng Sound của xe tiếp theo
	} while (continues == "y");
	// Cập nhật thông tin các xe trong mảng vào file (ghi các thông tin của các xe vào file)
	writeSetting();
}
// Định nghĩa hàm nhập thông tin chức năng General của xe
void NhapThongTinCaiDat_General()
{
	string continues = "n";
	do {
		system("cls");
		cout << " --- INPUT GENERAL SETTING --- " << endl;
		cout << " NHAP THONG TIN GENERAL, XE SO " << ListVehicle.size() + 1 << endl;
		Car NewVeh;
		// Nhập thông tin chung của xe
		NewVeh.User::inputInfoCom();
		// Check xe có tồn tại hay không
		int FoundIdx = checkCarExit(NewVeh);
		// Nếu xe không tồn tại, nhập tiếp thông tin chức năng của xe và thêm vào danh sách xe. 
		// Sau đó, cộng biến đếm Xe lên 1.
		if (FoundIdx == -1) {
			cout << "--> Xe chua ton tai " << endl;
			system("pause");
			// Nhập thông tin General của xe
			NewVeh.getAVN(2)->NhapAVN();
			// Đưa thông tin của xe vào List
			ListVehicle.push_back(NewVeh);
		}
		// Nếu xe đã tồn tại, nhập tiếp thông tin chức năng của xe và ghi đè tất cả thông tin chung đã nhập vào 
		// xe có trong danh sách xe. Khi này, biến đếm vẫn không thay đổi và đang chỉ đến sau phần tử cuối cùng của List.
		else {
			cout << "--> Xe da ton tai " << endl;
			system("pause");
			// Nhập thông tin General của xe
			NewVeh.getAVN(2)->NhapAVN();
			// Update thông tin xe
			ListVehicle[FoundIdx].updateInfo(3, NewVeh);
		}
		// Vòng lặp khi nhập không hợp lệ lựa chọn yêu cầu
		do
		{
			// Có muốn nhập thêm xe không, nếu không thì thoát khỏi chế độ nhập thông tin General.
			cout << "--> TIEP TUC XE SO " << ListVehicle.size() + 1 << " ? (y/n): ";
			getline(cin, continues);
			// Kiểm tra nhập thông tin có hợp lệ hay không
			if (!isValidCharacter(continues))
			{
				cout << "\nLua chon phai la 'y' hoac 'n'! " << endl;
				system("pause");
			}
			// Nếu nhập không hợp lệ, cho phép nhập lại lần nữa
		} while (!isValidCharacter(continues));
		cout << endl;
		// Nếu nhập 'y', quay lại vòng lặp và tiếp tục nhập thông tin chung và chức năng General của xe tiếp theo
	} while (continues == "y");
	// Cập nhật thông tin các xe trong mảng vào file (ghi các thông tin của các xe vào file)
	writeSetting();
}
// Định nghĩa hàm xuất thông tin chức năng Display của xe
void XuatThongTinCaiDat_Display() {
	cout << " --- DISPLAY SETTING --- " << endl;
	cout << setw(20) << "TEN CHU XE"
		<< setw(25) << "Email"
		<< setw(10) << "MSCN"
		<< setw(10) << "ODO"
		<< setw(10) << "SEVICES"
		<< setw(10) << "Light"
		<< setw(10) << "Screen"
		<< setw(10) << "Taplo" << endl;
	for (int i = 0; i < ListVehicle.size(); i++) {
		// Xuất thông tin chung của xe ở Setting
		ListVehicle[i].outputInfoCom();
		// Xuất thông tin chức năng Display của xe
		ListVehicle[i].getAVN(0)->XuatAVN();
		cout << endl;
	}
}
// Định nghĩa hàm xuất thông tin chức năng Sound của xe
void XuatThongTinCaiDat_Sound() {
	cout << " --- SOUND SETTING --- " << endl;
	cout << setw(20) << "TEN CHU XE"
		<< setw(25) << "Email"
		<< setw(10) << "MSCN"
		<< setw(10) << "ODO"
		<< setw(10) << "SEVICES"
		<< setw(10) << "Media"
		<< setw(10) << "Call"
		<< setw(10) << "Navi"
		<< setw(10) << "Notify" << endl;
	for (int i = 0; i < ListVehicle.size(); i++) {
		// Xuất thông tin chung của xe ở Setting
		ListVehicle[i].outputInfoCom();
		// Xuất thông tin chức năng Sound của xe
		ListVehicle[i].getAVN(1)->XuatAVN();
		cout << endl;
	}
}
// Định nghĩa hàm xuất thông tin chức năng General của xe
void XuatThongTinCaiDat_General() {
	cout << " --- GENERAL SETTING --- " << endl;
	cout << setw(20) << "TEN CHU XE"
		<< setw(25) << "Email"
		<< setw(10) << "MSCN"
		<< setw(10) << "ODO"
		<< setw(10) << "SEVICES"
		<< setw(30) << "TimeZone"
		<< setw(20) << "Language" << endl;
	for (int i = 0; i < ListVehicle.size(); i++) {
		// Xuất thông tin chung của xe ở Setting
		ListVehicle[i].outputInfoCom();
		// Xuất thông tin chức năng General của xe
		ListVehicle[i].getAVN(2)->XuatAVN();
		cout << endl;
	}
}
// Định nghĩa hàm xuất tất cả thông tin chức năng của xe
void XuatTatCaThongTinCaiDat() {
	cout << " --- ALL SETTING --- " << endl;
	cout << setw(20) << "TEN CHU XE"
		<< setw(25) << "Email"
		<< setw(10) << "MSCN"
		<< setw(10) << "ODO"
		<< setw(10) << "SEVICES"
		<< setw(10) << "Light"
		<< setw(10) << "Screen"
		<< setw(10) << "Taplo"
		<< setw(10) << "Media"
		<< setw(10) << "Call"
		<< setw(10) << "Navi"
		<< setw(10) << "Notify"
		<< setw(30) << "TimeZone"
		<< setw(20) << "Language" << endl;
	for (int i = 0; i < ListVehicle.size(); i++) {
		// Xuất tất cả các thông tin của xe
		ListVehicle[i].outputInfoCom();
		ListVehicle[i].getAVN(0)->XuatAVN();
		ListVehicle[i].getAVN(1)->XuatAVN();
		ListVehicle[i].getAVN(2)->XuatAVN();
		cout << endl;
	}
}
// Tách chuỗi thông tin FILE.txt
const vector<string> explode(const string& s, const char& c)
{
	// Khởi tạo một chuỗi trống tên là buff 
	string buff{ "" };
	// Khai báo một vector v kiểu string
	vector<string> v;
	// Duyệt  lần lượt các kí tự trong mảng tên s kiểu string
	for (auto n : s)
	{
		// Nếu kí tự n đó không phải là kí tự mà người dùng định nghĩa để cắt chuỗi
		// Khi duyệt qua chuỗi thứ nhất và kí tự cắt
		if (n != c)
			// Thì kí tự n duyệt qua trong mảng s sẽ được đưa vào mảng buff, ngầm hiểu là chuỗi thứ nhất
			// Thì kí tự n duyệt qua trong mảng s sẽ được đưa vào mảng buff, ngầm hiểu là chuỗi thứ hai
			buff += n;
		// Nếu kí tự n là kí tự mà người dùng định nghĩa để cắt chuỗi và buff không là một chuỗi trống
		// Khi duyệt qua chuỗi thứ nhất và kí tự cắt, nó sẽ không gặp kí tự cắt nữa nên bỏ qua câu else if này
		else if (n == c && buff != "")
		{
			// Thì đưa phần tử buff vào vector v. Lúc này, vector v chứa chuỗi đầu tiên mà ta cần lấy
			v.push_back(buff);
			// Và gán mảng kí tự buff là chuỗi trống. 
			buff = "";
		}
	}
	// Khi chuỗi buff không là một chuỗi trống và hiện tại đang chứa chuỗi thứ hai của file
	if (buff != "")
		// Thì thêm chuỗi thứ hai vào vector v
		v.push_back(buff);
	// Trả về vector v
	return v;
}
// Tải chuỗi thông tin timezone.txt lên
void downloadTimeZone() {
	try {
		// Khởi tại đối tượng File tên f
		ifstream f;
		// Mở file
		f.open("timezones.txt");
		// Nếu file không mở được thì thông báo cho người dùng file chưa tồn tại
		if (f.is_open() == false) {
			throw "Khong the mo file";
		}
		// Nếu mở được file thì đọc dữ liệu trong file
		else {
			// Khởi tạo chuỗi trống tên data
			string data = "";
			// Trong khi chưa đến hết dữ liệu trong file
			while (!f.eof()) {
				// Vòng lặp đọc 32 dòng File để gán các đối tượng line vào danh sách timezone
				// Các đối tượng line chứa chuỗi thứ nhất và thứ hai
				for (int i = 0; i < 32; i++) {
					// Câu lệnh getline chỉ kết thúc khi gặp kí tự enter nên nó được dùng để đọc các dòng trong File
					getline(f, data);
					// Khởi tạo một vector tên dataLine có chứa 2 chuỗi đã cắt
					vector<string> dataLine = explode(data, '/');
					// Khai báo một đối tượng line
					DataFile line;
					// Nếu mảng vector dataLine có chứa 2 chuỗi đã được tách
					if (dataLine.size() < 2) {
						throw "Thong tin file Timezone bi loi";
					}
					else if (dataLine.size() >= 2) {
						// Thì cập nhật giá trị cho đối tượng line chứa 2 chuỗi đó
						line.setNumber(dataLine[0]);
						line.setName(dataLine[1]);
					}
					// Sau đó, gán giá trị line vào danh sách timezone
					timezoneList[i] = line;
				}
			}
		}
		// Đóng file
		f.close();
	}
	catch(const char* str){
		cout << str << endl;
		system("pause");
	}
	catch (...) {
		cout << "Loi doc file Timezone!" << endl;
		system("pause");
	}
}
// Tải chuỗi thông tin language.txt lên
void downloadLanguage() {
	try {
		// Khởi tại đối tượng File tên f
		ifstream f;
		// Mở file
		f.open("languages.txt");
		// Nếu file không mở được thì thông báo cho người dùng file chưa tồn tại
		if (f.is_open() == false) {
			throw "Khong the mo file";
		}
		// Nếu mở được file thì đọc dữ liệu trong file
		else {
			// Khởi tạo chuỗi trống tên data
			string data = "";
			// Trong khi chưa đến hết dữ liệu trong file
			while (!f.eof()) {
				// Vòng lặp đọc 30 dòng File để gán các đối tượng line vào danh sách language
				// Các đối tượng line chứa chuỗi thứ nhất và thứ hai
				for (int i = 0; i < 30; i++) {
					// Câu lệnh getline chỉ kết thúc khi gặp kí tự enter nên nó được dùng để đọc các dòng trong File
					getline(f, data);
					// Khởi tạo một vector tên dataLine có chứa 2 chuỗi đã cắt
					vector<string> dataLine = explode(data, '/');
					// Khai báo một đối tượng line
					DataFile line;
					// Nếu mảng vector dataLine có chứa 2 chuỗi đã được tách
					if(dataLine.size() < 2) {
						throw "Thong tin file Language bi loi";
					}
					else if (dataLine.size() >= 2) {
						// Thì cập nhật giá trị cho đối tượng line chứa 2 chuỗi đó
						line.setNumber(dataLine[0]);
						line.setName(dataLine[1]);
					}
					// Sau đó, gán giá trị line vào danh sách language
					languageList[i] = line;
				}
			}
		}
		// Đóng file
		f.close();
	}
	catch (const char* str) {
		cout << str << endl;
		system("pause");
	}
	catch (...) {
		cout << "Loi doc file Language!" << endl;
		system("pause");
	}
}

// Màn hình 2 nhập các chức năng của xe
void MenuInput()
{
	while (true)
	{
		// Biến input để kiểm tra regrex
		string input;
		// Biến lựa chọn chờ regrex hợp lệ, rồi mới gán input cho nó 
		int select;
		// Biến break dùng để thoát khỏi Menu2 để tới Menu
		int Brk = 0;
		// Màn hình lựa chọn chức năng nhập thông tin cho xe.
		do
		{
			system("cls");
			cout << "-------- MENU INPUT --------";
			cout << "\n1. Display setting";
			cout << "\n2. Sound setting";
			cout << "\n3. General setting";
			cout << "\n4. Exit" << endl;
			cout << "Your select: ";
			getline(cin, input);
			// Kiểm tra điều kiện nhập Menu nhập 
			// Nếu trả về false thì thông báo nhập lại
			if (!Regrex(MenuIn, input))
			{
				cout << "Vui long nhap lua chon phai la mot so tu 1 den 4" << endl;
				system("pause");
			}
			// Nếu trả về true thì đổi giá trị input thành số nguyên 
			else {
				select = stoi(input);
			}
			// Nếu trả về false thì thông báo và yêu cầu nhập lại
		} while (!Regrex(MenuIn, input));
		switch (select)
		{
		case 1:
		{
			NhapThongTinCaiDat_Display();
			break;
		}
		case 2:
		{
			NhapThongTinCaiDat_Sound();
			break;
		}
		case 3:
		{
			NhapThongTinCaiDat_General();
			break;
		}
		case 4:
		{
			Brk = 4;
			break;
		}
		}
		if (Brk == 4)
		{
			break;
		}
	}
}
// Màn hình 3 xuất thông tin của các xe
void MenuOutput()
{
	while (true)
	{
		// Biến input để kiểm tra regrex
		string input;
		// Biến lựa chọn chờ regrex hợp lệ, rồi mới gán input cho nó 
		int select;
		// Biến break dùng để thoát khỏi Menu3 để tới Menu
		int Brk = 0;
		// Màn hình lựa chọn chức năng xuất thông tin cho xe.
		do
		{
			system("cls");
			cout << "-------- MENU OUTPUT --------";
			cout << "\n1. Print Display setting information";
			cout << "\n2. Print Sound setting information";
			cout << "\n3. Print General setting information";
			cout << "\n4. Print all setting information";
			cout << "\n5. Exit";
			cout << "\nYour select: ";
			getline(cin, input);
			// Kiểm tra điều kiện nhập Menu xuất 
			// Nếu trả về false thì thông báo nhập lại
			if (!Regrex(MenuOut, input))
			{
				cout << "Vui long nhap lua chon phai la mot so tu 1 den 5" << endl;
				system("pause");
			}
			// Nếu trả về true thì đổi giá trị input thành số nguyên 
			else {
				select = stoi(input);
			}
			// Nếu trả về false thì thông báo và yêu cầu nhập lại
		} while (!Regrex(MenuOut, input));
		// Trước khi xuất mỗi thông tin của các xe thì ta cần đưa ra menu lựa chọn để người dùng chọn cách hiển thị
		// sắp xếp thông tin theo họ tên hoặc MSCN của các xe
		// Sau khi lựa chọn sắp xếp và lựa chọn xuất ra thông tin chức năng nào thì bây giờ đã có thể in ra màn hình.
		switch (select)
		{
			case 1:
			{	
				if (ListVehicle.size() > 0) {
					carSort_Menu();
					XuatThongTinCaiDat_Display();
					system("pause");
					break;
				}
				else {
					cout << "--> Hien tai khong co du lieu cua xe nao trong he thong." << endl;
					system("pause");
					break;
				}
			}
			case 2:
			{
				if (ListVehicle.size() > 0) {
					carSort_Menu();
					XuatThongTinCaiDat_Sound();
					system("pause");
					break;
				}
				else {
					cout << "--> Hien tai khong co du lieu cua xe nao trong he thong." << endl;
					system("pause");
					break;
				}
			}
			case 3:
			{
				if (ListVehicle.size() > 0) {
					carSort_Menu();
					XuatThongTinCaiDat_General();
					system("pause");
					break;
				}
				else {
					cout << "--> Hien tai khong co du lieu cua xe nao trong he thong." << endl;
					system("pause");
					break;
				}
			}
			case 4:
			{
				if (ListVehicle.size() > 0) {
					carSort_Menu();
					XuatTatCaThongTinCaiDat();
					system("pause");
					break;
				}
				else {
					cout << "--> Hien tai khong co du lieu cua xe nao trong he thong." << endl;
					system("pause");
					break;
				}
			}
			case 5:
			{
				Brk = 5;
				break;
			}
		}
		if (Brk == 5)
		{
			break;
		}
	}
}
// Màn hình 4 cho phép tìm kiếm các thông tin của xe
void MenuSearch() {
	while (true)
	{
		// Biến input để kiểm tra regrex
		string input;
		// Biến lựa chọn chờ regrex hợp lệ, rồi mới gán input cho nó 
		int select;
		// Biến break dùng để thoát khỏi Menu3 để tới Menu
		int Brk = 0;
		// Màn hình lựa chọn chức năng xuất thông tin cho xe.
		do
		{
			system("cls");
			cout << "-------- SEARCH INFORMATION --------";
			cout << "\n1. Tim kiem theo MSCN";
			cout << "\n2. Tim kiem theo ten chu xe";
			cout << "\n3. Exit";
			cout << "\nYour select: ";
			getline(cin, input);
			// Kiểm tra điều kiện nhập Menu xuất 
			// Nếu trả về false thì thông báo nhập lại
			if (!Regrex(MenuFind, input))
			{
				cout << "Vui long nhap lua chon phai la mot so tu 1 den 3" << endl;
				system("pause");
			}
			// Nếu trả về true thì đổi giá trị input thành số nguyên 
			else {
				select = stoi(input);
			}
			// Nếu trả về false thì thông báo và yêu cầu nhập lại
		} while (!Regrex(MenuFind, input));
		switch (select)
		{
		case 1:
		{
			if (ListVehicle.size() > 0) {
				system("cls");
				string temp;
				cout << "1. Tim kiem theo MSCN";
				cout << "\n-->MSCN cua xe ma ban muon tim kiem la:";
				getline(cin, temp);
				carSort(Key);
				int found = binary_Search(Key, temp);
				if (found == -1) {
					cout << "\nXe khong ton tai!!! Khong tim thay MSCN cua xe trong he thong." << endl;
				}
				else {
					cout << "\nMSCN cua xe ma ban dang tim kiem co ton tai trong he thong!" << endl;
					cout << "Thong tin cua xe la:" << endl;
					cout << setw(20) << "TEN CHU XE"
						<< setw(25) << "Email"
						<< setw(10) << "MSCN"
						<< setw(10) << "ODO"
						<< setw(10) << "SEVICES"
						<< setw(10) << "Light"
						<< setw(10) << "Screen"
						<< setw(10) << "Taplo"
						<< setw(10) << "Media"
						<< setw(10) << "Call"
						<< setw(10) << "Navi"
						<< setw(10) << "Notify"
						<< setw(30) << "TimeZone"
						<< setw(20) << "Language" << endl;
					// Xuất tất cả các thông tin của xe
					ListVehicle[found].outputInfoCom();
					ListVehicle[found].getAVN(0)->XuatAVN();
					ListVehicle[found].getAVN(1)->XuatAVN();
					ListVehicle[found].getAVN(2)->XuatAVN();
					cout << endl;
				}
				system("pause");
				break;
			}
			else {
				cout << "--> Hien tai khong co du lieu cua xe nao trong he thong." << endl;
				system("pause");
				break;
			}
		}
		case 2:
		{
			if (ListVehicle.size() > 0) {
				system("cls");
				string temp;
				cout << "\n2. Tim kiem theo Ten chu xe";
				cout << "\n-->Ten chu xe ma ban muon tim kiem la:";
				getline(cin, temp);
				carSort(Name);
				int found = binary_Search(Name, temp);
				if (found == -1) {
					cout << "\nXe khong ton tai!!! Khong tim thay Ten chu xe trong he thong." << endl;
				}
				else {
					cout << "\nTen chu xe ma ban dang tim kiem co ton tai trong he thong!" << endl;
					cout << "Thong tin cua xe la:" << endl;
					cout << setw(20) << "TEN CHU XE"
						<< setw(25) << "Email"
						<< setw(10) << "MSCN"
						<< setw(10) << "ODO"
						<< setw(10) << "SEVICES"
						<< setw(10) << "Light"
						<< setw(10) << "Screen"
						<< setw(10) << "Taplo"
						<< setw(10) << "Media"
						<< setw(10) << "Call"
						<< setw(10) << "Navi"
						<< setw(10) << "Notify"
						<< setw(30) << "TimeZone"
						<< setw(20) << "Language" << endl;
					for (int i = 0; i < ListVehicle.size(); i++) {
						if (ListVehicle[i].getCarName() == temp) {
							// Xuất tất cả các thông tin của xe
							ListVehicle[i].outputInfoCom();
							ListVehicle[i].getAVN(0)->XuatAVN();
							ListVehicle[i].getAVN(1)->XuatAVN();
							ListVehicle[i].getAVN(2)->XuatAVN();
							cout << endl;
						}
					}
				}
				system("pause");
				break;
			}
			else {
				cout << "--> Hien tai khong co du lieu cua xe nao trong he thong." << endl;
				system("pause");
				break;
			}
		}
		case 3:
		{
			Brk = 3;
			break;
		}
		}
		if (Brk == 3)
		{
			break;
		}
	}
}
// Màn hình 5 cho phép xóa các thông tin của xe
void MenuErase() {
	while (true)
	{
		// Biến input để kiểm tra regrex
		string input;
		// Biến lựa chọn chờ regrex hợp lệ, rồi mới gán input cho nó 
		int select;
		// Biến break dùng để thoát khỏi Menu3 để tới Menu
		int Brk = 0;
		// Màn hình lựa chọn chức năng xuất thông tin cho xe.
		do
		{
			system("cls");
			cout << "-------- ERASE INFORMATION --------";
			cout << "\n1. Ban muon xoa thong tin cua xe trong he thong?";
			cout << "\n2. Exit";
			cout << "\nYour select: ";
			getline(cin, input);
			// Kiểm tra điều kiện nhập Menu xuất 
			// Nếu trả về false thì thông báo nhập lại
			if (!Regrex(MenuXoa, input))
			{
				cout << "Vui long nhap lua chon phai la mot so tu 1 den 2" << endl;
				system("pause");
			}
			// Nếu trả về true thì đổi giá trị input thành số nguyên 
			else {
				select = stoi(input);
			}
			// Nếu trả về false thì thông báo và yêu cầu nhập lại
		} while (!Regrex(MenuXoa, input));
		switch (select)
		{
		case 1:
		{
			if (ListVehicle.size() > 0) {
				system("cls");
				string temp;
				cout << "1. Tim kiem theo MSCN cua xe ma ban muon xoa";
				cout << "\n-->MSCN cua xe ma ban muon tim kiem la:";
				getline(cin, temp);
				carSort(Key);
				int found = binary_Search(Key, temp);
				if (found == -1) {
					cout << "\nXe khong ton tai!!! Khong tim thay MSCN cua xe trong he thong." << endl;
				}
				else {
					cout << "\nMSCN cua xe ma ban dang tim kiem co ton tai trong he thong! Thong tin cua xe da bi xoa khoi he thong" << endl;
					ListVehicle[found].swapCar(ListVehicle[ListVehicle.size() - 1]);
					ListVehicle.erase(ListVehicle.end() - 1);
					writeSetting();
				}
				system("pause");
				break;
			}
			else {
				cout << "--> Hien tai khong co du lieu cua xe nao trong he thong." << endl;
				system("pause");
				break;
			}
		}
		case 2:
		{
			Brk = 2;
			break;
		}
		}
		if (Brk == 2)
		{
			break;
		}
	}
}
// Màn hình 1 hiển thị nhập, xuất xe
void Menu()
{
	while (true)
	{
		// Biến input để kiểm tra regrex
		string input;
		// Biến lựa chọn chờ regrex hợp lệ, rồi mới gán input cho nó 
		int select;
		// Màn hình lựa chọn chức năng nhập xuất thông tin cho xe.
		do
		{
			system("cls");
			cout << "-------- SELECT MENU --------";
			cout << "\n1. Input setting information";
			cout << "\n2. Output setting information";
			cout << "\n3. Search information";
			cout << "\n4. Erase information";
			cout << "\n5. Exit";
			cout << "\nYour select: ";
			getline(cin, input);
			// Kiểm tra điều kiện nhập Menu nhập xuất
			// Nếu trả về false thì thông báo nhập lại
			if (!Regrex(MenuIO, input))
			{
				cout << "Vui long nhap lua chon phai la mot so tu 1 den 5" << endl;
				system("pause");
			}
			// Nếu trả về true thì đổi giá trị input thành số nguyên 
			else {
				select = stoi(input);
			}
			// Nếu trả về false thì thông báo và yêu cầu nhập lại
		} while (!Regrex(MenuIO, input));
		switch (select)
		{
		case 1:
		{
			// Màn hình 2 hiển thị nhập thông tin xe
			MenuInput();
			break;
		}
		case 2:
		{
			// Màn hình 3 hiển thị xuất thông tin xe
			MenuOutput();
			break;
		}
		case 3:
		{
			// Màn hình 4 cho phép tìm kiếm thông tin xe
			MenuSearch();
			break;
		}
		case 4:
		{
			// Màn hình 5 cho phép xóa thông tin xe
			MenuErase();
			break;
		}
		case 5:
		{
			cout << "\nHe thong da tat. Hen gap lai. " << endl;
			system("pause");
			exit(0);
		}
		}
	}
}
// Hàm kiểm tra thông tin cá nhân của xe đang nhập và thông tin của xe trong danh sách hiện có. 
int checkCarExit(const Car& Veh) {
	// Tìm trong danh sách Xe hiện có.
	for (int i = 0; i < ListVehicle.size(); i++) {
		// Nếu có trùng nhau thì trả về vị trí hiện tại để cập nhật thông tin chung của xe.
		if (Veh.getPersonalKey() == ListVehicle[i].getPersonalKey()) {
			return i;
		}
	}
	// Nếu không trùng nhau thì trả về giá trị -1 và cập nhật là xe mới.
	return -1;
}
void bubblesort(Type info) {
	switch (info) {
	case Name: {
		for (int i = 0; i < ListVehicle.size() - 1; i++) {
			bool sw = false;
			for (int j = 0; j < ListVehicle.size() - i - 1; j++) {
				if (ListVehicle[j].getCarName() > ListVehicle[j + 1].getCarName()) {
					ListVehicle[j].swapCar(ListVehicle[j + 1]);
					sw = true;
				}
			}
			if (sw == false)
				break;
		}
		break;
	}
	case Key:
	{
		for (int i = 0; i < ListVehicle.size() - 1; i++) {
			bool sw = false;
			for (int j = 0; j < ListVehicle.size() - i - 1; j++) {
				if (ListVehicle[j].getPersonalKey() > ListVehicle[j + 1].getPersonalKey()) {
					ListVehicle[j].swapCar(ListVehicle[j + 1]);
					sw = true;
				}
			}
			if (sw == false)
				break;
		}
		break;
	}
	default:
		break;
	}
}
// Sử dụng hàm sắp xếp Sort trong thư viện Algorithm xe trong mảng vector ListVehicle
// Khi xuất thông tin các xe ra màn hình thì phải yêu cầu sắp xếp thông tin các xe theo mã số cá nhân hay là họ tên?
void carSort(Type carInfo) {
	// Ta có các lựa chọn Name và Key tương ứng với các lựa chọn sắp xếp theo họ tên hoặc MSCN
	switch (carInfo) {
	case Name: {
		bubblesort(Name);
		break;
	}
	case Key:
	{
		bubblesort(Key);
		break;
	}
	default:
		break;
	}
}
// Menu lựa chọn sắp xếp thông tin của các xe
void carSort_Menu()
{
	string input;
	int select;
	int Brk = 0;
	// Màn hình lựa chọn sắp xếp dữ liệu hiển thị theo MSCN hoặc theo tên chủ xe
	do
	{
		system("cls");
		cout << "-------- LUA CHON HIEN THI --------";
		cout << "\n1. Theo ma so ca nhan";
		cout << "\n2. Theo ten chu xe";
		cout << "\nYour select: ";
		getline(cin, input);
		// Kiểm tra điều kiện nhập Menu xuất 
		// Nếu trả về false thì thông báo nhập lại
		if (!Regrex(CarSort, input))
		{
			cout << "Vui long nhap lua chon phai la mot so tu nhien va chi chon trong 2 lua chon tren." << endl;
			system("pause");
		}
		// Nếu trả về true thì đổi giá trị input thành số nguyên 
		else {
			select = stoi(input);
		}
		// Nếu trả về false thì thông báo và yêu cầu nhập lại
	} while (!Regrex(CarSort, input));
	// Xuất thông tin của các xe
	switch (select)
	{
		case 1:
		{
			// Sắp xếp theo MSCN của xe
			carSort(Key);
			break;
		}
		case 2:
		{
			// Sắp xếp theo tên chủ xe
			carSort(Name);
			break;
		}
	}
}
int binary_Search(Type info, string data) {
	int l = 0, r = ListVehicle.size() - 1;
	switch (info) {
	case Key: {
		while (l < r) {
			int m = (l + r) / 2;
			if (ListVehicle[m].getPersonalKey() < data) {
				l = m + 1;
			}
			else {
				r = m;
			}
		}
		if (ListVehicle[l].getPersonalKey() == data) {
			return l;
		}
		else
			return -1;
	}
	case Name:
	{
		while (l < r) {
			int m = (l + r) / 2;
			if (ListVehicle[m].getCarName() < data) {
				l = m + 1;
			}
			else {
				r = m;
			}
		}
		if (ListVehicle[l].getCarName() == data) {
			return l;
		}
		else
			return -1;
	}
	default:
		break;
	}
}
// Ghi đối tượng Xe vào file Setting.txt
void writeSetting() {
	try {
		// Khởi tại đối tượng File tên f
		ofstream f;
		// Mở file
		f.open("Setting.txt", ios::out);
		// Nếu file không mở được thì thông báo cho người dùng file chưa tồn tại
		if (f.is_open() == false) {
			throw exception();
		}
		// Nếu mở được file thì đọc dữ liệu trong file
		else {
			// Đọc thông tin của tất cả các xe trong mảng để ghi vào file
			for (int i = 0; i < ListVehicle.size(); i++) {
				// CommonInfo
				string line = "Common:";
				line.append(ListVehicle[i].getCarName());
				line.append(",");
				line.append(ListVehicle[i].getEmail());
				line.append(",");
				line.append(ListVehicle[i].getPersonalKey());
				line.append(",");
				line.append(to_string(ListVehicle[i].getODO()));
				line.append(",");
				line.append(to_string(ListVehicle[i].getServiceRemind()));
				// Display
				line.append(";Display:");
				if (Display *d = dynamic_cast<Display*>(ListVehicle[i].getAVN(0))) {
					line.append(to_string(d->get_light_level()));
					line.append(",");
					line.append(to_string(d->get_screen_light_level()));
					line.append(",");
					line.append(to_string(d->get_taplo_light_level()));
				}
				// Sound
				line.append(";Sound:");
				if (Sound* s = dynamic_cast<Sound*>(ListVehicle[i].getAVN(1))) {
					line.append(to_string(s->get_media_level()));
					line.append(",");
					line.append(to_string(s->get_call_level()));
					line.append(",");
					line.append(to_string(s->get_navi_level()));
					line.append(",");
					line.append(to_string(s->get_notification_level()));
				}	
				// General
				line.append(";General:");
				if (General* g = dynamic_cast<General*>(ListVehicle[i].getAVN(2))) {
					line.append(g->get_timeZone());
					line.append(",");
					line.append(g->get_language());
				}				
				f << line;
				// Khi đưa thông tin các xe vào mỗi dòng thì đều ghi vào cuối dòng trong file kí tự endl để xuống dòng
				// ngoại trừ dòng cuối cuối cùng(hay cũng là xe cuối cùng) thì không ghi endl.
				if (i != ListVehicle.size() - 1) {
					f << endl;
				}
			}
		}
		// Đóng file
		f.close();
	}
	catch (exception e) {
		cout << "Loi: " << e.what();
	}
	catch(...){
		cout << "Khong the ghi file";
	}
}
// Đọc đối tượng Xe từ file Setting.txt
void readSetting() {
	try {
		// Khởi tại đối tượng File tên f
		ifstream f;
		// Mở file
		f.open("Setting.txt", ios::in);
		// Nếu file không mở được thì thông báo cho người dùng file chưa tồn tại
		if (f.is_open() == false) {
			throw exception();
		}
		// Nếu mở được file thì đọc dữ liệu trong file
		else {
			string lineInfo = "";
			while (!f.eof()) {
				Car NewVeh;
				getline(f, lineInfo);
				// Khởi tạo một vector tên dataLine để đọc dữ liệu của một hàng trong file và sẽ chia thành các chuỗi bởi kí 
				// tự ';' và đưa vào vector. Ta có được 4 chuỗi chứa 4 thông tin về commonInfo, Display, Sound và General.
				vector<string> dataLine = explode(lineInfo, ';');
				// Kiểm tra nếu mảng vector dataLine có chứa 4 chuỗi đã được tách thì thực hiện câu lệnh if.
				if (dataLine.size() < 4) {
					throw "Thong tin luu tru commonInfo hoac cac chuc nang cua xe khong co nen khong the dua vao danh sach xe!";
				}
				else if (dataLine.size() >= 4) {
					for (int i = 0; i < 4; i++) {
						// Lấy lần lượt 4 chuỗi thông tin commonInfo, Display, Sound và General.
						string carStr = dataLine[i];
						// Chia chuỗi (trong mỗi 4 chuỗi) thành 2 chuỗi nữa, chuỗi đầu tiên là "Thông tin của xe:" và chuỗi thứ hai
						// chứa dữ liệu của thông tin đó.
						vector<string> infoStr = explode(carStr, ':');
						if (infoStr.size() < 2) {
							throw "Gia tri hoac so lieu cua commonInfo hoac cac chuc nang cua xe bi thieu!";
						}
						else if (infoStr.size() >= 2) {
							if (i == 3) {
								infoStr[1].append(":");
								infoStr[1].append(infoStr[2]);
							}
							// Gán chuỗi dữ liệu của CommonInfo vào 1 biến dataCommon để tách các dữ liệu riêng lẻ ra.
							string dataStr = infoStr[1];
							// Tách dữ liệu và đưa vào vector data1
							vector<string> data = explode(dataStr, ',');
							// Nếu đang tách chuỗi thứ "i + 1" trong vector dataLine thì lựa chọn các trường hợp để gán
							switch (i)
							{
							case 0:
								if (data.size() < 5) {
									throw "So lieu cua commonInfo cua mot xe nao do khong day du";
								}
								else if (data.size() >= 5) {
									// Gán dữ liệu Common vào đối tượng NewVeh
									NewVeh.setCarName(data[0]);
									NewVeh.setEmail(data[1]);
									NewVeh.setPersonalKey(data[2]);
									NewVeh.setODO(stoi(data[3]));
									NewVeh.setServiceRemind(stoi(data[4]));
								}
								break;
							case 1:
								if (data.size() < 3) {
									throw "So lieu cua Display cua mot xe nao do  khong day du";
								}
								else if (data.size() >= 3) {
									// Gán dữ liệu Common vào đối tượng NewVeh							
									if (Display* d = dynamic_cast<Display*>(NewVeh.getAVN(0))) {
										d->set_light_level(stoi(data[0]));
										d->set_screen_light_level(stoi(data[1]));
										d->set_taplo_light_level(stoi(data[2]));
									}
									break;
							case 2:
								if (data.size() < 4) {
									throw "So lieu cua Sound  cua mot xe nao do khong day du";
								}
								else if (data.size() >= 4) {
									// Gán dữ liệu Common vào đối tượng NewVeh								
									if (Sound* s = dynamic_cast<Sound*>(NewVeh.getAVN(1))) {
										s->set_media_level(stoi(data[0]));
										s->set_call_level(stoi(data[1]));
										s->set_navi_level(stoi(data[2]));
										s->set_notification_level(stoi(data[3]));
									}
								}
								break;
							case 3:
								if (data.size() < 2) {
									throw "So lieu cua General cua mot xe nao do khong day du";
								}
								else if (data.size() >= 2) {
									// Gán dữ liệu Common vào đối tượng NewVeh								
									if (General* g = dynamic_cast<General*>(NewVeh.getAVN(2))) {
										g->set_timeZone(data[0]);
										g->set_language(data[1]);
									}
								}
								break;
							default:
								break;
								}
							}
						}
					}
					// Đưa đối tượng xe mới đọc từ file Setting.txt vào một mảng List<Car> 
					ListVehicle.push_back(NewVeh);
				}
			}
			// Đóng file
			f.close();
			cout << "Da tai thong tin cac xe trong file len!" << endl;
		}
	}
	catch(exception e){
		cout << "Khong the mo file hoac file khong ton tai" << endl;
	}
	catch (const char *str) {
		cout << str << endl;
	}
	catch (...) {
		cout << "Khong the doc file" << endl;
	}
	system("pause");
}