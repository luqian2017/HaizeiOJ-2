/*一个集合中最近点对*/
#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<iomanip>
#include<algorithm>
#include<map>
#include<vector>
using namespace std;

struct node {
    double x, y;
};

bool cmp(node a, node b) {
    if(a.x == b.x) return a.y < b.y;
    return a.x < b.x;
}

int n;
node p[100005];

double dis(int p1, int p2) {
    return sqrt((p[p1].x - p[p2].x) * (p[p1].x - p[p2].x) +  (p[p1].y - p[p2].y) * (p[p1].y - p[p2].y));
}

double func(int l, int r) {
    if(l == r) {
        return 222222222222;//返回一个极大值，不影响结果
    }
    if(l + 1 == r) {
        return dis(l, r);
    }
    int mid = (l + r) >> 1; //分为两部分
    double d = min(func(l, mid), func(mid + 1, r));//左集合，右集合找一个最小的
    for(int i = mid; i >= l && p[mid].x - p[i].x < d; i--) {//求两个集合之间最小的一个
        for(int j = mid + 1; j < r && p[j].x - p[mid].x < d; j++) {
            d = min(d, dis(i, j));//与两个集合中最小的那个比较
        }
    }
    return d;
}

int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%lf%lf", &p[i].x, &p[i].y);
    }
    sort(p, p + n, cmp);
    double ans = func(0, n - 1);

    printf("%lf\n", ans);
    return 0;
}
