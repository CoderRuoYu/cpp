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
//hore�汾
void QuickSort1(int* arr, int left, int right)
{
	if (left >= right)return;
	int flagi = left;
	int begin = left;
	int end = right;
	while (left < right)
	{
		while (left < right && arr[right] >= arr[flagi])right--;
		while (left < right && arr[left] <= arr[flagi])left++;
		swap(arr[right], arr[left]);
	}
	swap(arr[left], arr[flagi]);
	flagi = left;
	QuickSort1(arr, begin, flagi - 1);
	QuickSort1(arr, flagi + 1, end);
}
//�Ż��������򡪡�����ȡ��
int GetMidNum(int* arr, int left, int right)
{
	int mid = (left + right) / 2;
	if (arr[left] < arr[mid])
	{
		if (arr[mid] < arr[right])
		{
			return mid;
		}
		else if (arr[left] > arr[right])
		{
			return left;
		}
		else
		{
			return right;
		}
	}
	else
	{
		if (arr[mid] > arr[right])
		{
			return mid;
		}
		else if (arr[right] > arr[left])
		{
			return left;
		}
		else
		{
			return right;
		}
	}
}
//�ڿӷ�
void QuickSort2(int* arr, int left, int right)
{
	if (left >= right)return;
	int begin = left;
	int end = right;
	int midi = GetMidNum(arr, left, right);
	swap(arr[midi], arr[left]);
	int key = arr[left];
	int hole = left;
	while (left < right)
	{
		while (left < right && arr[right] >= key)right--;
		arr[hole] = arr[right];
		hole = right;
		while (left < right && arr[left] <= key)left++;
		arr[hole] = arr[left];
		hole = left;
	}
	arr[hole] = key;
	QuickSort2(arr, begin, hole - 1);
	QuickSort2(arr, hole + 1, end);
}
//˫ָ�뷨
void QuickSort3(int* arr, int left, int right)
{
	if (left >= right)return;
	int midi = GetMidNum(arr, left, right);
	swap(arr[midi], arr[left]);
	int prev = left;
	int cur = left + 1;
	while (cur <= right)
	{
		if (arr[cur] < arr[left] && ++prev != cur)
		{
			swap(arr[cur], arr[prev]);
		}
		cur++;
	}
	swap(arr[left], arr[prev]);
	QuickSort3(arr, left, prev - 1);
	QuickSort3(arr, prev + 1, right);
}
int PartSort(int* arr, int left, int right)
{
	int mid = (left + right) / 2;

}
////�ǵݹ�
//void QuickSort(int* arr, int left, int right)
//{
//
//}
void _MergeSort(int* arr, int left, int right, int* tmp)
{
	if (left >= right)return;
	int mid = (left + right) / 2;
	_MergeSort(arr, left, mid, tmp);
	_MergeSort(arr, mid + 1, right, tmp);
	int begin1 = left;
	int begin2 = mid + 1;
	int cur = left;
	while (begin1 <= mid && begin2 <= right)
	{
		if (arr[begin1] < arr[begin2])
		{
			tmp[cur++] = arr[begin1++];
		}
		else
		{
			tmp[cur++] = arr[begin2++];
		}
	}
	while (begin1 <= mid)
	{
		tmp[cur++] = arr[begin1++];
	}
	while (begin2 <= right)
	{
		tmp[cur++] = arr[begin2++];
	}
	memcpy(arr + left, tmp + left, (right - left + 1) * sizeof(int));
}
void MergeSort1(int* arr, int n)
{
	int* tmp = new int[n];
	if (tmp == nullptr)
	{
		perror("new fail");
		return;
	}
	_MergeSort(arr, 0, n - 1, tmp);
	delete[] tmp;
}
void MergeSort2(int* arr, int n)
{

}
int main()
{
	int arr[] = { 6,2, 9,8,7,6,5 ,11,-1,-8,-9,1000,-111 };
	/*PrintArray(arr, sizeof(arr) / sizeof(arr[0]));
	InsertSort(arr, sizeof(arr) / sizeof(arr[0]));
	PrintArray(arr, sizeof(arr) / sizeof(arr[0]));*/
	PrintArray(arr, sizeof(arr) / sizeof(arr[0]));
	MergeSort1(arr, sizeof(arr) / sizeof(arr[0]) );
	PrintArray(arr, sizeof(arr) / sizeof(arr[0]));
	return 0;
}