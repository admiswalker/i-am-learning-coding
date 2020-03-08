#include <bits/stdc++.h>
using namespace std;
typedef int64_t int64;
typedef uint32_t uint;
typedef uint64_t uint64;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    uint N; cin >> N;
    
    int64 a; cin >> a;
    int64 max=a;
    int64 min=a;
    for(uint i=1; i<N; ++i){
        cin >> a;
        if(a>max){ max=a; }
        if(a<min){ min=a; }
    }
    cout << max-min << endl;
    
    return 0;
}
