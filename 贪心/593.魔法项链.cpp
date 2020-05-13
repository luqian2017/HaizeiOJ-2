#include <iostream>
#include <string>
using namespace std;

int n, m, ans[30005], mem[30005]; //mem[]存储最后一个滑动窗口后same的状态，方便下次取出直接往后继续计算
char str[30005];

int main() {
    cin >> n >> m >> &str[1]; 
    for (int i = 1; i <= n / 2; i++) { //枚举长度
        int same = 0; //魔力值
        for (int j = 1, k = i + 1; j <= i; j++, k++) {//计算从1开始的魔力值
            if (str[j] == str[k]) {
                same++;
            }
        }
        ans[same]++; //魔力值为几的方法数
        for (int j = 2; j + 2 * i - 1 <= n; j++) { //类比滑动窗口法
            if (str[j - 1] == str[j - 1 + i]) { //前面，str[起点 + 偏移量]
                same--;//相同的就得same - 1，不同same就不变
            }
            if (str[j + i - 1] == str[j + 2 * i - 1]) { //后面
                same++;
            }
            ans[same]++;
        }
        mem[i] = same; //保留最后一个状态
    }
    /*m次操作*/
    for (int i = 0; i < m; i++) {
        int t;
        cin >> t;
        if (t == 2) { //t 为2时输出答案
            cin >> t; //废物利用
            cout << ans[t] << endl;//输出对应魔力值的数量
            continue;
        }
        char l; //新加入一个字符
        cin >> l;
        str[++n] = l;
        /*全新的长度*/
        if (n % 2 == 0) { //若加入后长度为偶数，则计算新长度子串
            int same = 0, mid = n / 2;
            for (int j = 1, k = 1 + mid; j <= mid; j++, k++) {
                if (str[j] == str[k]) {
                    same++;
                }
            }
            ans[same]++;
            mem[mid] = same; //把mid这个状态村起来，因为如果继续加字母的话，mid就会变成之前的状态
        }
        for (int j = 1; j <= (n - 1) / 2; j++) { //将之前所有长度最后状态取出，向后移动
            if (str[n -j - j] == str[n - j]) {
                mem[j]--;
            }
            if (str[n] == str[n - j]) {
                mem[j]++;
            }
            ans[mem[j]]++;
        }
    }
    return 0;
}
