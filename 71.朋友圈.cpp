#include <iostream>
using namespace std;
#define MAX_N 10000
#define MAX_M 100000

struct UnionSet {
    int fa[MAX_N + 5];
    void init(int x) {
        for (int i = 1; i <= x; i++) {
            fa[i] = i;
        }
    }
    int get(int x) {
        return fa[x] = (x - fa[x] ? get(fa[x]) : x);
    }
    void merge(int a, int b) {
        fa[get(a)] = get(b);
    }
};

UnionSet u;

int main() {
    int n, m, a, b, c;
    cin >> n >> m;
    u.init(n);
    for (int i = 1; i <= m; i++) {
        cin >> a >> b >> c;
        switch(a) {
        case 1 : u.merge(b, c); break;
        case 2 : cout << (u.get(b) - u.get(c) ? "No" : "Yes") << endl; break;
        }
    }
    return 0;
}
