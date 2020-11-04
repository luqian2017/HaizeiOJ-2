#include <iostream>
using namespace std;

int n, num[25], check[1005] = {1}, ans;

void func(int s, int sum) {
    if (check[sum] == 0) {
        ans += 1;
        check[sum] = 1;
    }
    for (int i = s; i < n; i++) {
        sum += num[i];
        func(i + 1, sum);
        sum -= num[i];
    }
    return ;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> num[i];
    }
    func(0, 0); //选数的起点和现在的体积和
    cout << ans << endl;
    return 0;
}
