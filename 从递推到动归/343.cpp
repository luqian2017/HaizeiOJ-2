#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <queue>
#include <stack>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <vector>
using namespace std;
#define MAX_N 1000
int dp[MAX_N + 5][MAX_N + 5]; //截取dp[i][j]序列长度为i和序列长度为j时的最大公共子序列长度
string s1, s2;

int main() {
    cin >> s1 >> s2;
    for (int i = 1; i <= s1.size(); i++) {
        for (int j = 1; j <= s2.size(); j++) {
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]); //状态转移时，分情况进行讨论，情况1，s[i] != s[j],因为要求最长公共子序列，所以相当于子序列i少了一个元素，或者子序列j少了一个元素
            if (s1[i - 1] - s2[j - 1]) continue;
            dp[i][j] = dp[i - 1][j - 1] + 1; //情况2，s[i]=s[j],此时i，j序列同时少了一个元素，最后再加上1个长度即可
        }
    }
    cout << dp[s1.size()][s2.size()] << endl;
    return 0;
}
