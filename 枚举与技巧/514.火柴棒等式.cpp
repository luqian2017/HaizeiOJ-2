#include <iostream>
using namespace std;

int n, ans;
int num[15] = {
   6
   ,2
   ,5
   ,5
   ,4
   ,5
   ,6
   ,3
   ,7
   ,6
};

int func(int x) {
    if (x == 0) return num[0]; //相当于特判，因为 x = 0时，不会进入while循环
    int sum = 0;
    while (x) { //遍历每一位，求得需要火柴的总数
        sum += num[x % 10];
        x /= 10;
    }
    return sum;
}

int main() {
    cin >> n;
    for (int i = 0; i < 1111; i++) { //首先估算枚举上限，枚举a
        for (int j = 0; j < 1111; j++) { //枚举b
            if (func(i) + func(j) + func(i + j) + 4 == n) {
                ans++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}

