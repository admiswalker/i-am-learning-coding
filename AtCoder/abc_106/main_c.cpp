#include <bits/stdc++.h>
using namespace std;
typedef int64_t int64;
typedef uint32_t uint;
typedef uint64_t uint64;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s; cin >> s;
    uint k; cin >> k;
    
    uint idx1=0;
    uint val=1;
    for(uint i=0; i<s.size(); ++i){
        if( s[i]=='1' ){ idx1=i+1; continue; }
        val = s[i] - '0';
        break;
    }
    
    if(k<=idx1){
        cout << 1 << endl;
    }else{
        cout << val << endl;
    }
    
    return 0;
}
