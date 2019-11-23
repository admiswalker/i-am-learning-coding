#include <bits/stdc++.h>
using namespace std;

int search(vector<string>& matMap, int r_begin, int c_begin, int r_end, int c_end){
    vector<vector<int>> matStep(matMap.size(), vector<int>(matMap[0].size(), 0));
    
    queue<tuple<int,int,int>> queRCS;
    queRCS.push( make_tuple(r_begin, c_begin, 0) );
    
    while(queRCS.size()!=0){
        int row, col, steps;
        tie(row, col, steps) = queRCS.front(); queRCS.pop();
        
        if(matMap[row][col]=='#'){ continue; }
        
        if(matStep[row][col]!=0){ continue; }
        matStep[row][col]=steps;
        steps++;
        
        queRCS.push( make_tuple(row-1, col  , steps) );
        queRCS.push( make_tuple(row+1, col  , steps) );
        queRCS.push( make_tuple(row  , col-1, steps) );
        queRCS.push( make_tuple(row  , col+1, steps) );
    }
    
    return matStep[r_end][c_end];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int rows, cols, r_begin, c_begin, r_end, c_end;
    cin >> rows >> cols;
    cin >> r_begin >> c_begin;
    cin >> r_end   >> c_end;
    
    vector<string> matMap(rows);
    for(int r=0; r<matMap.size(); ++r){
        cin >> matMap[r];
    }
    
    int steps = search(matMap, r_begin-1, c_begin-1, r_end-1, c_end-1);
    cout << steps << endl;
    
    return 0;
}
