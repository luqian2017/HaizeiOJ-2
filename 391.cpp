#include <iostream>
using namespace std;

long long  n, m, num[100005], mmax, x;

/*计算分的段数*/
long long check(long long mid) {
    int now = 0, cnt = 0;
    for (int i = 0; i < n; i++) {
        if (now + num[i] == mid) {
            cnt++;
            now = 0;
        } else if (now + num[i] > mid) {
            cnt++;
            now = num[i];
        } else {
            now += num[i];
        }
    }
    if (now > 0) cnt++;
    return cnt;
}

/*二分*/
long long func() {
    long long l = x, r = mmax;
    while (l != r) {
        long long mid = (l + r) / 2;
        long long cnt = check(mid);
        if (cnt > m) {
            l = mid + 1;
        } else {
            r = mid;
        }
    }
    return 1;
}

int main() {
    /*输入，确定上下界*/
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> num[i];
        mmax += num[i];
        x = max(x, num[i]);
    }
    cout << func() << endl;
    return 0;
}
 
