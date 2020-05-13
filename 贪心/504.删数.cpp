#include <iostream>
#include <string>
using namespace std;
//尽可能让数小的在前面，如果不满足就删除前面那个数，如果都满足则删除最后一个数(此时最后一个为最大的数)
string str;
int n;

int main() {
    cin >> str >> n;
    for (int i = 0; i < n ; i++) {
        int ind = str.size() - 1;
        for (int j = 0; j < str.size() - 1; j++) {
            if (str[j] > str[j + 1]) { //构成了大小关系
                ind = j;
                break;
            }
        }
        str.replace(ind, 1, "");
    }
    int flag = 0; //解决前置0问题
    for (int i = 0; i < str.size(); i++) {
        if (str[i] != '0') flag = 1;
        if (flag) cout << str[i];
    }
    cout << endl;
    return 0;
}
