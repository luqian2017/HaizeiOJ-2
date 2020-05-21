#include <iostream>
using namespace std;

int n, ans;

int main() {
    cin >> n;
    for (int i = 1; i <= n / 3; i++) { //最短边的最长长度为 n / 3 ，等边三角形
        for (int j = i; j <= (n - i) / 2; j++) { //此短边从i 开始枚举，不能从i + 1 开始枚举，因为可能为等腰三角形, 注意上限为 （n - i）/ 2
            int y = n - i - j; //最后一条边的长度
            if (i + j > y) {
                ans++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
