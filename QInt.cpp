#include "QInt.h"

//Hàm khỏi tạo
QInt::QInt()
{
	arrBits.resize(128, false);
	soBitCanDung = 1;
}


//Khi chuyển từ chuỗi input sang QInt thì chỉ có 1 số bit nhất định được cập nhật, còn lại thì không
//Nên phải reset tất cả các bit thành 0
void QInt::resetData()
{
	QInt a;//Constructor, mặc định là 128 bit 0
	*this = a;//operator=
}

//Hàm chuyển từ chuỗi thập phân qua kiểu QInt
void QInt::chuyenTuChuoiThapPhan(string s)
{
	resetData();

	//Kiểm tra chuỗi âm hay dương
	int i = 0;
	bool laSoAm = s[0] == '-' ? 1 : 0;
	if (laSoAm)
		s.erase(0, 1);

	while (s != "0") 
	{
		int len = s.length() - 1;
		int bit = (s[len] - 48) % 2;
		arrBits[i] = bit;
		s = div2(s);
		i++;
	}
	soBitCanDung = i;

	if (laSoAm)
		chuyenThanhBu2();
}

void QInt::checkSoBitCanDung()
{
	bool found = 0;
	for (int i = 127; i >= 0; i--)
	{
		//Tìm thấy bit 1 thì note lại rồi dừng
		if (arrBits[i] == 1)
		{
			soBitCanDung = i + 1;
			found = 1;
			break;
		}
	}
	if (!found)
		soBitCanDung = 1;
}

//Hàm chuyển thành bù 1, chức năng giống như toán tử NOT
void QInt::chuyenThanhBu1()
{
	//Đảo bit
	for (int i = 0; i < 128; i++)
		arrBits[i] = !arrBits[i];

	checkSoBitCanDung();
}

//Hàm chuyển thành bù 2, để chuyển số dương thành số âm và ngược lại
void QInt::chuyenThanhBu2()
{
	chuyenThanhBu1();

	QInt temp;
	temp.chuyenTuChuoiNhiPhan("1");

	*this = *this + temp;
}

//Hàm chuyển từ chuỗi nhị phân sang kiểu QInt
void QInt::chuyenTuChuoiNhiPhan(string s)
{
	resetData();

	int len = s.length();
	for (int i = len - 1; i >= 0; i--)
	{
		arrBits[len - i - 1] = s[i] - '0';//Gán ngược lại vì bit phải nhất của chuỗi là bit nhỏ nhất của QInt
	}

	//Tìm số bit cần dùng vì input có thể dư số 0
	int i;
	for (i = len - 1; i >= 0; i--)
	{
		if (arrBits[i] == 1)
			break;
	}
	soBitCanDung = i + 1;
}

//Hàm chuyển từ chuỗi thập lục phân sang QInt
void QInt::chuyenTuChuoiThapLucPhan(string str) 
{
	resetData();

	//Kiểm tra chuỗi input
	while (str[0] == '0')
		str.erase(0, 1);

	if (str == "")
		return;

	int j;
	//Xét từ phải qua trái
	for (int i = str.length() - 1; i >= 0; i--)
	{
		j = (str.length() - i - 1) * 4;
		if (str[i] == '0')
		{
			//o là 0000
			arrBits[j] = 0;
			arrBits[++j] = 0;
			arrBits[++j] = 0;
			arrBits[++j] = 0;
		}
		else if (str[i] == '1')
		{
			//1 là 0001
			arrBits[j] = 1;
			arrBits[++j] = 0;
			arrBits[++j] = 0;
			arrBits[++j] = 0;
		}
		else if (str[i] == '2')
		{
			//2 là 0010
			arrBits[j] = 0;
			arrBits[++j] = 1;
			arrBits[++j] = 0;
			arrBits[++j] = 0;
		}
		else if (str[i] == '3')
		{
			//3 là 0011
			arrBits[j] = 1;
			arrBits[++j] = 1;
			arrBits[++j] = 0;
			arrBits[++j] = 0;
		}
		else if (str[i] == '4')
		{
			//4 là 0100
			arrBits[j] = 0;
			arrBits[++j] = 0;
			arrBits[++j] = 1;
			arrBits[++j] = 0;
		}
		else if (str[i] == '5')
		{
			//5 là 0101
			arrBits[j] = 1;
			arrBits[++j] = 0;
			arrBits[++j] = 1;
			arrBits[++j] = 0;
		}
		else if (str[i] == '6')
		{
			//6 là 0110
			arrBits[j] = 0;
			arrBits[++j] = 1;
			arrBits[++j] = 1;
			arrBits[++j] = 0;
		}
		else if (str[i] == '7')
		{
			//7 là 0111
			arrBits[j] = 1;
			arrBits[++j] = 1;
			arrBits[++j] = 1;
			arrBits[++j] = 0;
		}
		else if (str[i] == '8')
		{
			//8 là 1000
			arrBits[j] = 0;
			arrBits[++j] = 0;
			arrBits[++j] = 0;
			arrBits[++j] = 1;
		}
		else if (str[i] == '9')
		{
			//9 là 1001
			arrBits[j] = 1;
			arrBits[++j] = 0;
			arrBits[++j] = 0;
			arrBits[++j] = 1;
		}
		else if (str[i] == 'A')
		{
			//A là 1010
			arrBits[j] = 0;
			arrBits[++j] = 1;
			arrBits[++j] = 0;
			arrBits[++j] = 1;
		}
		else if (str[i] == 'B')
		{
			//B là 1011
			arrBits[j] = 1;
			arrBits[++j] = 1;
			arrBits[++j] = 0;
			arrBits[++j] = 1;
		}
		else if (str[i] == 'C')
		{
			//C là 1100
			arrBits[j] = 0;
			arrBits[++j] = 0;
			arrBits[++j] = 1;
			arrBits[++j] = 1;
		}
		else if (str[i] == 'D')
		{
			//D là 1101
			arrBits[j] = 1;
			arrBits[++j] = 0;
			arrBits[++j] = 1;
			arrBits[++j] = 1;
		}
		else if (str[i] == 'E')
		{
			//E là 1110
			arrBits[j] = 0;
			arrBits[++j] = 1;
			arrBits[++j] = 1;
			arrBits[++j] = 1;
		}
		else if (str[i] == 'F')
		{
			//F là 1111
			arrBits[j] = 1;
			arrBits[++j] = 1;
			arrBits[++j] = 1;
			arrBits[++j] = 1;
		}
	}
	checkSoBitCanDung();
}

//Xuất QInt theo dạng nhị phân
void QInt::xuatNhiPhan()
{
	for (int i = soBitCanDung-1; i >= 0; i--)
	{
		cout << arrBits[i];
	}
	cout << '\n';
}

//Chuyển từ QInt sang thập lục phân
string QInt::chuyenSangThapLucPhan()
{
	string result;

	//Gom 4 bit lại chuyển thành thập phân, sau đó chuyển sang thập lục phân

	int tong4Bit = 0;
	int i = 0;


	while (i < soBitCanDung || i % 4 != 0)
	{
		//Chuyển thành thập phân
		tong4Bit += arrBits[i] * (int)pow(2, i % 4);

		//Khi i đã chạy qua đủ 4 bit thì chuyển sang thập lục phân
		if ((i + 1) % 4 == 0)
		{
			if (tong4Bit < 10)
				result += tong4Bit + '0';
			else //thập phân >= 10 thì chuyển thành A, B, C, ...
				result += tong4Bit - 10 + 'A';
			tong4Bit = 0;
		}
		i++;
	}
	return result;
}

//Xuất Qint theo dạng thập lục phân
void QInt::xuatThapLucPhan()
{
	string s = chuyenSangThapLucPhan();

	//Đảo chuỗi để in ra theo thứ tự bit lớn đến bit nhỏ
	reverse(s.begin(), s.end());
	cout << s << '\n';
}

string QInt::div2(string number)
{
	string ans;

	//Neu so am
	int laSoAm = 0;
	if (number[0] == '-')
	{
		laSoAm = 1;
		number.erase(0, 1);//Xóa dấu trừ đưa về số dương làm bình thường
	}

	//Nếu chữ số ngoài cùng bằng 0 thì có thể là number = 0 hoặc number dư số 0 ở đầu
	if (number[0] == '0')
	{
		while (number[0] == '0')
		{
			number.erase(0, 1);
		}
		//Nếu chuỗi rỗng tức là chuỗi toàn 0 nên kết quả = 0
		if (number == "")
		{
			number = "0";	//Gán lại number = 0 để tiện cho hàm chuyển từ thập phân
			return number;
		}
	}

	//Lấy từng số từ trái qua phải chia cho 2
	int idx = 0;
	int temp = number[idx] - '0';//temp là chữ số đầu tiên

	//Nếu temp >= 2 thì đem đi chia 2 bình thường
	//Còn nếu bằng 1 thì mượn số đằng sau để chia được cho 2
	if (temp == 1)
	{
		//Nhưng khi không có số nào đằng sau thì kết quả bằng 0
		if (number.length() == 1)
			return "0";
		else
		{
			idx++;
			temp = 10 + (number[idx] - '0');
		}
	}

	//Khi chia đủ các hàng thì kết thúc
	while (idx < number.length())
	{
		//Kết quả của temp / 2 được nối vào đuôi chuỗi ans 
		ans += (temp / 2) + '0';

		//Kéo chữ số tiếp theo xuống để chia tiếp
		idx++;
		temp = (temp % 2) * 10 + number[idx] - '0';
	}

	if (laSoAm)	return '-' + ans;
	return ans;
}

//Phép gán
QInt& QInt::operator=(const QInt& a)
{
	if (this != &a)
	{
		//Vector gán thẳng vầy được
		arrBits = a.arrBits;
		soBitCanDung = a.soBitCanDung;
	}
	return *this;
}

//Hàm tính mũ cho số thập phân lớn
string QInt::tinhMu(int n, int exp)
{
	//Chuyển số n thành chuỗi
	string n_string;
	ostringstream convert;
	convert << n;
	n_string = convert.str();
	//Kiểm tra điều kiện để thực hiện là exp >=0
	//Nếu exp <= 0 trả về n_string
	if (exp < 0) return  n_string;
	if (exp == 0) return "1";
	else {
		//Chuyển phép tính mũ thành phép cộng
		//Vd 2^3 = 2*2*2 = (2+2)*2 = (4 + 4)
		//Bug o cho ham cong khi cong ra ket qua lon hon length 2 so ban dau (vd 5+5 = 10 =>bug)
		while (exp > 1) {
			string temp = n_string;
			for (int i = 1; i < n; i++) {
				n_string = cong(n_string, temp);
			}
			exp -= 1;
		}
	}
	return n_string;
}

//Hàm cộng 2 chuỗi số thập phân
string QInt::cong(string a, string b)
{
	//So sánh 2 chuỗi a,b. Chuỗi nào ngắn hơn thì thêm n (với n = độ dài chuỗi lớn - độ dài chuỗi bé ) chữ 0 vào đầu chuỗi, tạo thành 2 chuỗi bằng nhau để thực hiện + theo hàng(đơn vị,chục,trăm,...)
	if (a.length() > b.length())
		b.insert(0, a.length() - b.length(), '0');
	else if (a.length() < b.length())
		a.insert(0, b.length() - a.length(), '0');
	//Do 2 chuỗi đã có độ dài như nhau nên gán độ dài chuỗi a vào biến dai.
	int dai = a.length();
	int *temp = new int[dai];//mảng int lưu kết quả.
	for (int i = 0; i < dai; i++)
		temp[i] = 0;// cho toàn bộ ptử trong mảng temp = 0.
	int nho = 0;
	for (int i = dai - 1; i >= 0; i--)
	{
		temp[dai - i - 1] = (a[i] - 48) + (b[i] - 48) + temp[dai - i - 1] + nho;
		if (temp[dai - i - 1] >= 10)// nếu giá trị vừa tính lớn hơn 10 tức phải nhớ 1.
		{
			temp[dai - i - 1] = temp[dai - i - 1] - 10;//Lấy giá trị vừa tính - 10 để ra giá trị cần lưu.
			nho = 1;//Lưu nhớ để tính tiếp.
		}
		else
			nho = 0;
	}
	string c;//chuỗi lưu kết quả cuối
	c.resize(dai);

	//Lưu mảng qua chuỗi
	//Nếu như tính xong không còn nhớ thì làm bình thường
	if (nho == 0)
	{
		for (int i = 0; i < dai; i++)
		{
			c[a.length() - i - 1] = temp[i] + 48;
		}
	}
	//Nếu vẫn còn nhớ 1 thì tăng độ dài chuỗi lên 1 rồi gán 1 vào vị trí đầu
	else if (nho == 1)
	{
		c.resize(dai + 1);

		for (int i = 0; i < dai; i++)
		{
			c[dai - i] = temp[i] + 48;
		}
		c[0] = nho + 48;
	}
	delete[] temp;
	return c;
}

//Hàm chuyển từ kiểu QInt sang thập phân
string QInt::chuyenSangThapPhan()
{
	//Ý tưởng là làm như thuật toán đã học
	//Nếu như mà số âm thì bù 2 thành số dương xong thêm dấu trừ ở đầu
	//Bù 2 thì sẽ làm thay đổi giá trị của this nên ta sẽ gán giá trị vào biến QInt khác
	QInt a = *this;

	//Chuyển âm thành dương
	bool laSoAm = arrBits[127] == 1 ? 1 : 0;
	if (laSoAm)
		a.chuyenThanhBu2();

	string res = "0";

	//Kết quả thập phân bằng tổng các lũy thừa 2 của vị trí bit 1
	for (int i = a.soBitCanDung - 1; i >= 0; i--)
	{
		if (a.arrBits[i] == 1)
			res = cong(res, tinhMu(2, i));
	}

	//Nếu là số âm thì thêm dấu trừ ở đầu
	if (laSoAm)
		return '-' + res;
	//Không thì thôi
	return res;
}

//Xuất QInt theo dạng thập phân
void QInt::xuatThapPhan()
{
	cout << chuyenSangThapPhan() << '\n';
}

//Phép AND
void QInt::AND(const QInt& bigNum) 
{
	vector<bool> temp;
	for (int i = 0; i < 128; i++) 
	{
		//Nếu cả 2 bool ở vị trí index true thì flag là true
		bool flag = (this->arrBits[i] && bigNum.arrBits[i]) ? true : false;
		temp.push_back(flag);
	}

	this->arrBits = temp;
	checkSoBitCanDung();
}

//Phep OR
void QInt::OR(const QInt& bigNum) 
{
	vector<bool> temp;
	for (int i = 0; i < 128; i++) 
	{
		//Nếu 1 trong 2 bool ở index là true thì flag là true
		bool flag = (this->arrBits[i] || bigNum.arrBits[i]) ? true : false;
		temp.push_back(flag);
	}
	this->arrBits = temp;
	//Số nào dài hơn thì lấy độ dài của nó làm số bit cần dùng luôn
	soBitCanDung = soBitCanDung > bigNum.soBitCanDung ? soBitCanDung : bigNum.soBitCanDung;
}

//Phép XOR
void QInt::XOR(const QInt& bigNum) 
{
	vector<bool> temp;
	for (int i = 0; i < 128; i++)
	{
		//Nếu 2 bit đang xét giống nhau là false ngược lại là true.
		bool flag = (this->arrBits[i] == bigNum.arrBits[i]) ? false : true;
		temp.push_back(flag);
	}
	this->arrBits = temp;
	checkSoBitCanDung();
}


//Hàm cộng 2 số
QInt QInt::operator+(const QInt& a)
{
	//Gọi biến trả về
	QInt kq;
	//Biến nhớ, chưa cộng nên mặc định là 0
	bool nho = 0;
	//Số nào nhiều bit hơn thì lấy độ dài là số đó
	int n;
	if (soBitCanDung > a.soBitCanDung)
		n = soBitCanDung;
	else
		n = a.soBitCanDung;
	//kq.arrBits.resize(n);
	for (int i = 0; i < n; i++)
	{
		//Nếu như nhớ đang là 0
		if (nho == 0)
		{
			//Thực hiện phép + lưu vào kq như bình thường.
			kq.arrBits[i] = this->arrBits[i] + a.arrBits[i];
			//Nếu như phép cộng là với 2 bit 1
			if ((this->arrBits[i] == 1) && (a.arrBits[i] == 1))
			{
				//Thì giá trị lưu lại là 0, gán biến nhớ là 1.
				kq.arrBits[i] = 0;
				nho = 1;
			}
			//Những trường hợp cộng khác thì cho biến nhớ là 0.
			else
				nho = 0;
		}
		//Nếu như biến nhớ là 1
		else if (nho == 1)
		{
			//Nếu như bit 1 và bit 0 cộng với nhau
			if (((this->arrBits[i] == 1) && (a.arrBits[i] == 0)) || ((this->arrBits[i] == 0) && (a.arrBits[i] == 1)))
			{
				//Thì lưu kết quả là 0 và gán nho = 1.
				kq.arrBits[i] = 0;
				nho = 1;
			}
			//Nếu như 2 bit 1 cộng với nhau
			if ((this->arrBits[i] == 1) && (a.arrBits[i] == 1))
			{
				//Thì lưu kết quả là 1 và gán nho = 1.
				kq.arrBits[i] = 1;
				nho = 1;
			}
			//Nếu như 2 bit 0 cộng với nhau
			if ((this->arrBits[i] == 0) && (a.arrBits[i] == 0))
			{
				// 0 + 0 + nho = 1, lưu 1 vào kết quả và gán nho = 0.
				kq.arrBits[i] = 1;
				nho = 0;
			}
		}
	}
	//Nếu cộng hết mà vẫn còn nhớ 1 thì tăng độ dài lên để chứa thêm 1 bit 1
	if (nho == 1)
	{
		if (n < 128)
		{
			//Tăng độ dài lên để chứa thêm 1 bit 1
			n++;
			kq.arrBits[n - 1] = 1;
			//Sau đó cập nhật số bit cần dùng
			kq.soBitCanDung = n;
		}
		//Bằng 128 rồi thì không cần tăng độ dài thêm nữa
		else
		{
			kq.checkSoBitCanDung();
		}
	}
	//Còn nếu mà không nhớ thì số bit cần dùng vẫn cứ bằng độ dài nãy giờ xét
	else
		kq.soBitCanDung = n;
	return kq;
}

//Hàm trừ 2 số
QInt QInt::operator-(const QInt& a)
{
	QInt kq, temp = a;
	//Chuyển số bị trừ thành dạng bù 2
	temp.chuyenThanhBu2();
	//Thực hiện phép cộng
	kq = *this + temp;

	return kq;
}

//Hàm dịch trái
QInt QInt::operator<<(int n)
{
	QInt a = *this;
	for (int i = 0; i < n; i++)
	{
		for (int i = 127; i > 0; i--) 
		{
			a.arrBits[i] = a.arrBits[i - 1];
		}
		a.arrBits[0] = 0;
	}

	a.checkSoBitCanDung();

	return a;
}

//Hàm dịch phải
QInt QInt::operator>>(int n)
{
	QInt a = *this;
	for (int i = 0; i < n; i++)
	{
		for (int i = 0; i < 127; i++)
		{
			a.arrBits[i] = a.arrBits[i + 1];
		}
		//Biến dấu dựa vào bit dấu cũ
		if (a.arrBits[126] == 1)
			a.arrBits[127] = 1;
		else
			a.arrBits[127] = 0;
	}

	a.checkSoBitCanDung();
	return a;
}

//Hàm quay trái
void QInt::rol()
{
	bool temp = arrBits[127];//Lưu lại bên trái cùng
	for (int i = 127; i > 0; i--) 
	{
		arrBits[i] = arrBits[i - 1];//Chuyển tất cả các bit qua trái
	}
	arrBits[0] = temp;//Gán vị trí phải cùng = temp
	checkSoBitCanDung();

}

//Hàm quay phải
void QInt::ror()
{
	//Chắc tương tự
	bool temp = arrBits[0];//Lưu lại bên phải cùng
	for (int i = 0; i < 127; i++)
	{
		arrBits[i] = arrBits[i + 1];//Chuyển tất cả các bit qua trái
	}
	arrBits[127] = temp;//Gán vị trí phải cùng = temp

	checkSoBitCanDung();
}

//Hàm nhân 2 số
QInt QInt::operator*(const QInt& a)
{
	//Biến tạm và kq để lưu và tính toán.
	QInt temp, kq;
	//Số nào có độ dài lớn hơn thì gán n = độ dài số đó.
	int n;
	//Nếu như mà độ dài của this > độ dài của a
	if (soBitCanDung > a.soBitCanDung)
	{
		//thì n sẽ = độ dài của this.
		n = soBitCanDung;

		//Chạy từ bit đầu đến bit cuối của a, chỉ xét trường hợp bit 1, bit 0 thì không cần.
		for (int i = 0; i < a.soBitCanDung; i++)
		{
			//Nếu ngay tại bit đang xét là 1
			if (a.arrBits[i] == 1)
			{
				//Thì lưu giá trị của this vào biến tạm, và sau đó dịch trái biến tạm i lần.
				temp = *this;
				temp  = temp << i;
				//Sau đó cộng temp vào biến kq.
				kq = kq + temp;
			}
		}
	}
	else
	{
		//n = độ dài của a
		n = a.soBitCanDung;

		//Chạy từ bit đầu đến bit cuối của this, chỉ xét trường hợp bit 1, bit 0 thì không cần.
		for (int i = 0; i < this->soBitCanDung; i++)
		{
			//Nếu ngay tại bit đang xét là 1
			if (this->arrBits[i] == 1)
			{
				//Thì lưu giá trị của a vào biến tạm, và sau đó dịch trái biến tạm i lần.
				temp = a;
				temp = temp << i;
				//Sau đó cộng temp vào biến kq.
				kq = kq + temp;
			}
		}
	}
	
	return kq;
}

//Hàm chia 2 số
QInt QInt::operator/(const QInt& m)
{
	//Biến tạm để lưu và tính toán
	QInt A, Q = *this, M = m;
	//Độ dài
	int n = 128;

	//Chuyển hết về số dương rồi tính toán
	//Nếu trong 2 số có 1 số âm thì kết quả là số âm
	bool kqLaSoAm = false;
	if (Q.arrBits[127] == 1 && M.arrBits[127] == 0)
	{
		Q.chuyenThanhBu2();
		kqLaSoAm = true;
	}
	else if (Q.arrBits[127] == 0 && M.arrBits[127] == 1)
	{
		M.chuyenThanhBu2();
		kqLaSoAm = true;
	}
	else if (Q.arrBits[127] == 1 && M.arrBits[127] == 1)
	{
		Q.chuyenThanhBu2();
		M.chuyenThanhBu2();
	}

	//Cho vòng lặp bằng độ dài của số bi chia.
	for (int i = 0; i < n; i++)
	{
		A = A << 1;
		A.arrBits[0] = Q.arrBits[n - 1];
		Q = Q << 1;

		A = A - M;
		//Nếu kết quả phép trừ là số âm.
		if (A.arrBits[127] == 1)
		{
			Q.arrBits[0] = 0;
			A = A + M;
		}
		//Nếu kết quả phép trừ là số dương.
		else if (A.arrBits[127] == 0)
		{
			Q.arrBits[0] = 1;
		}
	}
	//Nếu trong 2 số có 1 số âm thì kết quả là số âm
	if (kqLaSoAm)
		Q.chuyenThanhBu2();

	return Q;
}


