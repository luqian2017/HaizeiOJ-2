#include <iostream>
#include <cstdio>
using namespace std;

int n, k;
double num[10005], mmax;

double func() {
    double l = 0, r = mmax;
    while (r - l > 0.00001) {
        double (r - l)
    }
}

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> num[i];
        mmax = max(mmax, num[i]);
    }
    double ans = func();
    return 0;
}
