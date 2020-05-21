#include <iostream>
using namespace std;
//方法1，遍历L-R区间内的所有数，然后判断他们是否为优雅数
//方法2，枚举优雅数，然后判断优雅数是否在L-R区间内， 1、枚举一堆数0-9，2、枚举一个数0 - 9，且一堆 != 一个 3、数多长 4、一个数的位置

long long a, b, ans;

int main() {
    cin >> a >> b;
    for (int i = 0; i <= 9; i++) { //枚举一堆数
        for (int j = 0;j  <= 9; j++) { //枚举一个数
            if (i == j) continue; //一堆数与一个数相等
            for (int k = 3; k <= 17; k++) {
                for (int l = 1; l <= k; l++) { //一个数的位置
                    if (j == 0 && l == 1) continue; //前置0
                    if (i == 0 && l != 1) break; //一堆0，并且一个数不在第一个，不符合，如000001
                    long long t = 0;
                    for (int m = 1; m <= k; m++) {
                        if (m != l) {
                            t = t * 10 + i;
                        } else {
                            t = t * 10 + j;
                        }
                    }
                    if (t >= a && t <= b) ans++;
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}

