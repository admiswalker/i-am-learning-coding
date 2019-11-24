// ref: https://atcoder.jp/contests/abc054/submissions/8585283
#include <bits/stdc++.h>
using namespace std;

void search(int& sum, vector<vector<int>>& mat, vector<int>& vecUsed, int r, int steps){
    int N = mat.size();
    if(steps == N){ sum++; return; }
    
    for(int i=1; i<N; ++i){
        if(mat[r][i]==1 && vecUsed[i]==0){
            vecUsed[i] = 1;
            search(sum, mat, vecUsed, i, steps+1);
            vecUsed[i] = 0;
        }
    }
    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, M;
    cin >> N >> M;
    vector<vector<int>> mat(N, vector<int>(N, 0));
    
    for(int i=0; i<N; i++){
        int a; cin >> a; a--;
        int b; cin >> b; b--;
        mat[a][b] = 1;
        mat[b][a] = 1;
    }
    
    vector<int> vecUsed(N, 0);
    int sum=0;
    search(sum, mat, vecUsed, 0, 1);
    cout << sum << endl;
    
    return 0;
}

/*
#include <bits/stdc++.h>
using namespace std;

// use mat as col-major
#define MatC(mat, r, c) mat[c][r]

vector<int> col2vecRow(const vector<vector<int>>& mat, int col_idx){
    vector<int> ret;
    for(int r=0; r<mat[0].size(); ++r){
        if( MatC(mat, r, col_idx)==1 ){
            ret.emplace_back(r);
        }
    }
    return ret;
}

int count_path(const vector<vector<int>>& mat_in){
    int sum=0;
    int end=mat_in.size()-1;
//    int end=mat_in.size();
    
    vector<tuple<vector<vector<int>>,int,int>> vecMatCN; // col index, num
    vector<int> vecR = col2vecRow(mat_in, 0);
    
    vector<vector<int>> matBuf = mat_in;
    for(int i=0; i<vecR.size(); ++i){
        MatC(matBuf, vecR[i], 0) = 0;
    }
    
    for(int i=0; i<vecR.size(); ++i){
        vecMatCN.emplace_back( make_tuple(matBuf, vecR[i], 0) );
    }
    
    while(!vecMatCN.empty()){
        vector<vector<int>> mat;
        int col, num;
        tie(mat, col, num) = vecMatCN.back(); vecMatCN.pop_back();
        if(num==end){ sum++; continue; }
        
        vector<int> vecR = col2vecRow(mat, col);
        vector<vector<int>> matBuf = mat;
        for(int i=0; i<vecR.size(); ++i){
            MatC(matBuf, vecR[i], 0) = 0;
        }
        
        for(int i=0; i<vecR.size(); ++i){
            vecMatCN.emplace_back( make_tuple(matBuf, vecR[i], num+1) ); // あー，，，たぶんこの辺りループしている．（一度来たという印がないから．
        }
    }
    
    return sum;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, M;
    cin >> N >> M;
    vector<vector<int>> mat(N, vector<int>(N, 0));
    for(int i=0; i<N; ++i){
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        MatC(mat, a, b) = 1;
        MatC(mat, b, a) = 1;
    }
    
    int paths = count_path(mat);
    cout << paths << endl;
    
    return 0;
}
//*/
