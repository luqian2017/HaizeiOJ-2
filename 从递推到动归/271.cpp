#include <iostream>
using namespace std;

#define MAX_N 300000
int a[MAX_N + 5];
int q[MAX_N + 5], head = 0, tail = 0; //存的是下标

int main() {
    int n, k;
    cin >> n >> k;
	/*维护递增的队列*/
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) {
        while (tail - head && a[q[tail - 1]] >= a[i]) tail--; //淘汰掉队列中不符合性质的数据
        q[tail++] = i; //先入队再去检测更新
        if (q[head] <= i - k) head++;
        if (i < k) continue;
        i == k || cout << " "; //控制空格输出
        cout << a[q[head]];
    }
    cout << endl;
    head = tail = 0; //相当于重置队列
	/*维护递减队列*/
    for (int i = 1; i <= n; i++) {
        while (tail - head && a[q[tail - 1]] <= a[i]) tail--;
        q[tail++] = i;
        if (q[head] <= i - k) head++;
        if (i < k) continue;
        i == k || cout << " ";
        cout << a[q[head]];
    }
    cout << endl;
    return 0;
}
