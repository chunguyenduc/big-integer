#pragma once
#include "QInt.h"

//input có thể có 4 chuỗi hoặc 3 chuỗi, hàm này dùng để tính số chuỗi
int demSoChuoi(string str);

//operator+, operator-, operator*, operator/
void congTruNhanChia(ofstream&, string base, string num1, string op, string num2);

//operator>>, operator<<
void dichTraiPhai(ofstream&, string base, string num, string op, string n);

//AND, OR, XOR
void toanTuLogic(ofstream&, string base, string num1, string op, string num2);

//Chuyển các hệ cơ số
void chuyenCoSo(ofstream&, string base1, string base2, string num);

//ror, rol, NOT
void not_quayTraiPhai(ofstream&, string base, string op, string num);
