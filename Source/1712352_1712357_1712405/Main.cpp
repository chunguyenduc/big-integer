#include "QInt.h"
#include "NhapXuat.h"

using namespace std;


int main(int argc, char* argv[])
{
	ofstream out(argv[2]);
	ifstream in(argv[1]);

	string str;
	//Chạy vòng lặp đến cuối file
	while (getline(in, str))
	{
		if (demSoChuoi(str) == 4)
		{
			//Cộng trừ nhân chia, dịch trái phải, and or xor
			string base, num1, op, num2;
			istringstream is(str);
			is >> base >> num1 >> op >> num2;

			if (op == "+" || op == "-" || op == "*" || op == "/")
				congTruNhanChia(out, base, num1, op, num2);

			else if (op == ">>" || op == "<<")
			{
				dichTraiPhai(out, base, num1, op, num2);
			}

			else if (op == "&" || op == "|" || op == "^")
			{
				toanTuLogic(out, base, num1, op, num2);
			}
		}
		else
			//chuyển cơ số, not, quay trái phải
		{
			string base1, base2_op, num;
			istringstream is(str);
			is >> base1 >> base2_op >> num;

			//nếu là quay trái phải, not thì base2_op không phải là 10, 2, 16
			if (base2_op != "2" && base2_op != "10" && base2_op != "16")
				not_quayTraiPhai(out, base1, base2_op, num);
			else
				chuyenCoSo(out, base1, base2_op, num);
		}
	}

	out.close();
	in.close();

	system("pause");
	return 0;
}