#include <bits/stdc++.h>
using namespace std;

struct RowCol{
    RowCol(int r_in, int c_in){ r=r_in; c=c_in; }
    ~RowCol(){}
    int r;
    int c;
};

int vec_dr[] = {1, 0, -1,  0};
int vec_dc[] = {0, 1,  0, -1};

bool search(vector<string>& mat, int r_begin, int c_begin){
    vector<struct RowCol> vecRC;
    vecRC.push_back( RowCol(r_begin, c_begin) );
    while(vecRC.size()!=0){
        struct RowCol rc = vecRC.back();
        vecRC.pop_back();
        
        for(int i=0; i<4; ++i){
            int dr = rc.r + vec_dr[i];
            int dc = rc.c + vec_dc[i];
            if(dr<0 || dr>=mat.size() || dc<0 || dc>=mat[dr].size()){ continue; }
            
            if(mat[dr][dc] == '#'){ continue; }
            if(mat[dr][dc] == 'g'){ return true; }
            mat[dr][dc] = '#';
            vecRC.push_back( RowCol(dr, dc) );
        }
    }
    return false;
}

int main(){
    int H, W; cin >> H >> W;
	vector<string> mat(H);
	
    int r_begin, c_begin;
    for(int r=0; r<mat.size(); ++r){
        cin >> mat[r];
        for(int c=0; c<mat[r].size(); ++c){
            if(mat[r][c]=='s'){ r_begin=r; c_begin=c; }
        }
    }
    
    bool ret = search(mat, r_begin, c_begin);
    
    cout << (ret ? "Yes":"No") << endl;
    
    return 0;
}

