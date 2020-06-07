#include <iostream>
#include <cmath>
//求区间和的时候想到用前缀和，用前缀和时，必须把第1位空出来，并赋值为0
using namespace std;

#define MAX_N 300000
int s[MAX_N + 5];
int q[MAX_N + 5], head, tail;

int main() {
    int n, m, ans;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> s[i], s[i] += s[i - 1];
    head = tail = 0; //不能省略
    q[tail++] = 0; //将前缀和的0号元素压进去
    ans = s[1];
    for (int i = 1; i <=n; i++) {
        //if (i - q[head] > m) head++;
        //ans = max(ans, s[i] - s[q[head]]);
        while (tail - head && s[q[tail - 1]] >= s[i]) tail--;
        q[tail++] = i;
        if (i - q[head] > m) head++;
        ans = max(ans, s[i] - s[q[head]]);
    }
    cout << ans << endl;
    return 0;
}
