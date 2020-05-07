#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

struct node {
    double val, cost, num; //收获，花费，性价比
};

double m, n, ans;
node s[1005];


bool cmp(node a, node b) {
    return a.num > b.num;
}

int main() {
    cin >> m >> n;
    for (int i = 0; i < n; i++) {
        cin >> s[i].val >> s[i].cost;
        s[i].num = s[i].val / s[i].cost;
    }
    sort(s, s + (int)n, cmp); //将性价比降序排序
    for (int i = 0; i < n; i++) { //遍历仓库
        if (m <= s[i].cost) {
            ans += s[i].num * m; //买不下整个仓库
            break;
        }
        ans += s[i].val; //能买下整个仓库
        m -= s[i].cost;
    }
    printf("%.3f\n", ans);
    return 0;
}
