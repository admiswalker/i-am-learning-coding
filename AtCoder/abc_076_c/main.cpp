#include <bits/stdc++.h>
using namespace std;

vector<string> gen_candidates(const string& Sd, const string& T){
    vector<string> vecCand;
    for(int i=0; i<Sd.size()-T.size()+1; ++i){
        int t;
        string buf; buf.clear();
        for(t=0; t<T.size(); ++t){
            if(Sd[i + t] != T[t] && Sd[i + t] != '?'){ break; }
        }
        if(t < T.size()){ continue; }
        for(int k=0;   k<i;         ++k){ buf += ((Sd[k]=='?') ? 'a':Sd[k]); }
        for(int k=0;   k<T.size();  ++k){ buf += T[k]; }
        for(int k=i+t; k<Sd.size(); ++k){ buf += ((Sd[k]=='?') ? 'a':Sd[k]); }
        vecCand.emplace_back(buf);
    }
    return vecCand;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    string Sd; cin >> Sd;
    string T;  cin >> T;
    
    vector<string> vecCand = gen_candidates(Sd, T);
    if(vecCand.size()==0){ cout << "UNRESTORABLE" << endl; return 0; }
    
    sort(vecCand.begin(), vecCand.end());
    cout << vecCand[0] << endl;
    
    return 0;
}

// ref: https://atcoder.jp/contests/abc076/submissions/1717950

// Additional TEST case 1
/*
ab???ba
abcba

candidate1: abcbaba
candidate1: ababcba <--
 */

// Additional TEST case 2
/*
cb???bc
cbabc

candidate1: cbabcbc <--
candidate1: cbcbabc
 */
