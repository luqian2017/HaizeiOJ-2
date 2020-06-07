#include <iostream>
using namespace std;

int f[32800];

int main() {
    int n;
    cin >> n;
    f[1] = 1;//f[i]i个人游戏，下一轮被淘汰人的位置
    for (int i = 2; i <= n; i++) {
        f[i] = (f[i - 1] + 2 - 1) % i + 1;
    }
    int x = n; //第一轮游戏总人数
    while (x != f[x]) x = f[x]; //如果还有人在被淘汰，可以用过数组f[x]知道，下一次起点在那儿
    cout << n + x << endl;
    return 0;
}

