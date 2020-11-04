#include <iostream>
#include <algorithm>
using namespace std;

int n, x, cost[45], set[2][9961480], cnt[2];

void func(int set_num, int start, int end, int sum) {
    if (sum > x) return ;
    for (int i = start; i < end; i++) {
        sum += cost[i];
        set[set_num][cnt[set_num]++] = sum;
        func(set_num, i + 1, end, sum);
        sum -= cost[i];
    }
    return ;
}

int main() {
    while (cin >> n >> x) {
        cnt[0] = cnt[1] = 0;
        for (int i = 0; i < n; i++) {
            cin >> cost[i];
        }
        func(0, 0, n / 2, 0);
        func(1, n / 2, n, 0);
        sort(set[1], set[1] + cnt[1]);
        int flag = 0;
        for (int i = 0; i < cnt[0]; i++) {
            int target = x - set[0][i], l = 0, r = cnt[1] - 1;
            while (l <= r) {
                int mid = (l + r) / 2;
                if (set[1][mid] == target) {
                    cout << "YES" << endl;
                    flag = 1;
                    break;
                } else if (set[1][mid] < target) l = mid + 1;
                else r = mid - 1;
            }
            if (flag) break;
        }
        if (!flag) cout << "NO" << endl;
    }
    return 0;
}
