// ref of base: https://atcoder.jp/contests/dwacon2018-prelims/submissions/3318731

#include <bits/stdc++.h>
using namespace std;
typedef int64_t int64;

int main(){
    const int64 MOD=1e9+7;
    int N, M;
    cin >> N >> M;

    vector<int> vecA(N+1); vecA[0]=-1;
    vector<int> vecB(M+1); vecB[0]=-1;
//    int a[101], b[101];
//    a[0]=-1, b[0]=-1;
    int cta[101], ctb[101];
    int sa=0, sb=0;
    int ct;
    for(int i=1; i<=N; i++){
//        cin>>a[i]; sa+=a[i];
        cin >> vecA[i]; sa+=vecA[i];
        if(vecA[i]!=vecA[i-1]) ct=1;
        cta[i]=ct;
        ct++;
    }
    for(int i=1; i<=M; i++){
        cin>>vecB[i]; sb+=vecB[i];
        if(vecB[i]!=vecB[i-1]) ct=1;
        ctb[i]=ct;
        ct++;
    }
    int64 dpa[1001]={}, dpb[1001]={};
    dpa[0]=1, dpb[0]=1;
    for(int i=1; i<=N; i++){
        for(int j=cta[i]; j<=sb; j++){
            dpa[j]+=dpa[j-cta[i]];
            dpa[j]%=MOD;
        }
    }
    for(int i=1; i<=M; i++){
        for(int j=ctb[i]; j<=sa; j++){
            dpb[j]+=dpb[j-ctb[i]];
            dpb[j]%=MOD;
        }
    }
    cout<<dpa[sb]*dpb[sa]%MOD<<endl;
    return 0;
}
