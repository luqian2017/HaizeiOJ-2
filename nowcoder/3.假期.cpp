#include <iostream>
#include<cstring>
using namespace std;

int n, work[100005], gym[100005], ans[100005][3]; //ans[100005][3] 0 工作， 1 建身， 2 休息

int main() {
    memset(ans, 0x3F, sizeof(ans));
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> work[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> gym[i];
    }
    if (work[1] == 1) {
        ans[1][0] = 0; //休息的天数
    }
    if (gym[1] == 1) {
        ans[1][1] = 0;
    }
    ans[1][2] = 1;
    for (int i = 2; i <= n; i++) {
        if (work[i] == 1) {
            ans[i][0] = min(ans[i - 1][1], ans[i - 1][2]);
        }
        if (gym[i] == 1) {
            ans[i][1] = min(ans[i - 1][0], ans[i - 1][2]);
        }
        ans[i][2] = min(ans[i - 1][0], min(ans[i - 1][1], ans[i - 1][2])) + 1;
    }
    cout << min(ans[n][0], min(ans[n][1], ans[n][2])) << endl;
    return 0;
}

