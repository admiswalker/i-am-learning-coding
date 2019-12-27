// ref:
// [1] 蝶本 第 2 版 page. 62 個数制限付き部分和問題
// [2] https://atcoder.jp/contests/maximum-cup-2018/submissions/4834449

#include <bits/stdc++.h>
using namespace std;

//bool dps(const vector<int>& vecA, int N, int M, int L, int X){
bool dps(const vector<pair<int, int>>& vecPL, int N, int M, int L, int X){
    
    vector<int> dp_min (M, INT_MAX); dp_min [0] = 0;
    vector<int> dp_prev(M, INT_MAX); dp_prev[0] = 0;
    
    for(unsigned int i=0; i<vecPL.size(); ++i){
        for(int p=0; p<M; ++p){
            if(dp_prev[p] == INT_MAX){ continue; }
            
            int place = p + vecPL[i].first;
            int laps  =     vecPL[i].second;
            if(place >= M){ place-=M; ++laps; }
            
            dp_min[place] = min(dp_min[place], dp_prev[p]+laps);
        }
        if(dp_min[L] < X){ return true; }
        dp_prev = dp_min;
    }
    return false;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, M, L, X;
    cin >> N >> M >> L >> X;
//    vector<int> vecA(N);
//    for(int i=0; i<N; ++i){ cin >> vecA[i]; }
    vector<pair<int, int>> vecPL(N);
    for(int i=0; i<N; ++i){
        int a; cin >> a;
        int div = a / M;
        int mod = a - M*div; // same as a "a % M"
        vecPL[i] = make_pair(mod, div);
    }
    
    bool TF = dps(vecPL, N, M, L, X);
    cout << (TF ? "Yes":"No") << endl;
    
    return 0;
}
