#include <iostream>
using namespace std;

char ans[2200][2200]; // 后一个图形的答案不影响前一个图形的答案所以可以将它们存在同一个二维数组中
int num[10] = {0, 1, 3, 9, 27, 81, 243, 729, 2187};

void func(int x, int y, int n) {
    if (n == 1) {
        ans[x][y] = 'X';
        return ;
    }
    func(x, y, n - 1);
    func(x, y + num[n] / 3 * 2, n - 1); // x, y的初始值为1, 1 所以计算坐标时不用 + 1
    func(x + num[n] / 3 * 2, y, n - 1);
    func(x + num[n] / 3 * 2, y + num[n] / 3 * 2, n - 1);
    func(x + num[n] / 3, y + num[n] / 3, n - 1);
    return ;
}

int main() {
    func(1, 1, 7); // 使用递归，将问题规模化小
    int n;
    while (cin >> n) {
        if (n == -1) {
            break;
        }
        for (int i = 1; i <= num[n]; i++) {
            for (int j = 1; j <= num[n]; j++) {
                if (ans[i][j] == 'X') cout << 'X';
                else cout << ' ';
            }
            cout << endl;
        }
        cout << "-" << endl;
    }
    return 0;
}
