#include <iostream>
using namespace std;

#define MAX_N 32767
int f[MAX_N + 5];

int main() {
    int n;
    cin >> n;
    f[1] = 1; //f[n]表示n个人玩游戏最后剩下的人是谁
    for (int i = 2; i <= n; i++) {
        //第推公式：f[n] = (f[n - 1] + k) % n，用个坐标映射
        f[i] = (f[i - 1] + 2 - 1) % i + 1; //取模前-1,然后又+1是为了把边界改为1-n闭区间
    }
    int x = n;
    while (f[x] - x) x = f[x]; //剩下的人数不再变化
    cout << n + x << endl;// + x是因为剩下的人要多获得1元
    return 0;
}
