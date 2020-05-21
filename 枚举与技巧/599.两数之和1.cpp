#include <iostream>
using namespace std;
//头尾两个指针，如果两数之和大于sum r--，如果两数之和小于sum, l++
int n, num[10000005], target;

int main() {
    cin >> n >> target;
    for (int i = 0; i < n; i++) {
        cin >> num[i];
    }
    int l = 0, r = n - 1;
    while (l  < r) { //不能取等号
        int sum = num[l] + num[r];
        if (sum == target) {
            cout << l << " " << r << endl;
            return 0;
        }
        if (sum < target) {
            l++;
        } else {
            r--;
        }
    }
    return 0;
}

