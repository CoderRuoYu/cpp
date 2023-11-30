#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
int idx;
const int N = 100010;
int a[N], ne[N];
int hh;
void init()
{
    hh = -1;
    idx = 0;
}
void insert_head(int x)
{
    a[idx] = x;
    ne[idx] = hh;
    hh = idx;
    idx++;
}
void erasek(int k)
{
    ne[k - 1] = ne[ne[k - 1]];
}
void insertk(int k, int x)
{
    a[idx] = x;
    ne[idx] = ne[k - 1];
    ne[k - 1] = idx;
    idx++;
}
int main()
{
    int m;
    scanf("%d", &m);
    init();
    for (int i = 0; i < m; i++)
    {
        char ch;
        int k, x;
        scanf("%c", &ch);
        if (ch == 'H')
        {
            
            scanf("%d", &x);
            insert_head(x);
        }
        else if (ch == 'D')
        {
            scanf("%d", &k);
            erasek(k);
        }
        else
        {
            scanf("%d%d", &k, &x);
            insertk(k, x);
        }
    }
    for (int i = hh; i != -1; i = ne[i])
    {
        cout << a[i] << ' ';
    }
    return 0;
}