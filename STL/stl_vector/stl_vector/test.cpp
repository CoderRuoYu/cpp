#define _CRT_SECURE_NO_WARNINGS 1
#include "vector.h"
void test01()
{
	/*gao::vector<int> temp(1,2);

	for (auto e:temp)
	{
		std::cout << e << " ";
	}
	cout << endl;
	gao::vector<int> s(temp);
	for (auto e : s)
	{
		std::cout << e << " ";
	}
	cout << endl;*/
	gao::vector<vector<int>> test(20,vector<int>(20));
	test[19].push_back(1);
	cout << test[1].back() << endl;
}
int main()
{
	test01();
	return 0;
}