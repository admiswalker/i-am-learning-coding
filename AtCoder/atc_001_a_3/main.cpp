#include <bits/stdc++.h>
using namespace std;

int vec_dr[] = {1, 0, -1,  0};
int vec_dc[] = {0, 1,  0, -1};

bool search(vector<string>& mat, int r_begin, int c_begin){
    vector<pair<int,int>> vecRC;
    vecRC.push_back( pair<int,int>(r_begin, c_begin) );
    while(vecRC.size()!=0){
        pair<int,int> rc = vecRC.back();
        vecRC.pop_back();
        
        for(int i=0; i<4; ++i){
            int dr = rc.first  + vec_dr[i];
            int dc = rc.second + vec_dc[i];
            if(dr<0 || dr>=mat.size() || dc<0 || dc>=mat[dr].size()){ continue; }
            
            if(mat[dr][dc] == '#'){ continue; }
            if(mat[dr][dc] == 'g'){ return true; }
            mat[dr][dc] = '#';
            vecRC.push_back( pair<int,int>(dr, dc) );
        }
    }
    return false;
}

pair<int,int> secrch_x(const vector<string>& mat, char x){
    for(int r=0; r<mat.size(); ++r){
        for(int c=0; c<mat[r].size(); ++c){
            if(mat[r][c]==x){
                return pair<int,int>(r, c);
            }
        }
    }
    return pair<int,int>(0, 0);
}

int main(){
    int H, W; cin >> H >> W;
	vector<string> mat(H);
    for(int r=0; r<mat.size(); ++r){
        cin >> mat[r];
    }
    
    int r_begin, c_begin;
    tie<int,int>(r_begin, c_begin) = secrch_x(mat, 's');
    
    bool ret = search(mat, r_begin, c_begin);
    
    cout << (ret ? "Yes":"No") << endl;
    
    return 0;
}
