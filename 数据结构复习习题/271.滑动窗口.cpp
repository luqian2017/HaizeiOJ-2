#include <iostream>
using namespace std;
/*单调队列
 * 功能：维护固定结尾，区间内的最大/小值问题（其中存元素下标）
 * 入队操作：队尾入队，会把之前破环单调性的元素都从队尾移出（维护单调性）
 * 出对操作：1、违反单调性被移出 2、对首元素超出维护区间范围
 * */
#define MAX_N 300000
int a[MAX_N + 5];
int q[MAX_N + 5], head = 0, tail = 0; //单调队列存的是下标，左闭右开

int main() {
    int n, k;
    cin >> n >> k;
	/*维护递增的队列*/
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) {
        while (tail - head && a[q[tail - 1]] >= a[i]) tail--; 
        //当单调队列不为空且末尾元素>=待插入元素时,淘汰掉队列中不符合性质（违反维护的单调性）的数据
        q[tail++] = i; //先入队再去检测更新
        if (q[head] <= i - k) head++;
        if (i < k) continue;//先怼k-1个元素到单调队列
        i == k || cout << " "; //控制空格输出
        cout << a[q[head]];
    }
    cout << endl;
    head = tail = 0; //清空单调队列
	/*维护递减队列*/
    for (int i = 1; i <= n; i++) {
        while (tail - head && a[q[tail - 1]] <= a[i]) tail--;
        q[tail++] = i;
        if (q[head] <= i - k) head++;
        if (i < k) continue;
        i == k || cout << " ";
        cout << a[q[head]];
    }
    cout << endl;
    return 0;
}
