#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
void PrintArray(int* arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << ' ';
	}
	cout << endl;
}
void InsertSort(int* arr, int n)
{
	for (int i = 1; i < n; i++)
	{
		int end = i - 1;
		int tmp = arr[i];
		while (end >= 0)
		{
			if (arr[end] > tmp)
			{
				arr[end + 1] = arr[end];
				end--;
			}
			else
			{
				break;
			}
		}
		arr[end + 1] = tmp;
	}
}
void ShellSort(int* arr, int n)
{
	int gap = n;
	while (gap > 0)
	{
		gap = gap / 2;
		for (int i = 0; i < n - gap; i++)
		{
			int end = i;
			int tmp = arr[end + gap];
			while (end >= 0)
			{
				if (arr[end] > tmp)
				{
					arr[end + gap] = arr[end];
					end -= gap;
				}
				else
				{
					break;
				}
			}
			arr[end + gap] = tmp;
		}
	}
}
void SelectSort(int* arr, int n)
{
	int left = 0;
	int right = n - 1;
	while (left < right)
	{
		int maxi = left;
		int mini = left;
		for (int i = left + 1; i <= right; i++)
		{
			if (arr[i] > arr[maxi])
			{
				maxi = i;
			}
			if (arr[i] < arr[mini])
			{
				mini = i;
			}
		}
		swap(arr[mini], arr[left]);
		if (left == maxi)
		{
			maxi = mini;
		}
		swap(arr[maxi], arr[right]);
		left++;
		right--;
	}
	
}
void BubbleSort(int* arr, int n)
{
	for (int j = 0; j < n - 1; j++)
	{
		for (int i = 1; i < n - j; i++)
		{
			if (arr[i - 1] > arr[i])
			{
				swap(arr[i - 1], arr[i]);
			}
		}
	}
}
void QuickSort(int* arr, int left, int right)
{
	if (left >= right)return;
	int flagi = left;
	int righti = right;
	while (left < right)
	{
		while (left < right && arr[right] >= arr[flagi])right--;
		while (left < right && arr[left] <= arr[flagi])left++;
		swap(arr[right], arr[left]);
	}
	swap(arr[left], arr[flagi]);
	flagi = left;
	QuickSort(arr, 0, flagi - 1);
	QuickSort(arr, flagi + 1, righti);

}
int main()
{
	int arr[] = { 9,8,7,6,5,4,3,3,3,2,1,0 };
	/*PrintArray(arr, sizeof(arr) / sizeof(arr[0]));
	InsertSort(arr, sizeof(arr) / sizeof(arr[0]));
	PrintArray(arr, sizeof(arr) / sizeof(arr[0]));*/
	PrintArray(arr, sizeof(arr) / sizeof(arr[0]));
	QuickSort(arr, 0, sizeof(arr) / sizeof(arr[0]) - 1);
	PrintArray(arr, sizeof(arr) / sizeof(arr[0]));
	return 0;
}