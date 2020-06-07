#include <iostream>
using namespace std;
#define MAX_N 10000

struct UnionSet {
    int fa[MAX_N + 5], val[MAX_N + 5];
    void init(int x) {
        for (int i = 1; i <= x; i++) {
            fa[i] = i;
            val[i] = 0;
        }
    }
    int get(int x) {
        if (x == fa[x]) return fa[x];
        int root = get(fa[x]);
        val[x] += val[fa[x]];
        val[x] %= 3;
        return fa[x] = root;
    }
    void merge(int a, int b, int c) {
        int aa = get(a), bb = get(b);
        if (aa == bb) return ;
        fa[aa] = bb;
        val[aa] = (c + val[b] - val[a] + 3) % 3;
        return ;
    }
};

UnionSet u;

int main() {
    int n, m;
    cin >> n >> m;
    u.init(n);
    int a, b, c;
    for (int i = 1; i <= m; i++) {
        cin >> a >> b >> c;
        if (a == 1) {
            u.merge(b, c, 2);
        } else {
            if (u.get(b) != u.get(c)) {
                cout << "Unknown" << endl;
            } else {
                switch ((u.val[b] - u.val[c] + 3) % 3) {
                    case 0 : cout << "Tie" << endl; break;
                    case 1 : cout << "Loss" << endl; break;
                    case 2 : cout << "Win" << endl; break;
                }
            }
        }
    }
    return 0;
}
