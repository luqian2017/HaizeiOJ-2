#include <iostream>
using namespace std;
//优化：
//用一个数组去记录长度位i的队列，的末尾最小元素，且这数组一定是递增的
#define MAX_N 1000000
int a[MAX_N + 5];
int len[MAX_N + 5], ans = 0; //ans 记录len数组的长度
int dp[MAX_N + 5];

int bs(int *arr, int l, int r, int x) {
    if (l == r) return l;
    int mid = (l + r) >> 1;
    if (arr[mid] < x) return bs(arr, mid + 1, r, x);
    return bs(arr, l, mid, x);
}

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        dp[i] = 1; //自身的长度
        len[i] = n + 1; //赋值为极大值
    }
    len[++ans] = a[1]; //读入第一个元素，现在序列长度为1，序列尾最小的元素位a[i],且ans至少得为1;
    for (int i = 2; i <= n; i++) {
        dp[i] = bs(len, 1, ans + 1, a[i]);
        len[dp[i]] = a[i]; //更新当前长度序列，末尾最小的元素的值
        ans = max(dp[i], ans); //更新答案
    }
    cout << ans << endl;
    return 0;
}
