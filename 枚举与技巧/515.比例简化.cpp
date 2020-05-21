#include <iostream>
using namespace std;
//1、上限不能超过L 2、不能超过原比列 3、互质 4、两比列尽量接近
int a, b, l, aa, bb;
double raw, now = 999999999; //now记录上一次符合要求的比列，先赋最大值，后面差有更小的就可更新

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main() {
    cin >> a >> b >> l;
    raw = (double) a / b; //原比例，记得强转
    for (int i = 1; i <= l; i++) {
        for (int j = 1; j <= l; j++) {
            double t = (double) i / j; //临时比列
            if (t >= raw && t - raw < now - raw && gcd(i, j) == 1) {
                now = t;
                aa = i;
                bb = j;
            }
        }
    }
    cout << aa << " " << bb << endl;
    return 0;
}

