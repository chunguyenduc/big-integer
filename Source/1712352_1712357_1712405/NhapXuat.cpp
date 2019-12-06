#include "NhapXuat.h"
#include "Qint.h"

//input có thể có 4 chuỗi hoặc 3 chuỗi, hàm này dùng để tính số chuỗi
int demSoChuoi(string str)
{
	//Đếm số khoảng trắng
	int count = 0;
	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] == ' ')
			count++;
	}
	//Cộng 1 là ra số chuỗi
	return count + 1;
}

//operator+, operator-, operator*, operator/
void congTruNhanChia(ofstream& out, string base, string num1, string op, string num2)
{
	QInt a, b, kq;
	//Chuyển chuỗi từ các hệ thành QInt
	if (base == "2")
	{
		a.chuyenTuChuoiNhiPhan(num1);
		b.chuyenTuChuoiNhiPhan(num2);
	}
	else if (base == "10")
	{
		a.chuyenTuChuoiThapPhan(num1);
		b.chuyenTuChuoiThapPhan(num2);
	}
	else
	{
		a.chuyenTuChuoiThapLucPhan(num1);
		b.chuyenTuChuoiThapLucPhan(num2);
	}

	//Lam phep tinh
	if (op == "+")
		kq = a + b;
	else if (op == "-")
		kq = a - b;
	else if (op == "*")
		kq = a * b;
	else
		kq = a / b;

	//Xuat ra file
	if (base == "2")
		kq.xuatNhiPhan(out);
	else if (base == "10")
		kq.xuatThapPhan(out);
	else
		kq.xuatThapLucPhan(out);
}

//operator>>, operator<<
void dichTraiPhai(ofstream& out, string base, string num, string op, string n)
{
	//Chuyển chuỗi các hệ thành QInt
	QInt a;
	if (base == "2")
		a.chuyenTuChuoiNhiPhan(num);
	else if (base == "10")
		a.chuyenTuChuoiThapPhan(num);
	else
		a.chuyenTuChuoiThapLucPhan(num);

	//Đọc số lần dịch
	int count;
	istringstream ss(n);
	ss >> count;

	if (op == "<<")
		a = a << count;
	else
		a = a >> count;

	//Xuất theo các hệ cơ số ra file
	if (base == "2")
		a.xuatNhiPhan(out);
	else if (base == "10")
		a.xuatThapPhan(out);
	else
		a.xuatThapLucPhan(out);
}

//AND, OR, XOR
void toanTuLogic(ofstream& out, string base, string num1, string op, string num2)
{
	//Chuyển chuỗi từ ác hệ thành QInt
	QInt a, b;
	if (base == "2")
	{
		a.chuyenTuChuoiNhiPhan(num1);
		b.chuyenTuChuoiNhiPhan(num2);
	}
	else if (base == "10")
	{
		a.chuyenTuChuoiThapPhan(num1);
		b.chuyenTuChuoiThapPhan(num2);
	}
	else
	{
		a.chuyenTuChuoiThapLucPhan(num1);
		b.chuyenTuChuoiThapLucPhan(num2);
	}

	//Lam phep tinh
	if (op == "&")
		a.AND(b);
	else if (op == "|")
		a.OR(b);
	else if (op == "^")
		a.XOR(b);

	//Xuat ra file
	if (base == "2")
		a.xuatNhiPhan(out);
	else if (base == "10")
		a.xuatThapPhan(out);
	else
		a.xuatThapLucPhan(out);
}

//Chuyển các hệ cơ số
void chuyenCoSo(ofstream& out, string base1, string base2, string num)
{
	//Chuyển chuỗi từ các hệ thành Qint
	QInt a;
	if (base1 == "2")
		a.chuyenTuChuoiNhiPhan(num);
	else if (base1 == "10")
		a.chuyenTuChuoiThapPhan(num);
	else
		a.chuyenTuChuoiThapLucPhan(num);

	//Chuyển từ QInt ra các hệ cơ số rồi xuất ra file
	if (base2 == "2")
		a.xuatNhiPhan(out);
	else if (base2 == "10")
		a.xuatThapPhan(out);
	else
		a.xuatThapLucPhan(out);
}

//ror, rol, NOT
void not_quayTraiPhai(ofstream& out, string base, string op, string num)
{
	//Chuyển chuỗi từ các hệ cơ số thành QInt
	QInt a;
	if (base == "2")
		a.chuyenTuChuoiNhiPhan(num);
	else if (base == "10")
		a.chuyenTuChuoiThapPhan(num);
	else
		a.chuyenTuChuoiThapLucPhan(num);

	//Thực hiện các toán tử
	if (op == "rol")
		a.rol();
	else if (op == "ror")
		a.ror();
	else
		a.chuyenThanhBu1();

	//Xuất ra file theo các hệ cơ số
	if (base == "2")
		a.xuatNhiPhan(out);
	else if (base == "10")
		a.xuatThapPhan(out);
	else
		a.xuatThapLucPhan(out);
}