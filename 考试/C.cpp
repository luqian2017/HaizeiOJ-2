#include <iostream>
using namespace std;
#define MAX_N 300000
long long arr[MAX_N + 5];
long long q[MAX_N + 5], head = 0, tail = 0;
long long n, k;

int main() {
    cin >> n >> k;
    for (long long i = 1; i <= n; i++) cin >> arr[i];
    head = 0, tail = 0;
    for (long long i = 1; i <= n; i++) {
        while (tail - head && arr[q[tail - 1]] >= arr[i]) tail--;
        q[tail++] = i;
        if (q[head] <= i - k) head++;
        if (i < k) continue;
        i == k || cout << " ";
        cout << arr[q[head]];
    }
    cout << endl;
    head = 0, tail = 0;
    for (long long i = 1; i <= n; i++) {
        while (tail - head && arr[q[tail - 1]] <= arr[i]) tail--;
        q[tail++] = i;
        if (q[head] <= i - k) head++;
        if (i < k) continue;
        i == k || cout << " ";
        cout << arr[q[head]];
    }
    cout << endl;
    return 0;
}
