// ref: https://atcoder.jp/contests/maximum-cup-2018/submissions/4834449

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (n); i++)
#define rep1(i, n) for(int i = 1; i <= (n); i++)
#define co(x) cout << (x) << "\n"
#define cosp(x) cout << (x) << " "
#define ce(x) cerr << (x) << "\n"
#define cesp(x) cerr << (x) << " "

const int cm = 1 << 16;
char ci[cm];
char *cn = ci + cm;
inline char getcha(){
    if (cn - ci == cm) { fread(ci, 1, cm, stdin); cn = ci; }
    return *cn++;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N, M, L, X;
    cin >> N >> M >> L >> X;
    
//    vector<int> V[1000];
    vector<vector<int>> place2laps(M);
    
    for(int i=0; i<N; ++i){
        int a; cin >> a;
        int div = a / M;
        int mod = a - M*div; // same as a "a % M"
//        V[mod].push_back(div);
        place2laps[mod].push_back(div);
    }
    
    int D[2][1000];
    rep(i, 2000) *(D[0] + i) = 1e9;
    D[0][0] = 1;
    D[1][0] = 1;
    for(int i=1; i<M; ++i){
        if( !place2laps[i].size() ){ continue; }
        
        sort(place2laps[i].begin(), place2laps[i].end());
        
        vector<pair<int, int>> V2;
        int k1 = 0; // place
        int k2 = 0; // numOfLaps
//        for(int j=0; j<V[i].size(); ++j){
        for(unsigned int j=0; j<place2laps[i].size(); ++j){
//            int buf =V [i][j];
            int laps = place2laps[i][j];
            k1 += i;
            k2 += laps;
            if (k1 >= M) {
                k1 -= M;
                k2++;
            }
            if (k1 == 0) continue;
            V2.push_back( make_pair(k1, k2) );
        }
        vector<pair<int, int>> V3;
        for(int j=0; j<M; ++j){
            if(*(D[0] + j) < 5e8){
                for(auto p : V2){
                    int b = p.first;
                    int c = p.second;
                    if(j + b >= M){
                        b -= M;
                        c++;
                    }
                    *(D[1] + j + b) = min(*(D[1] + j + b), *(D[0] + j) + c);
                }
            }
        }
        if(*(D[1] + L) < X){
            printf("Yes\n");
            return 0;
        }
        memcpy(D[0], D[1], 4 * M);
    }
    printf("No\n");
    
    return 0;
}
