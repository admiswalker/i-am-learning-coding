#include <bits/stdc++.h>
using namespace std;

struct elem{
    elem(){ reached=false; }
    ~elem(){}
    char ch;
    bool reached;
};

template<class T>
void vvec_alloc(vector<vector<T>>& mat, int H, int W){
    mat.resize(H);
    for(int r=0; r<H; ++r){
        mat[r].resize(W);
    }
}

void search_x(int& x, int& y, vector<vector<struct elem>>& mat, char ch){
    for(int r=0; r<mat.size(); ++r){
        for(int c=0; c<mat[r].size(); ++c){
            if(mat[r][c].ch != ch){ continue; }
            x = r;
            y = c;
            return;
        }
    }
}

void search_re(bool& ret, vector<vector<struct elem>>& mat, int x, int y, char ch){ // re: recursive
    if(ret){ return; }
    if(x<0 || x>=mat.size() || y<0 || y>=mat[0].size()){ return; }
    if(mat[x][y].ch == '#'){ return; }
    if(mat[x][y].reached){ return; }
    
    if(mat[x][y].ch == ch){ ret=true; return; }
    
    mat[x][y].reached = true;
    
    search_re(ret, mat, x+1, y  , ch);
    search_re(ret, mat, x-1, y  , ch);
    search_re(ret, mat, x  , y+1, ch);
    search_re(ret, mat, x  , y-1, ch);
}

int main(){
    int H, W; cin >> H >> W;
    vector<vector<struct elem>> mat; // row-major
    vvec_alloc(mat, H, W);
    
    string buf;
    for(int r=0; r<mat.size(); ++r){
        buf.resize(0);
        cin >> buf;
        for(int c=0; c<mat[r].size(); ++c){
            mat[r][c].ch = (char)buf[c];
        }
    }
    
    int x, y; search_x(x, y, mat, 's');
    bool ret=false; search_re(ret, mat, x, y, 'g');
    
    cout << (ret ? "Yes":"No") << endl;
    
    return 0;
}

