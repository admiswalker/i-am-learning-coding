#include <bits/stdc++.h>
using namespace std;

struct XY{
    XY(int x_in, int y_in){ x=x_in; y=y_in; }
    ~XY(){}
    int x;
    int y;
};

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

int vec_dx[] = {1, 0, -1,  0};
int vec_dy[] = {0, 1,  0, -1};

bool search(vector<vector<struct elem>>& mat, int x_begin, int y_begin){
    vector<XY> vecXY;
    vecXY.push_back( XY(x_begin, y_begin) );
    while(vecXY.size()!=0){
        struct XY xy = vecXY.back();
        vecXY.pop_back();
        
        for(int i=0; i<4; ++i){
            int dy = xy.y + vec_dx[i];
            int dx = xy.x + vec_dy[i];
            if(dy<0 || dy>=mat.size() || dx<0 || dx>=mat[dy].size()){ continue; }
            
            if(mat[dy][dx].reached){ continue; }
            mat[dy][dx].reached = true;
            
            if(mat[dy][dx].ch == '#'){ continue; }
            if(mat[dy][dx].ch == 'g'){ return true; }
            vecXY.push_back( XY(dx, dy) );
        }
    }
    return false;
}

int main(){
    int H, W; cin >> H >> W;
    vector<vector<struct elem>> mat; // row-major
    vvec_alloc(mat, H, W);
    
    int x, y;
    for(int r=0; r<mat.size(); ++r){
        string buf;
        cin >> buf;
        for(int c=0; c<mat[r].size(); ++c){
            mat[r][c].ch = (char)buf[c];
            if(mat[r][c].ch=='s'){ y=r; x=c; }
        }
    }
    
    bool ret = search(mat, x, y);
    
    cout << (ret ? "Yes":"No") << endl;
    
    return 0;
}

