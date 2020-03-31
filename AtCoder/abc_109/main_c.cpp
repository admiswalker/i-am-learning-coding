#include <bits/stdc++.h>
using namespace std;
typedef int64_t int64;

int64 gcd(int64 a, int64 b){
    if(b==0ll){ return a; }
    return gcd(b, a%b);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, X; cin >> N >> X;
    if(N==1){
        int X0; cin >> X0;
        cout << abs(X0-X) << endl;
        return 0;
    }
    
    vector<int> vX(N+1);
    for(int i=0; i<N; ++i){ cin >> vX[i]; }
    vX[N] = X;
    sort(vX.begin(), vX.end());
    
    int64 gcd_val=gcd(vX[1]-vX[0], vX[2]-vX[1]);
    for(int i=3; i<N; ++i){
        gcd_val = gcd(vX[i]-vX[i-1], gcd_val);
    }
    cout << gcd_val << endl;
    
    return 0;
}
