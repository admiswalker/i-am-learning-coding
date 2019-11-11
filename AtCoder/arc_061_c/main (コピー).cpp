/*
#include <bits/stdc++.h>
using namespace std;

int s2i(const char c){ return (int)c-'0'; }
int s2i(const char* pS, const int len){
    int sum=0;
    for(int i=0; i<len; ++i){
        sum = sum*10 + s2i(pS[i]);
    }
    return sum;
}

int sumS(const char* pS, const int len){
    int sum=0;
    
    for(int i=0; i<len; ++i){
        sum += s2i(&pS[0],     i);
        sum += s2i(&pS[i], len-i);
    }
    
    return sum;
}

int sumSN(const char* pS, const int numOfPlus){
    int sum=0;
    
    for(int n=0; n<numOfPlus; ++n){
        sum += sumSN(&s[0], n);
    }
    
    return sum;
}

int sumSN(const string& s, const int numOfPlus){
    int sum=0;
    
//    for(int i=0; i<s.size(); ++i){
//        sum += sumSN(&s[0], i);
//    }
    
    // 0
    sum += sumSN(&s[0], s.size());
    
    // 1
    for(int i=0; i<len; ++i){
        sum += s2i(&s[0],     i);
        sum += s2i(&s[i], len-i);
    }
    
    // 2
    for(int i1=0; i1<len; ++i1){
        for(int i2=0; i2<len; ++i2){
            sum += s2i(&s[0],     i);
            sum += s2i(&s[i], len-i);
        }
    }
    
    return sum;
}

int main(){
    string s; cin >> s;
    vector<char> isPlus(s.size()-1);
    
    int sum=0;
    for(int numOfPlus=0; numOfPlus<s.size(); ++numOfPlus){
//        sum += sumS(&s[0], numOfPlus);
    }
    cout << sum;
    
    return 0;
}
//*/
