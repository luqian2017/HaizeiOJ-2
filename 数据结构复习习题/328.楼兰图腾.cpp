#include <iostream>
using namespace std;
//题目中说 y1到yn是1到n的全排列
#define lowbit(x) ((x) & (-x)) //宏定义实现lowbit函数
#define MAX_N 200005

int a[MAX_N], c[MAX_N];

void add(int x, int val, int n) { //给c[i]进行赋值或更新值
    while (x <= n) {
        c[x] += val;
        x += lowbit(x);
    }
    return ;
}

int query(int x) { //求前缀和
    int sum = 0;
    while (x) {
        sum += c[x];
        x -= lowbit(x);
    }
    return sum;
}

int main() {
    int n;
    long long int lnum, ans1 = 0, ans2 = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) {
        lnum = query(a[i]); //c[i]是以a[i]作为数组下标，前面有多少个数比a[i]小
        ans1 += (a[i] - 1 - lnum) * lnum; //每扫描到一个点都有答案所以累加，右边比a[i]小的数的个数*左边比a[i]小的数的个数
        ans2 += (i - 1 - lnum) * (n - a[i] - i + 1 + lnum); //左边比a[i]大的数的个数*右边比a[i]大的个数
        //      起点到当前点的元素个数-左边比自己小的数的个数，得到左边比自己大的数的个数，然后用大于a[i]数的总数（V）-左边大于他的数得到，右边大于a[i]的数的个数
        add(a[i], 1, n);
    }
    cout << ans2 << " " << ans1 << endl;
    return 0;
}
