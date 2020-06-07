#include <iostream>
using namespace std;
#define MAX_N 1005
char g[MAX_N + 5][MAX_N + 5];
int n, m;

struct UnionSet {
    int fa[MAX_N * MAX_N];
    void init(int x) {
        for (int i = 0; i <= x; i++) fa[i] = i;
    }
    int get(int x) {
        return fa[x] = (x == fa[x] ? x : get(fa[x]));
    }
    void merge(int a, int b) {
        fa[get(a)] = get(b);
    }
};

int index (int i, int j) {
    return i * m + j + 1;
}

UnionSet u;

int main() {
    cin >> n >> m;
    u.init(n * m);
    for (int i = 0; i < n; i++) cin >> g[i];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (g[i][j] == 'X') continue;
            if (i - 1 >= 0 && g[i - 1][j] == 'O') u.merge(index(i, j), index(i - 1, j));
            if (j - 1 >= 0 && g[i][j - 1] == 'O') u.merge(index(i, j), index(i, j - 1));
            if (i == 0 || i == n - 1) u.merge(index(i, j), 0);
            if (j == 0 || j == m - 1) u.merge(index(i , j), 0);
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (g[i][j] == 'X') continue;
            if (u.get(index(i, j)) - u.get(0)) ans++;
        }
    }
    cout << ans << endl;
    return 0;
}
