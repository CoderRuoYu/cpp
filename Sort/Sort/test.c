#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
void ShellSort(int* a, int n)
{
	int gap = 3;
	for (int cn = 0; cn < gap; cn++)
	{
		for (int i = cn; i < n; i += gap)
		{

			int end;
			int tmp = a[end + gap];
			while (end >= 0)
			{
				if (a[end] > tmp)
				{
					a[end + gap] = a[end];
					end -= gap;
				}
				else
				{
					break;
				}
			}
			a[end + gap] = tmp;
		}
	}
	
	
}

int main()
{

	return 0;
}