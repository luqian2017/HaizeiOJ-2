#include <iostream>
using namespace std;
/* 1、把64进制数转化为2进制数，记录其中0的个数
 * 2、AND一个0有三种可能，假如有x个0 (x,y)对数应该为3^x
 * */
char str[100005];
long long num[64], num2[10] = {1, 2, 4, 8, 16, 32}; //num[]记录转化为二进制数后树中包含1的个数，num2[]用来判断2进制数该位是否为1
long long ans = 1;//累乘，所以初始值为1

int main() {
    cin >> str;
    for (int i = 0; i <= 63; i++) {
        int t = i;
        for (int j = 5; j >= 0; j--) {
            if (t >= num2[j]) {
                num[i]++;
                t -= num2[j];
            }
        }
    }
    for (int i = 0; str[i]; i++) {//变成10进制数
        int t;
        if (str[i] >= '0' && str[i] <= '9') {
            t = str[i] - '0';
        } else if (str[i] >= 'A' && str[i] <= 'Z') {
            t = str[i] - 'A' + 10;
        } else if (str[i] >= 'a' && str[i] <= 'z') {
            t = str[i] - 'a' + 36;
        } else if (str[i] == '-') {
            t = 62;
        } else {
            t = 63;
        }

        t = 6 - num[t];
        for (int i = 0; i < t; i++) {
            ans = ans * 3 % 1000000007;
        }
    }
    cout << ans << endl;
    return 0;
}

