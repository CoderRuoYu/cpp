#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
using namespace std;
vector<string> reserve = { "void","int","float","double","if","else","for","do","while" };
const int num_reserve[] = { 2,3,4,5,6,7,8,9,10 };
//判断是否是保留字 如果是的话返回对应的类别编码，否则返回0
int is_reserve(string& temp)
{
	for (int i = 0; i < reserve.size(); i++)
	{
		if (reserve[i] == temp)
		{
			return num_reserve[i];
		}
	}
	return 0;
}
//是字母返回值为1 否则返回值为0
int is_letter(char& ch)
{
	if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
	{
		return 1;
	}
	return 0;
}
//如果是数字返回1 否则返回0
int is_number(char ch)
{
	if (ch >= '0' && ch <= '9')
	{
		return 1;
	}
	return 0;
}
//判断是否是单字符分界符，如果是返回1，否则返回0
int is_single_delimiter(char& ch)
{
	switch (ch)
	{
	case ';':
		return 1;
	case ',':
		return 1;
	case '(':
		return 1;
	case ')':
		return 1;
	case '{':
		return 1;
	case '}':
		return 1;
	case '[':
		return 1;
	case ']':
		return 1;
	default:
		return 0;
	}
}
int main()
{
	char ch;
	FILE* ptr = fopen("input.txt", "r");
	if (!ptr)
	{
		perror("input文件打开失败");
		return -1;
	}
	FILE* fp = fopen("output.txt", "a+");
	if (!fp)
	{
		perror("output文件打开失败");
		return -1;
	}
	ch = fgetc(ptr);
	while (ch != EOF)
	{
		if (ch == ' ' || ch == '\t')
		{
			ch = fgetc(ptr);
			continue;
		}
		else if (ch == '\n')
		{
			fprintf(fp, "%c", ch);
			ch = fgetc(ptr);
			
		}
		else if (is_letter(ch))
		{
			string temp("");
			temp += ch;
			ch = fgetc(ptr);
			while (is_letter(ch) || is_number(ch))
			{
				temp += ch;
				ch = fgetc(ptr);
			}
			//fseek(ptr, -1, SEEK_CUR);
			int id = is_reserve(temp);
			if (id != 0)
			{
				fprintf(fp, "<%d,%s>", id, temp.c_str());
			}
			else
			{
				fprintf(fp, "<%d,%s>", 1, temp.c_str());
			}

		}
		else if (is_number(ch))
		{
			string temp("");
			temp += ch;
			ch = fgetc(ptr);
			while (is_number(ch))
			{
				temp += ch;
				ch = fgetc(ptr);
			}
			fprintf(fp, "<%d,%s>", 11, temp.c_str());
		}
		else if (is_single_delimiter(ch))
		{
			fprintf(fp, "<12,%c>", ch);
			ch = fgetc(ptr);
		}
		else if (ch == '<')
		{
			string temp("");
			temp += ch;
			ch = fgetc(ptr);
			if (ch == '<')
			{
				temp += ch;
				fprintf(fp, "<13,%s>", temp.c_str());
				ch = fgetc(ptr);

			}
			else if (ch == '=')
			{
				temp += ch;
				fprintf(fp, "<13,%s>", temp.c_str());
				ch = fgetc(ptr);
			}
			else
			{
				fprintf(fp, "<13,%s>", temp.c_str());
			}
		}
		else if (ch == '=')
		{
			string temp("");
			temp += ch;
			ch = fgetc(ptr);
			if (ch == '=')
			{
				temp += ch;
				fprintf(fp, "<13,%s>", temp.c_str());
				ch = fgetc(ptr);
			}
			else
			{
				fprintf(fp, "<13,%s>", temp.c_str());
			}
		}
		else if (ch == '>')
		{
			string temp("");
			temp += ch;
			ch = fgetc(ptr);
			if (ch == '>')
			{
				temp += ch;
				fprintf(fp, "<13,%s>", temp.c_str());
				ch = fgetc(ptr);

			}
			else if (ch == '=')
			{
				temp += ch;
				fprintf(fp, "<13,%s>", temp.c_str());
				ch = fgetc(ptr);
			}
			else
			{
				fprintf(fp, "<13,%s>", temp.c_str());
			}
		}
		else if (ch == '/')
		{
			string temp("");
			temp += ch;
			ch = fgetc(ptr);
			if (ch == '*')
			{
				fprintf(fp, "注释处理开始");
				ch = fgetc(ptr);
				while (ch != EOF)
				{
					if (ch == '*')
					{
						ch = fgetc(ptr);
						if (ch == '/')
						{
							break;
						}
						else
						{
							continue;
						}
					}
					ch = fgetc(ptr);
				}
				if (ch == '/')
				{
					fprintf(fp, "注释处理完成");
					ch = fgetc(ptr);
				}
			}
			else if (ch == '=')
			{
				temp += ch;
				fprintf(fp, "<13,%s>", temp.c_str());
				ch = fgetc(ptr);
			}
			else
			{
				fprintf(fp, "<12,%s>", temp.c_str());
			}
		}
		else if (ch == '!')
		{
			string temp("");
			temp += ch;
			ch = fgetc(ptr);
			if (ch == '=')
			{
				temp += ch;
				fprintf(fp, "<13,%s>", temp.c_str());
				ch = fgetc(ptr);
			}
			else
			{
				fprintf(fp, "<12,%s>", temp.c_str());
			}
		}
		else if (ch == '+')
		{
			string temp("");
			temp += ch;
			ch = fgetc(ptr);
			if (ch == '=')
			{
				temp += ch;
				fprintf(fp, "<13,%s>", temp.c_str());
				ch = fgetc(ptr);
			}
			else if (ch == '+')
			{
				temp += ch;
				fprintf(fp, "<13,%s>", temp.c_str());
				ch = fgetc(ptr);
			}
			else
			{
				fprintf(fp, "<12,%s>", temp.c_str());
			}
		}
		else if (ch == '-')
		{
			string temp("");
			temp += ch;
			ch = fgetc(ptr);
			if (ch == '=')
			{
				temp += ch;
				fprintf(fp, "<13,%s>", temp.c_str());
				ch = fgetc(ptr);
			}
			else if (ch == '-')
			{
				temp += ch;
				fprintf(fp, "<13,%s>", temp.c_str());
				ch = fgetc(ptr);
			}
			else
			{
				fprintf(fp, "<12,%s>", temp.c_str());
			}
		}
		else if (ch == '*')
		{
			string temp("");
			temp += ch;
			ch = fgetc(ptr);
			if (ch == '=')
			{
				temp += ch;
				fprintf(fp, "<13,%s>", temp.c_str());
				ch = fgetc(ptr);
			}
			else
			{
				fprintf(fp, "<12,%s>", temp.c_str());
			}
		}
		else if (ch == '&')
		{
			string temp("");
			temp += ch;
			ch = fgetc(ptr);
			if (ch == '&')
			{
				temp += ch;
				fprintf(fp, "<13,%s>", temp.c_str());
				ch = fgetc(ptr);
			}
			else
			{
				fprintf(fp, "<12,%s>", temp.c_str());
			}
		}
		else if (ch == '|')
		{
			string temp("");
			temp += ch;
			ch = fgetc(ptr);
			if (ch == '|')
			{
				temp += ch;
				fprintf(fp, "<13,%s>", temp.c_str());
				ch = fgetc(ptr);
			}
			else
			{
				fprintf(fp, "<12,%s>", temp.c_str());
			}
		}
	}
	fclose(ptr);
	fclose(fp);
	return 0;
}