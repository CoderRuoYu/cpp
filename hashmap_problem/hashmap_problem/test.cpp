#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <vector>
using namespace std;
const int N = 60011;
class Solution {
public:

    
    #define null 0x3f3f3f3f3f3f3f3f
    long long h[N];
    int cn[N];
    int find(long long x)
    {
        int locate = (x % N + N) % N;
        while (h[locate] != null && h[locate] != x)
        {
            locate++;
            if (locate == N)locate = 0;
        }
        return locate;
    }
    int singleNumber(vector<int>& nums) {
        memset(cn, 0, sizeof(cn));
        memset(h, 0x3f, sizeof(h));
        for (int i = 0; i < nums.size(); i++)
        {
            int locate = find(nums[i]);
            if (h[locate] != null)
            {
                cn[locate]++;
            }
            else
            {
                h[locate] = nums[i];
                cn[locate]++;
            }
        }
        int i = 0;
        for (i = 0; i < N; i++)
        {
            if (cn[i] == 1)
            {
                break;
            }
        }
        return h[i];
    }
};
int main()
{
    Solution temp;
    vector<int> s = { 2,2,3,2 };
    temp.singleNumber(s);
    return 0;
}