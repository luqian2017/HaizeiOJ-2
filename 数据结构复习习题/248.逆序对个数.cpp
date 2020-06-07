#include <iostream>
using namespace std;
#define MAX_N 500000

long long arr[MAX_N + 5];
long long temp[MAX_N + 5];

long long merge_sort(long long l, long long r) {
    if (l == r) return 0;
    long long mid = (l + r) >> 1;
    long long ans1 = merge_sort(l, mid);
    long long ans2 = merge_sort(mid + 1, r);
    /*计算数组1和数组2中的你逆序对数*/
    long long ans3 = 0;
    long long p1 = l, p2 = mid + 1, p3 = 0; //p1指向数组1的起点，p2指向数组2的起点，p3指向temp,从0开始，方便后面把temp拷贝回arr
    while (p1 <= mid || p2 <= r) {
        if (p2 > r || p1 <= mid && arr[p1] <= arr[p2]) { // arr[p1] <= arr[p2] 中的=不能省
            temp[p3++] = arr[p1++]; //p1++
        } else {
            ans3 += (mid - p1 + 1); //把数组2中的一个元素放在了数组1的前面，所以累加，数组1中剩余的元素
            temp[p3++] = arr[p2++];//p2++
        }
    }
    //把数组拷贝回去
    for (long long i = l ; i <= r; i++) arr[i] = temp[i - l]; 
    return ans1 + ans2 + ans3;
}

long long solve() {
    long long n;
    cin >> n;
    if (n == 0) return 0;
    for (long long i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    cout << merge_sort(1, n) << endl;
    return 1;
}

int main() {
    while (solve());
    return 0;
}
