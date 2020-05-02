#include <iostream>
#include <algorithm>
using namespace std;

#define MAX_N 20000
#define MAX_M 100000

int fa[MAX_N + 5], val[MAX_N + 5];

void init(int n) {
    for (int i = 1; i <= n; i++) {
        fa[i] = i;
        val[i] = 0;
    }
    return ;
}

int get(int x) {
    if (x == fa[x]) return x;
    int root = get(fa[x]); //路径压缩
    val[x] += val[fa[x]];
    val[x] %= 2; //0表示不能分配两个监狱去 1表示能分配到连个监狱去
    return fa[x] = root;
}

int merge(int a, int b, int t) {
    int x = get(a), y = get(b);
    if (x == y) {
        return (val[a] - val[b] - t) % 2 == 0;
    }
    fa[x] = y;
    val[x] = (t + val[b] - val[a] + 2) % 2;
    return 1;
}

struct Data {
    int x, y, c;  
} arr[MAX_M + 5];

bool cmp(const Data &a, const Data &b) {
    return a.c > b.c;
}

int main() {
    int n, m;// 囚犯的 人数， 彼此存在怒气值的对数
    cin >> n >> m;
    init(n); //维护的结点数
    for (int i = 0; i < m; i++) {
        cin >> arr[i].x >> arr[i].y >> arr[i].c;
    }
    sort(arr, arr + m, cmp);
    arr[m].x = arr[m].y = 1; //设定一个特殊的，不可能被分到两个监狱去的项,解决都能分到两个监狱，输出怒气值为0的情况
    arr[m].c = 0;
    for (int i = 0; i <= m; i++) {
        if (merge(arr[i].x, arr[i].y, 1)) continue;
        cout << arr[i].c <<endl;
        break;
    }
    return 0;
}

