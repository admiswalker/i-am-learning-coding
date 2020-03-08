// ref: https://par.hateblo.jp/entry/2018/06/24/213218
// ref: https://hackmd.io/@Mister/Bk8xU7lzQ?type=view
// ref: https://drken1215.hatenablog.com/entry/2018/06/24/010600
// ref: https://img.atcoder.jp/arc099/editorial.pdf

#include <bits/stdc++.h>
using namespace std;
typedef int64_t int64;
typedef uint32_t uint;
typedef uint64_t uint64;

int64 fn_S(const int64 rhs){
    int64 sum=0ll;
    string s=to_string(rhs);
    for(uint i=0; i<s.size(); ++i){ sum+=s[i]-'0'; }
    return sum;
}

void solver(int64 K){
    int64 sn = 0;
    int64 add = 1;
    for(int64 k=0; k<K; ++k){
        int64 i = sn + add;
        int64 n = sn + add*10;
        if((i * fn_S(n))<(n * fn_S(i))){
            sn = i;
        }else{
            sn = n;
            add *= 10;
        }
        cout << sn << endl;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int64 K; cin >> K;
    solver(K);
    
    /*
    vector<int64> vSN;
    
    cout << "print sunuke numbers" << endl;
    for(int64 n=1; n<K; ++n){
        bool exist=false;
        int64 sx_n = fn_S(n);
        
        for(int64 i=n+1; i<100000; ++i){
            int64 sx_i = fn_S(i);
//            if(((double)i/(double)sx_i)<((double)n/(double)sx_n)){ exist=true; break; }
            if((i * sx_n)<(n * sx_i)){ exist=true; break; }
        }
        
        if(!exist){
            cout << n << endl;
            vSN.push_back(n);
        }
    }
    cout << endl;
    
    cout << "print diff of sunuke numbers" << endl;
    for(uint i=1; i<vSN.size(); ++i){
        cout << vSN[i]-vSN[i-1] << endl;
    }
    //*/
    return 0;
}

/*
100000
print sunuke numbers
1
2
3
4
5
6
7
8
9
19
29
39
49
59
69
79
89
99
199
299
399
499
599
699
799
899
999
1099
1199
1299
1399
1499
1599
1699
1799
1899
1999
2999
3999
4999
5999
6999
7999
8999
9999
10999
11999
12999
13999
14999
15999
16999
17999
18999
19999
20999
21999
22999
23999
24999
25999
26999
27999
28999
29999
39999
49999
59999
69999
79999
89999
99999

print diff of sunuke numbers
1
1
1
1
1
1
1
1     8
10
10
10
10
10
10
10
10
10    9
100
100
100
100
100
100
100
100
100
100
100
100
100
100
100
100
100
100
100   19
1000
1000
1000
1000
1000
1000
1000
1000
1000
1000
1000
1000
1000
1000
1000
1000
1000
1000
1000
1000
1000
1000
1000
1000
1000
1000
1000
1000  28
10000
10000
10000
10000
10000
10000
10000
*/
