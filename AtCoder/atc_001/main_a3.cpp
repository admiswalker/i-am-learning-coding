#include <bits/stdc++.h>
using namespace std;

int vec_dr[] = {1, 0, -1,  0};
int vec_dc[] = {0, 1,  0, -1};

pair<int,int> secrch_x(const vector<string>& mat, char x){
    for(int r=0; r<mat.size(); ++r){
        for(int c=0; c<mat[r].size(); ++c){
            if(mat[r][c]==x){
                return make_pair(r, c);
            }
        }
    }
    return make_pair(0, 0);
} 

bool search(vector<string>& mat, int r_begin, int c_begin){
    vector<pair<int,int>> vecRC;
    vecRC.emplace_back( make_pair(r_begin, c_begin) );
    
    while(vecRC.size()!=0){
        int row, col;
        tie(row, col) = vecRC.back();
        vecRC.pop_back();
        
        for(int i=0; i<4; ++i){
            int dr = row + vec_dr[i];
            int dc = col + vec_dc[i];
            if(dr<0 || dr>=mat.size() || dc<0 || dc>=mat[0].size()){ continue; }
            
            if(mat[dr][dc] == '#'){ continue; }
            if(mat[dr][dc] == 'g'){ return true; }
            mat[dr][dc] = '#';
            vecRC.emplace_back( make_pair(dr, dc) );
        }
    }
    return false;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int H, W; cin >> H >> W;
	vector<string> mat(H);
    for(int r=0; r<H; ++r){
        cin >> mat[r];
    }
    
    int r_begin, c_begin;
    tie(r_begin, c_begin) = secrch_x(mat, 's');
    
    bool ret = search(mat, r_begin, c_begin);
    cout << (ret ? "Yes":"No") << endl;
    
    return 0;
}
