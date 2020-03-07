#include <bits/stdc++.h>
using namespace std;
typedef int64_t int64;
typedef uint32_t uint;
typedef uint64_t uint64;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s; cin >> s;

    int num=0;
    for(uint i=0; i<s.size(); ++i){
        if(s[i]=='+'){ ++num;
        }    else    { --num; }
    }
    
    cout << num << endl;
    
    return 0;
}
