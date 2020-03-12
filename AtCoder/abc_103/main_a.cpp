#include <bits/stdc++.h>
using namespace std;
typedef int64_t int64;
typedef uint32_t uint;
typedef uint64_t uint64;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    vector<int> vA(3);
    for(uint i=0; i<3; ++i){ cin>>vA[i]; }
    sort(vA.begin(), vA.end());
    
    int64 sum=0ll;
    for(uint i=1; i<3; ++i){
        sum += vA[i] - vA[i-1];
    }
    cout << sum << endl;
    
    return 0;
}
