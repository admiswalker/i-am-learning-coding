// ref: https://atcoder.jp/contests/abc054/submissions/8585283
#include <bits/stdc++.h>
using namespace std;

void search(int& sum, const vector<vector<int>>& mat, vector<int>& vecIsUsed, int r, int steps){
    if(steps == mat.size()-1){ ++sum; return; }
    
    for(int i=1; i<mat.size(); ++i){
        if(mat[r][i]==0 || vecIsUsed[i]==1){ continue; }
        vecIsUsed[i] = 1;
        search(sum, mat, vecIsUsed, i, steps+1);
        vecIsUsed[i] = 0;
    }
    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, M;
    cin >> N >> M;
    vector<vector<int>> mat(N, vector<int>(N, 0));
    
    for(int i=0; i<M; ++i){
        int a; cin >> a; --a;
        int b; cin >> b; --b;
        mat[a][b] = 1;
        mat[b][a] = 1;
    }
    
    vector<int> vecIsUsed(N, 0);
    int sum=0;
    search(sum, mat, vecIsUsed, 0, 0);
    cout << sum << endl;
    
    return 0;
}
