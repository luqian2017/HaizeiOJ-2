#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

struct edge {
    int to, next;
};

edge edg[10000];
int n, m, edg_cnt, ans_cnt, head[30], in_degress[30];
char ans[30];

void insert_edg(int a, int b, int x) {
    edg[x].to = b;
    edg[x].next = head[a];
    edg[a] = x;
    edg_cnt = x + 1;
    in_degress[b]++;
}

int check() {
    int temp_in[30];
    queue<int> que;
    for (int i = 1; i <= n; i++) {
        temp_in[i] = in_degress[i];
        if (temp_in[i] == 0) {
            que.push(i);
        }
    }
    int f1 = que.size(); //起点的点的数量 如果不为1 说明答案不正确
    while (!que.empty()) {
        int t = que.front(), f2 = 0;
        que.pop();
        for (int i = head[t]; i != -1; i = edg[i].next) {
            int e = edg[i].to;
            temp_in[e]--;
            if (temp_in[e] == 0) {
                if (f2 == 1) {
                    f2 = 2; //f2 为2时  说明答案不确定
                } else {
                    f2 = 1;
                }
                que.push(e);
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        if (temp_in[i] != 0) {
            return 1;
        }
    }
    if (f1 != 1 || f2 == 2) {
        return 0;
    }
}

int main() {
    memset(head, - 1, sizeof(head));
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        char a, b;
        cin >> a >> b >> b;
        insert_edg(a - 'A' + 1, b - 'A' + 1, i);
        int t = check(); //o normal  1 wrong     2 ans
        if (t == 1) {
            cout << "" << i + 1 << "" << endl;
        } else if(t == 2) {
            cout << "" << i + 1 << "" << endl;
            for (int i = 1; i <= ans_cnt; i++) {
                cout << ans[i];
            }
            cout << "." << endl;
            break;
        }
    }
    return 0;
}

