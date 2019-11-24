#include <bits/stdc++.h>
using namespace std;

void search(int& sum, const vector<vector<int>>& mat, vector<int>& vecIsUsed, int row, int steps){
    int N    = mat.size();
    int N_m1 = mat.size()-1;
    if(steps==N_m1){ ++sum; return; }
    
    for(int i=1; i<N; ++i){
        if(mat[row][i]==0){ continue; }
        if(vecIsUsed[i]==1){ continue; }
        vecIsUsed[i] = 1;
        search(sum, mat, vecIsUsed, i, steps+1);
        vecIsUsed[i] = 0;
    }
    return;
}

/*
// 再帰を展開したかったが，
// 単にスタックを積むのであれば，
// もう少し工夫が欲しい・・・？

struct parameters{
    parameters(int steps_in){
        steps = steps_in;
    }
    ~parameters(){}
    int steps;
};

int search(const vector<vector<int>>& mat, int r_begin){
    int N = mat.size();
    int N_m1 = mat.size()-1;
    int sum = 0;
    
    vector<struct parameters> stuck;
    stuck.emplace_back( parameters(0) );
    
    vector<int> vecIsUsed(mat.size(), 0);
    
    while(!stuck.smpty()){
        struct parameters param = stuck.back(); stuck.pop_back();
        if(param.steps==N_m1){ ++sum; continue; }

        for(int i=1; i<N; ++i){
            if(mat[param.row][i]==0){ continue; }
            if(     vecIsUsed[i]==1){ continue; }
            vecIsUsed[i]=1;
            int next_row = ;
            stuck.emplace_back(i, );
            vecIsUsed[i]=0;
        }
    }
    return sum;
}
//*/


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N; cin >> N;
    int M; cin >> M;
    vector<vector<int>> mat(N, vector<int>(N, 0));
    for(int i=0; i<M; ++i){
        int a; cin >> a; --a;
        int b; cin >> b; --b;
        mat[a][b] = 1;
        mat[b][a] = 1;
    }
    
    int sum;
    vector<int> vecIsUsed(mat.size(), 0);
    search(sum, mat, vecIsUsed, 0, 0);
    cout << sum << endl;
    
    return 0;
}
