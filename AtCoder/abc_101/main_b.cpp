#include <bits/stdc++.h>
using namespace std;
typedef int64_t int64;
typedef uint32_t uint;
typedef uint64_t uint64;

int fn_S(const string& s){
    int sum = 0;
    for(uint i=0; i<s.size(); ++i){
        sum += s[i]-'0';
    }
    return sum;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s; cin >> s;
    int N = stoi(s);
    int SN = fn_S(s);
    
    cout << ((N%SN==0)?"Yes":"No") << endl;
    
    return 0;
}
