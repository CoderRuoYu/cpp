#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string>
using namespace std;
#define MAXWORDS 100
string code, ch_code;
int i, SIGN;
const char* s;
char buff[MAXWORDS];
void S();
void E();
void E_();
void T();
void T_();
void F();
void A();
void M();
void V();


int main()
{
	FILE* fp = fopen("test.txt", "r");
	if (fp == nullptr)
	{
		perror("fopen(test.txt):");
	}
	while (fgets(buff, MAXWORDS - 1, fp) != nullptr)
	{
		int len = strlen(buff);
		buff[len - 1] = '\0';
		len = strlen(buff);
		for (int j = 0; j < len; j++)
		{
			if (buff[i] == '<')
			{
				j++;
				string temp;
				while (j < len && buff[j] != ',')
				{
					temp += buff[j];
					j++;
				}
				j++;
				if (temp != "1")
				{
					while (j < len && buff[j] != '>')
					{
						code += buff[j];
						ch_code += buff[j];
						j++;
					}
				}
				else
				{
					ch_code += 'i';
					while (j < len && buff[j] != '>')
					{
						code += buff[j];
						j++;
					}
				}
			}
		}
	}
	code += '#';
	ch_code += '#';
	cout << "要计算的表达式是:" << code << endl;
	cout << "变量和常数替换为i的表达式是:" << ch_code << endl;
	fclose(fp);
	if (ch_code[0] == '#')
	{
		cout << "无表达式可以分析" << endl;
	}
	s = ch_code.c_str();
	S();
	if (!SIGN && s[i] == '#')
	{
		cout << "语句合法" << endl;
	}
	else
	{
		cout << "语句不合法" << endl;
	}
	return 0;
}
void S()
{
	if (SIGN == 0)
	{
		printf("S检查  ");
		// 当输入的字符串中首字母为a时
		if (s[i] == 'i') {
			V();
			if (SIGN == 0 && s[i] == '=') {
				//				printf("(%c)  ",s[i]);
				i++;
				E();
			}
			else {
				SIGN = 1;
				cout << "S处出现错误" << endl;
			}
		}
		else {
			SIGN = 1;
			cout << "S处出现错误" << endl;
		}
	}
}

void E()
{
	if (SIGN == 0) {
		printf("E   ");
		if (s[i] == '(' || s[i] == 'i') {
			T();
			if (SIGN == 0) {
				if (s[i] == '+' || s[i] == '-') {
					E_();
				}
				else if (s[i] == ')' || s[i] == '#') {
					return;
				}
				else {
					SIGN = 1;
					cout << "E处出现错误" << endl;
				}
			}
		}
		else {
			SIGN = 1;
			cout << "E处出现错误" << endl;
		}
	}
}

void E_()
{
	if (SIGN == 0) {
		printf("E'   ");
		if (s[i] == '+' || s[i] == '-') {
			A();
			if (SIGN == 0) {
				if (s[i] == '(' || s[i] == 'i') {
					T();
					if (SIGN == 0) {
						if (s[i] == '+' || s[i] == '-') {
							E_();
						}
						else if (s[i] == ')' || s[i] == '#') {
							return;
						}
						else {
							SIGN = 1;
							cout << "E'处出现错误" << endl;
						}
					}
				}
				else {
					SIGN = 1;
					cout << "E'处出现错误" << endl;
				}
			}
		}
		else if (s[i] == ')' || s[i] == '#') {
			return;
		}
		else {
			SIGN = 1;
			cout << "E'处出现错误" << endl;
		}
	}
}

void T()
{
	if (SIGN == 0) {
		printf("T   ");
		if (s[i] == '(' || s[i] == 'i') {
			F();
			if (SIGN == 0) {
				if (s[i] == '*' || s[i] == '/') {
					T_();
				}
				else if (s[i] == '+' || s[i] == '-' || s[i] == ')' || s[i] == '#') {
					return;
				}
				else {
					SIGN = 1;
					cout << "T处出现错误" << endl;
				}
			}
		}
		else {
			SIGN = 1;
			cout << "T处出现错误" << endl;
		}
	}
}

void T_()
{
	if (SIGN == 0) {
		printf("T'   ");
		if (s[i] == '*' || s[i] == '/') {
			M();
			if (SIGN == 0) {
				F();
				if (SIGN == 0) {
					T_();
				}
			}
		}
		else if (s[i] == '+' || s[i] == '-' || s[i] == ')' || s[i] == '#') {
			return;
		}
		else {
			SIGN = 1;
			cout << "T'处出现错误" << endl;
		}
	}
}

void F()
{
	if (SIGN == 0) {
		printf("F   ");
		if (s[i] == '(') {
			//			printf("(%c)  ",s[i]);
			i++;
			if (s[i] == '(' || s[i] == 'i') {
				E();
				if (SIGN == 0) {
					if (s[i] == ')') {
						//						printf("(%c)  ",s[i]);
						i++;
					}
					else {
						SIGN = 1;
						cout << "F处出现错误" << endl;
					}
				}
			}
			else {
				SIGN = 1;
				cout << "F处出现错误" << endl;
			}
		}
		else if (s[i] == 'i') {
			//			printf("(%c)  ",s[i]);
			i++;
		}
		else {
			SIGN = 1;
			cout << "F处出现错误" << endl;
		}
	}
}

void A()
{
	if (SIGN == 0) {
		printf("A   ");
		if (s[i] == '+' || s[i] == '-') {
			//			printf("(%c)  ",s[i]);
			i++;
		}
		else {
			SIGN = 1;
			cout << "A处出现错误" << endl;
		}
	}
}

void M()
{
	if (SIGN == 0) {
		printf("M   ");
		if (s[i] == '*' || s[i] == '/') {
			//			printf("(%c)  ",s[i]);
			i++;
		}
		else {
			SIGN = 1;
			cout << "M处出现错误" << endl;
		}
	}
}

void V()
{
	if (SIGN == 0) {
		printf("V   ");
		if (s[i] == 'i') {
			//			printf("(%c)  ",s[i]);
			i++;
		}
		else {
			SIGN = 1;
			cout << "V处出现错误" << endl;
		}
	}
}
