#include <bits/stdc++.h>
using namespace std;
typedef int64_t int64;
typedef uint32_t uint;
typedef uint64_t uint64;

bool solver(const string& s){
    if(s[0]!='A'){ return false; }

    uint numOfLC=0;
    for(uint i=2; i<s.size()-1; ++i){
        if(s[i]=='C'){ ++numOfLC; }
    }
    if(numOfLC!=1){ return false; }
    
    uint numOfL=0;
    for(uint i=0; i<s.size(); ++i){
        if('A'<=s[i] && s[i]<='Z'){ ++numOfL; }
    }
    if(numOfL!=2){ return false; }
    
    return true;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    string s; cin >> s;
    cout << (solver(s) ? "AC":"WA") << endl;
    
    return 0;
}
