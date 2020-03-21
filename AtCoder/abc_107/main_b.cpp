#include <bits/stdc++.h>
using namespace std;
typedef int64_t int64;
typedef uint32_t uint;
typedef uint64_t uint64;

bool isRowWhite(const vector<char>& vA){
    for(uint i=0; i<vA.size(); ++i){
        if( vA[i]!='.' ){ return false; }
    }
    return true;
}

vector<vector<char>> Tr(const vector<vector<char>>& vvA){
    vector<vector<char>> vvR(vvA[0].size(), vector<char>(vvA.size()));
    for(uint p=0; p<vvA.size(); ++p){
        for(uint q=0; q<vvA[0].size(); ++q){
            vvR[q][p] = vvA[p][q];
        }
    }
    return vvR;
}

vector<vector<char>> compress_row(const vector<vector<char>>& vvA){
    vector<vector<char>> vvR;
    for(uint i=0; i<vvA.size(); ++i){
        if(isRowWhite(vvA[i])){ continue; }
        vvR.push_back(vvA[i]);
    }
    return vvR;
}
vector<vector<char>> compress_col(const vector<vector<char>>& vvA){
    return Tr(compress_row(Tr(vvA)));
}

void print_vv(const vector<vector<char>>& vvA){
    for(uint p=0; p<vvA.size(); ++p){
        for(uint q=0; q<vvA[0].size(); ++q){
            cout << vvA[p][q];
        }
        cout << endl;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    uint H, W; cin >> H >> W;
    vector<vector<char>> vvA(H, vector<char>(W));
    for(uint h=0; h<H; ++h){
        for(uint w=0; w<W; ++w){
            cin >> vvA[h][w];
        }
    }
    
    uint prev_H, prev_W;
    do{
        prev_H = vvA.size();
        prev_W = vvA[0].size();
        vvA = compress_row(vvA);
        vvA = compress_col(vvA);
    }while(prev_H!=vvA.size() || prev_W!=vvA[0].size());
    
    print_vv(vvA);
    
    return 0;
}
