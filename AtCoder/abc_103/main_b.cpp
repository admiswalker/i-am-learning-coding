#include <bits/stdc++.h>
using namespace std;
typedef int64_t int64;
typedef uint32_t uint;
typedef uint64_t uint64;

bool isSame(const char* pS, const char* pTt, const uint n){
    for(uint i=0; i<n; ++i){
        if(pS[i]==pTt[i]){ continue; }
        return false;
    }
    return true;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s; cin >> s;
    string t; cin >> t;
    string tt = t + t;
    
    for(uint i=0; i<s.size(); ++i){
        if(!isSame(&s[0], &tt[i], s.size())){ continue; }
        cout << "Yes" << endl;
        return 0;
    }
    cout << "No" << endl;
    
    return 0;
}
