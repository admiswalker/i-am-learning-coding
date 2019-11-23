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

int count_path(const vector<vector<int>>& mat){
    int sum=0;
    int end=mat.size()-1;
    
    vector<tuple<int,int>> vecCN; // col index, num
    vector<int> vecR = col2vecRow(mat, 0);
    for(int i=0; i<vecR.size(); ++i){
        vecCN.emplace_back( make_pair(vecR[i], 0) );
    }
    
    while(!vecCN.empty()){
        int col, num;
        tie(col, num) = vecCN.back(); vecCN.pop_back();
        if(num==end){ sum++; continue; }
        
        num++;
        vector<int> vecR = col2vecRow(mat, col);
        for(int i=0; i<vecR.size(); ++i){
            vecCN.emplace_back( make_pair(vecR[i], num) );
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
