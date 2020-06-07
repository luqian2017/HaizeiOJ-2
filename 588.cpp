#include <iostream>
using namespace std;

int n, ans[35][5000] = {{}, {1}}; //题目给的第一行为1，第二维开足够大就行

int main() {
    cin >> n;
    for (int i = 2; i <= n; i++) {
        int ind = 0;//记录下一行打印位置
        for (int j = 0; ans[i - 1][j] != 0; j++) { //如果此行还有数据就继续读
            //为什么i - 1? 因为需要把第一行的情况也记录在数组中，然后输出
            int x = 1;
            while (ans[i - 1][j] == ans[i - 1][j + 1]) {
                x++; //记录此行连续的字符个数
                j++; //位置被相同字符所占，读取位置也得跟着往后移动
            }
            ans[i][ind++] = x;//几个什么的几
            ans[i][ind++] = ans[i - 1][j]; //几个什么的什么
        }
    }
    for (int i = 0; ans[n][i] != 0; i++) {
        cout << ans[n][i]; //输出最后一行
    }
    cout << endl;
    return 0;
}
