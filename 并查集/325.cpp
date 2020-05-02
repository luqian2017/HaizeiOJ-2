#include <iostream>
#include <map>
#include <string>

using namespace std;

#define MAX_N 10000
int fa[MAX_N + 5], val[MAX_N + 5];

void init(int n) {
    for (int i = 1; i <= n ; i++) {
        fa[i]= i;
        val[i] = 0; //0 表示和为偶数个， 1表示和为奇数个
    }
    return ;
}

int get(int x) {
    if (x == fa[x]) return x;
    int root = get(fa[x]);
    val[x] += val[fa[x]]; //权值压缩
    val[x] %= 2;
    return fa[x] = root; //路径压缩
}

int merge(int x, int y, int t) { //t = 0 偶数， t = 1 奇数
    int a = get(x), b = get(y);
    if (a == b) {
        return (val[x] - val[y] -t) % 2 == 0; //判断添加的关系是否正确
    }
    fa[a] = b;
    val[a] = (t + val[y] - val[x] + 2) % 2;
    return 1;
}

/*坐标重映射*/
map<int, int> ind;
int ind_cnt = 0; //记数

struct Date {
    int x, y;
    string t;
} arr[MAX_N + 5];


int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> arr[i].x  >> arr[i].y >> arr[i].t;
        arr[i].y += 1; //要映射成左闭右开
        ind[arr[i].x] = 0;
        ind[arr[i].y] = 0;
    }
    
    /*坐标重映射*/
    for (auto iter = ind.begin(); iter != ind.end(); iter++) {
        iter->second = (++ind_cnt);
    }

    init(ind_cnt);
    for (int i = 0; i < m; i++) {
        if (merge(ind[arr[i].x], ind[arr[i].y], arr[i].t[0] == 'o')) continue; //条件表达式是为了 偶数传0，奇数传1
        cout << i << endl; //最后一次正确时的i
        return 0;
    }
    cout << m << endl;
    return 0;
}
