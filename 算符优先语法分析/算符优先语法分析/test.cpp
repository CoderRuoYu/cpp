#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
#define MAXWORDS 100
//优先关系矩阵
map<char, map<char, char>> priorityMatrix = {
	{'+',{{'+','>'},{'-','>'},{'*','<'},{'/','<'},{'(','<'},{')','>'},{'i','<'},{'#', '>'}}},
	{'-',{{'+','>'},{'-','>'},{'*','<'},{'/','<'},{'(','<'},{')','>'},{'i','<'},{'#', '>'}}},
	{'*',{{'+','>'},{'-','>'},{'*','>'},{'/','>'},{'(','<'},{')','>'},{'i','<'},{'#', '>'}}},
	{'/',{{'+','>'},{'-','>'},{'*','>'},{'/','>'},{'(','<'},{')','>'},{'i','<'},{'#', '>'}}},
	{'(',{{'+','<'},{'-','<'},{'*','<'},{'/','<'},{'(','<'},{')','='},{'i','<'}}},
	{')',{{'+','>'},{'-','>'},{'*','>'},{'/','>'},{')','>'},{'#', '>'}}},
	{'i',{{'+','>'},{'-','>'},{'*','>'},{'/','>'},{'(','<'},{')','>'},{'#', '>'}}},
	{'#',{{'+','<'},{'-','<'},{'*','<'},{'/','<'},{'(','<'},{'i','<'},{'#', '='}}}
};
//存放文法
map<string, char> grammer = { {"#E#",'S'},{"E+T",'E'},{"E-T",'E'},{"T",'E'},{"T*F",'T'},{"T/F",'T'},{"F",'T'},{"(E)",'F'},{"i",'F'} };

// 终结符号
vector<char> Vt = { '+','-','*','/','(',')','i','#' };
// 非终结符号
vector<char> Vn = { 'S','E','T','F' };
//读取词法分析程序的输出结果，获得要进行语法分析的输入串
string readFile();
//判断是否是终结符号
bool isVt(char& ch);

//判断是否是非终结符号
bool isVn(char& ch);

//算符优先文法分析
bool OperatorPrecedenceAnalysis(string& str);

int main()
{
	string ch_code(readFile());
	bool res = OperatorPrecedenceAnalysis(ch_code);
	if (res == true)
	{
		cout << "语法分析正确" << endl;
	}
	else
	{
		cout<<"语法分析错误"<<endl;
	}
	return 0;
}
bool OperatorPrecedenceAnalysis(string& str)
{
	//分析栈
	vector<char> s;//使用vector容器模拟分析栈
	s.push_back('#');
	int i = 0;//指向栈顶元素
	int k = 0;//指向当前的输入字符
	char r;//存放分析串中的一个符号
	char q;//存放# ， Vt， Vn
	int j;
	while (true)
	{
		r = str[k++];

		if (isVt(s[i]))
		{
			j = i;
			
		}
		else
		{
			j = i - 1;
		}
		//当前算符的优先级大于分析串输入元素
		if (priorityMatrix[s[j]][r] == '>')
		{
			int flag = 1;
			string temp;
			while (flag)
			{
				q = s[j];
				//temp += q;
				j = j - 1;
				if (!isVt(s[j]))j = j - 1;
				if (priorityMatrix[s[j]][q] == '<')
				{
					
					//进行规约
					//reverse(temp.begin(), temp.end());
					for (int pos = j + 1; pos <= i; pos++)temp += s[pos];
					for (int cn = 0; cn < temp.size(); cn++)
					{
						s.pop_back();
					}
					auto ptr = grammer.find(temp);
					if (ptr == grammer.end())
					{
						cout << "没有找到规约的对应文法" << endl;
						return false;
					}
					else
					{
						i = j + 1;
						s.push_back(ptr->second);
					}
					flag = 0;
					break;
				}
			}
			
		}
		//当前栈顶元素的优先级小于等于分析串当前指向元素，所以向分析栈中放入元素
		else
		{
			i = i + 1;
			s.push_back(r);
			continue;
		}
		if (i == 1 && r == '#')
		{
			return true;
		}
		else
		{
			k--;
		}
	}
	
	
}

bool isVt(char& ch)
{
	if (find(Vt.begin(), Vt.end(), ch) != Vt.end())
	{
		return true;
	}
	return false;
}
bool isVn(char& ch)
{
	if (find(Vn.begin(), Vn.end(), ch) != Vn.end())
	{
		return true;
	}
	return false;
}

string readFile()
{
	string code, ch_code;
	int i = 0;
	char buff[MAXWORDS];
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
	return ch_code;
}