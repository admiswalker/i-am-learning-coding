#include <bits/stdc++.h>
using namespace std;

struct place{
    int begin;
    int len;
};

vector<struct place> str2vec_X(const string str& str, const char c){
    vector<struct place> ret;
    
    for(int i=0; i<str.size()-1; ++i){
        if(str[i]!=c){ continue; }
        
        struct place buf;
        buf.begin = i;
        for(buf.len=0; l<str.size()-1; ++buf.len){
            if(str[i]!=str[i+1]){ break; }
        }
    }
}

int vecPlace2maxLen(){
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    string Sd; cint >> Sd;
    string T; cint >> T;
    
    vector<tuple<int,int>> = str2vec_X(string str& str, const char c);
    
    return 0;
}
