#include <iostream>
using namespace std;

int m, n;


struct node {
    int a, b, c;
};

bool cmp(node a, node b) {
    return a.c > b.c;
}

int main() {
    node x[50];

    sort(x, x + 50, cmp);

    return 0;
}
