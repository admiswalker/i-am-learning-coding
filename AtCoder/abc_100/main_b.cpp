// ref: https://atcoder.jp/contests/abc100/submissions/10524878
#include <bits/stdc++.h>
using namespace std;
typedef int64_t int64;
typedef uint32_t uint;
typedef uint64_t uint64;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int d, n; cin >> d >> n;
    if(n==100){ n=101; }
    cout << (uint64)pow(100,d) * n << endl;
    
    return 0;
}
