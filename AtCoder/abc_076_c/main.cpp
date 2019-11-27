// ref: https://atcoder.jp/contests/abc076/submissions/1717950
#include <bits/stdc++.h>
using namespace std;

//  true: 0以外
// false: 0

int main(){
    iobase::sync_with_stdio(false);
    cin.tie(NULL);
    
    string Sd; cin >> Sd;
    string T;  cin >> T;
    
    for(int i=Sd.size()-T.size(); ~i; --i){ // i!=i_max に同じ?
        int t;
        for(t=0; t<T.size(); ++t){
            if(Sd[i + t] != T[t] && Sd[i + t] != '?'){ break; }
        }
        if(t < T.size()){ continue; }
        for(int t=0; t<i; ++t){ cout << ((Sd[t]=='?') ? 'a':Sd[t]); }
    }
    cout << "UNRESTORABLE" << endl;
    
    return 0;
}


/*
#include <cstdio>
#include <cstring>

char s[100], t[100];
int main(){
    scanf("%s%s", s, t);
    int n = strlen(s), m = strlen(t);
    for(int i = n - m; ~i; --i){
        int j;
        for(j = 0; j < m; ++j){
            if (s[i + j] != t[j] && s[i + j] != '?'){ break; }
        }
        if(j >= m){
            for(int j = 0; j < i; ++j){ putchar((s[j] == '?') ? 'a' : s[j]); }
            for(int j = 0; j < m; ++j){ putchar(t[j]); }
            for(int j = i + m; j < n; ++j){ putchar((s[j] == '?') ? 'a' : s[j]); }
            return 0;
        }
    }
    puts("UNRESTORABLE");
    return 0;
}
//*/
/*
#include <bits/stdc++.h>
using namespace std;

tuple<vector<int>, vector<int>> str2vecBL(const string& str, const char c){
    vector<int> vecBegin, vecLen;
    
    for(int i=0; i<str.size(); ++i){
        if(str[i]!=c){ continue; }
        
        int begin=i;
        int len  =0;
        for(; i<str.size(); ++i, ++len){
            if(str[i]!=c){ break; }
        }
        vecBegin.emplace_back(begin);
        vecLen.emplace_back(len);
    }
    return make_tuple(vecBegin, vecLen);
}

template<typename T>
int argmax(const vector<T>& rhs){
    if(rhs.size()==0){ return -1; }
    
    int idx=0;
    for(int i=1; i<rhs.size(); ++i){
        if(rhs[i]<rhs[idx]){ continue; }
        idx = i;
    }
    return idx;
}

void replace(string& str, const char target, const char replacing){
    for(int i=0; i<str.size(); ++i){
        if( str[i]!=target ){ continue; }
        str[i] = replacing;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    string Sd; cin >> Sd;
    string T; cin >> T;
    
    vector<int> vecBegin, vecLen;
    tie(vecBegin, vecLen) = str2vecBL(Sd, '?');
    printf("vecBegin.size(): %lu\n", vecBegin.size());
    for(int i=0; i<vecBegin.size(); ++i){
        cout << vecBegin[i] << endl;
    }
    printf("vecLen.size(): %lu\n",   vecLen.size());
    for(int i=0; i<vecLen.size(); ++i){
        cout << vecLen[i] << endl;
    }
    
    int maxIdx = argmax(vecLen);
    printf("madIdx: %d\n", maxIdx);
    if(vecLen[maxIdx] != T.size()){
        cout << "UNRESTORABLE" << endl;
        return 0;
    }
    
    int begin = vecBegin[maxIdx];
    for(int i=0; i<T.size(); ++i){
        Sd[begin+i] = T[i];
    }
    
    replace(Sd, '?', 'a');
    
    cout << Sd << endl;
    
    return 0;
}
//*/
