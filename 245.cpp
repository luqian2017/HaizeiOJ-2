#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    int pos = a[n / 2];
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += abs(a[i] - pos);
    }
    cout << sum << endl;
    return 0;
}

