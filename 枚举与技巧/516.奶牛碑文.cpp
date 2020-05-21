#include <iostream>
#include <string>
//方法1，三层循环，一层枚举c，一层枚举o,一层枚举w
//方法2，转化为cow的个数等于 ‘'o'前面的‘'c'的个数 * o后面'w'的个数，所以我们需要一个类似前缀和的数组，从前向后遍历，记录到当前位置前面c的个数
//同理，从后往前遍历记录，到当前位置，后面出现的w的个数
using namespace std;
string str;
long long n, ans, numc[100005], numw[100005], nc, nw;

int main() {
    cin >> n >> str;
    for (int i = 0; i < n; i++) {
        if (str[i] == 'C') nc++;
        numc[i] = nc;
    }
    for (int i = n - 1; i >= 0; i--) {
        if (str[i] == 'W') nw++;
        numw[i] = nw;
    }
    for (int i = 0; i < n; i++) {
        if (str[i] == 'O') {
            ans += numc[i] * numw[i];
        }
    }
    cout << ans << endl;
    return 0;
}

