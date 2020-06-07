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
    int get (int x) { //路径压缩的同时，也会进行权值压缩
        if (x == fa[x]) return fa[x];
        int root = get(fa[x]);
        val[x] += val[fa[x]]; //先累加压缩前该点到根节点的权值
        val[x] %= 3; // 0 平手， 1 输， 2 赢
        return fa[x] = root;
    }
    void merge(int a, int b, int c) {
        int aa = get(a), bb = get(b);
        if (aa == bb) return ;
        fa[aa] = bb;
        val[aa] = (c + val[b] - val[a] + 3) % 3; //a->aa为val[a], b->bb为val[b],a->b为c,易得，aa->bb 为(c + val[b] - val[a] + 3) % 3
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
            if (u.get(b) != u.get(c)) { //当b,c不在同一个集合中就不能判断他们的关系
                cout << "Unknown" << endl;
            } else {
                switch((u.val[b] - u.val[c] + 3) % 3) { //get(b),get(c)会进行路径和权值压缩，且，现在b,c都已经接到了根节点上，易得，b,c之间的关系为(val[a] - val[b] + 3) % 3, +3 是为了避免负值
                case 0 : cout << "Tie" << endl; break;
                case 1 : cout << "Loss" << endl; break;
                case 2 : cout << "Win" << endl; break;
                }
            }
        }
    }
    return 0;
}
