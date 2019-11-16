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

void search_x(int& x, int& y, vector<vector<struct elem>>& mat, char ch){
    for(int r=0; r<mat.size(); ++r){
        for(int c=0; c<mat[r].size(); ++c){
            if(mat[r][c].ch != ch){ continue; }
            y = r;
            x = c;
            return;
        }
    }
}

bool search(vector<vector<struct elem>>& mat, int x_begin, int y_begin){
    vector<XY> vecXY;
    vecXY.push_back( XY(x_begin, y_begin) );
    while(vecXY.size()!=0){
        struct XY xy = vecXY.back(); vecXY.pop_back();
        if(xy.y<0 || xy.y>=mat.size() || xy.x<0 || xy.x>=mat[xy.y].size()){ continue; }
        if(mat[xy.y][xy.x].reached){ continue; }
        mat[xy.y][xy.x].reached = true;
        
        if(mat[xy.y][xy.x].ch == '#'){ continue; }
        if(mat[xy.y][xy.x].ch == 'g'){ return true; }
        
        vecXY.push_back( XY(xy.x+1, xy.y  ) );
        vecXY.push_back( XY(xy.x-1, xy.y  ) );
        vecXY.push_back( XY(xy.x  , xy.y+1) );
        vecXY.push_back( XY(xy.x  , xy.y-1) );
    }
    return false;
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
    bool ret = search(mat, x, y);
    
    cout << (ret ? "Yes":"No") << endl;
    
    return 0;
}

