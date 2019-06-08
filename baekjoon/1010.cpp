#include <iostream>
#include <cstring>
using namespace std;

int d[31][31]; // combination
int foo(int n, int r) {
    if (n == r || r == 0)
        return 1;
    if (d[n][r]) return d[n][r];
    return d[n][r] = foo(n - 1, r - 1) + foo(n - 1, r); // nCr = n-1Cr-1 + n-1Cr
}
int main() {
    int N;
    cin >> N;
    while (N--) {
        memset(d, 0, sizeof(d));
        
        int n, m;
        cin >> n >> m;
        cout << foo(m, n) <<endl;
    }
}
