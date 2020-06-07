#include <iostream>
using namespace std;

long long a, num[20000005]; //不知道数组开多大的时候，尽量把数组开到边界

int main() {
    cin >> a;
    for (int i = 1; i <= 20000000; i++) {
        num[i] = num[i - 1] + i;
    }
    for (int i = a; 1; i++) {
        int l = i + 1, r = 20000000;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (num[mid] - num[i] == num[i - 1]) {
                cout << i << " " << mid << endl;
                return 0;
            }
            if (num[mid] - num[i] > num[i  - 1]) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
    }
    return 0;
}
