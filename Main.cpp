#include "QInt.h"


int main()
{
	QInt num1, num2, tong, hieu, tich, thuong;
	
	string a = "133456334589665523";
	string b = "41225452236965523";
	
	num1.chuyenTuChuoiThapPhan(a);
	num2.chuyenTuChuoiThapPhan(b);
	
	cout << "Number 1: "; num1.xuatThapPhan();
	cout << "Number 2: "; num2.xuatThapPhan();
	
	cout << endl;
	
	tong = num1 + num2;
	cout << "Sum: "; tong.xuatThapPhan();
	
	
	hieu = num1 - num2;
	cout << "Diff: "; hieu.xuatThapPhan();
	
	tich = num1 * num2;
	cout << "Product: "; tich.xuatThapPhan();
	
	thuong = num1 / num2;
	cout << "Division: "; thuong.xuatThapPhan();
	
	
	return 0;
}