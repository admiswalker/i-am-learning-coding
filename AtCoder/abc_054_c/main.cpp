#include <bits/stdc++.h>
using namespace std;

// use mat as col-major
#define MatC(mat, r, c) mat[c][r]

vector<int> mat2elemNum(vector<vector<int>>& mat, int vertex_idx){
    vector<int> ret;
    for(int r=0; r<mat[0].size(); ++r){
        if( MatC(mat, r, vertex_idx)==1 ){
            ret.emplace_back(r);
        }
    }
    return ret;
}

int count_path(const vector<vector<int>>& mat){
    int sum=0;
    int end=mat.size()-1;
    
    vector<tuple<int,int>> vecRCN; // row index, col index, num
    vector<int> vecR = mat2elemNum(mat, 0);
    for(int i=0; i<vecR.size(); ++i){
        vecRCN.emplace_back( make_pair(vecR[i], 0, 0) );
    }
    
    while(!vecRCN.empty()){
        int row, col, num;
        tie(row, col, num) = vecRCN.back(); vecRCN.pop_back();
        if(num==end){ sum++; continue; }
        
        num++;
        if(MatC(mat, row, col)){ ; }
    }
    
    return sum;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> N >> M;
    vector<vector<int>> mat(N, vector<int>(N, 0));
    for(int i=0; i<N; ++i){
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        matC_m(mat, a, b) = 1;
        matC_m(mat, b, a) = 1;
    }
    
    int paths = count_path(mat);
    cout << paths << endl;
    
    return 0;
}
