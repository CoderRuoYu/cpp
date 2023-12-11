#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#include <cstdlib>
using namespace std;
const int N = 1000010;
int a[N];
struct prev
{
    prev()
    {
        flag = 0;
        pos = 0;
        val = 0;
    }
    int val;
    int pos;
    int flag;
};
int main() {
    int n;
    scanf("%d", &n);
    vector<pair<int, int>> res;
    for (int i = 0; i < n; i++)
    {
        int x;
        scanf("%d", &x);
        res.push_back(pair<int, int>(x, i));
    }
    sort(res.begin(), res.end());
    int tag = 1;
    struct prev temp;
    for (int i = 0; i < n; i++)
    {
        if (temp.flag == 0)
        {
            a[res[i].second] = tag;
            temp.flag = 1;
        }
        else
        {
            if (abs(res[i].second - temp.pos) == 1)
            {
                if (res[i].first == temp.val)
                {
                    a[res[i].second] = tag;
                }
                else
                {
                    tag++;
                    a[res[i].second] = tag;
                }
            }
            else
            {
                a[res[i].second] = tag;

            }
        }
        temp.pos = res[i].second;
        temp.val = res[i].first;
    }
    for (int i = 0; i < n; i++)cout << a[i] << " ";
    cout << endl;
    return 0;
}
