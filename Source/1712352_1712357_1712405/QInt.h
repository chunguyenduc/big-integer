#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>

using namespace std;

class QInt
{
private:
	vector<bool> arrBits;
	int soBitCanDung;//Lúc xuất thì không cần xuât đủ 128 bit mà chỉ cần xuất ra đủ số bit cần thiết
public:
	//Khởi tạo QInt bằng 0
	QInt();

	//Hàm tìm vị trí bit 1 đầu tiên để output biết mà xuất ra từ vị trí đó
	void checkSoBitCanDung();
	
	//Trước khi chuyển từ các hệ cơ số thì QInt phải bằng 0, hàm này dùng để reset QInt = 0
	void resetData();

	//Chuyển chuỗi thập phân thành QInt
	void chuyenTuChuoiThapPhan(string);

	//Phép chia 2 để thực hiện hàm chuyenTuChuoiThapPhan()
	string div2(string);

	//Chuyển chuỗi nhị phân thành QInt
	void chuyenTuChuoiNhiPhan(string);

	//Chuyển chuỗi thập lục phân phân thành QInt
	void chuyenTuChuoiThapLucPhan(string);

	//Chuyển từ QInt thành chuỗi thập lục phân
	string chuyenSangThapLucPhan();

	//Chuyển từ QInt thành chuỗi thập phân
	string chuyenSangThapPhan();

	//Hàm tính lũy thừa số lớn
	string tinhMu(int, int);

	//Hàm cộng các chuỗi lũy thừa
	string cong(string a, string b);

	//Xuất QInt theo dạng nhị phân ra file
	void xuatNhiPhan(ofstream&);

	//Xuất QInt theo dạng thập lục phân ra file
	void xuatThapLucPhan(ofstream&);

	//Xuất QInt theo dạng thập phân ra file
	void xuatThapPhan(ofstream&);
	
	//Toán tử NOT
	void chuyenThanhBu1();

	//Dạng bù 2
	void chuyenThanhBu2();

	//Phép gán
	QInt& operator=( const QInt&);

	//Toán tử AND
	void OR(const QInt&);

	//Toán tử OR
	void AND(const QInt&);

	//Toán tử XOR
	void XOR(const QInt&);

	//Phép cộng
	QInt operator+(const QInt&);

	//Phép trừ
	QInt operator-(const QInt&);

	//Phép nhân
	QInt operator*(const QInt&);

	//Phép chia
	QInt operator/(const QInt&);

	//Phép dịch trái
	QInt operator<<(int);

	//Phép dịch phải
	QInt operator>>(int);

	//Phép quay trái
	void rol();

	//Phép quay phải
	void ror();
};

