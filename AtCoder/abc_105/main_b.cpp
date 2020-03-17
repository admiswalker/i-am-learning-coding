#include <bits/stdc++.h>
using namespace std;
typedef int64_t int64;
typedef uint32_t uint;
typedef uint64_t uint64;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    vector<bool> vTF(100, false);
    for(uint p=0; ; ++p){
        for(uint q=0; ; ++q){
            if(4*p+7*q>100){ break; }
            vTF[4*p+7*q] = true;
        }
        if(4*p>100){ break; }
    }
    
    uint N; cin >> N;
    cout << (vTF[N] ? "Yes":"No") << endl;
    
    return 0;
}
