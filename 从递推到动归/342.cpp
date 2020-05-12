#include <iostream>
using namespace std;
int f[35][35][35][35][35] = {0};
int a[5];

int main() {
    
    for (int i = 0; i < k; i++) {
        cin >> a[i];
    }
    f[0][0][0][0][0] = 1;
    for (int i1 = 0; i1 <= a[0]; i1++) {
    for (int i2 = 0; i2 <= a[1]; i2++) {
    for (int i3 = 0; i3 <= a[2]; i3++) {
    for (int i4 = 0; i4 <= a[3]; i4++) {
    for (int i5 = 0; i5 <= a[4]; i5++) {
        int val = f[i1][i2][i3][i4][i5];
        if (i1 + 1 <= a[0]) f[i1 + 1][i2][i3][i4][i5] += val;
        if (i2 + 1 <= a[1] && i2 + 1 > i1)f[i1][i2 + 1][i3][i4][i5] += val;
        if (i3 + 1 <= a[2] && i3 + 1 > i1 && )f[i1][i2 + 1][i3][i4][i5] += val;
        if (i4 + 1 <= a[3] && i4 + 1 > i1)f[i1][i2 + 1][i3][i4][i5] += val;
        if (i5 + 1 <= a[4] && i5 + 1 > i1)f[i1][i2 + 1][i3][i4][i5] += val;
    }}}}}
    cout << f[a[0][1][2][3][4]] << endl;
    return 0;
}
