#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
//排序规则 a连接b > b连接a

int n;
string str[100005];

bool cmp(string a, string b) {
    return a + b > b + a; //按字典序比较大小
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> str[i]; //以字符串的形式读入
    }
    sort(str, str + n, cmp);
    for (int i = 0; i < n; i++) {
        cout << str[i];
    }
    cout << endl;
    return 0;
}
