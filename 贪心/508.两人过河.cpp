#include <iostream>
#include <algorithm>
using namespace std;

int n, num[1005], ans;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> num[i];
    }
    sort(num, num + n);
    for (int i = n - 1; i >= 0; i -= 2) {
        if (i == 0) { //一个人过桥所消耗时间
            ans += num[0];
            break;
        }
        if (i == 1) { //两个过桥所消耗时间
            ans += num[1];
            break;
        }
        if (i == 2) { //三个人过桥所消耗时间
            ans += num[0] + num[1] + num[2];
            break;
        }
        /*四个人过河时，从两种方案中选择用时少的那种*/
        ans += min(num[1] + num[0] + num[i] + num[1], num[i] + num[0] + num[i - 1] + num[0]);//方案1，《过河快》最快+次快|最快回|最慢+次慢|次快回 方案2，《送手电筒块》最慢+最快|最快回|次慢+最快|最快回(主要折腾最快的)
    }
    cout << ans << endl;
    return 0;
}
