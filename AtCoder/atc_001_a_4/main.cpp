// 遅い理由が分からないため，下記 URL から変更してみる．
// ref: https://atcoder.jp/contests/atc001/submissions/3123169

#include <bits/stdc++.h>
using namespace std;

struct cww{cww(){ios::sync_with_stdio(false);cin.tie(0);}}star;
#define rep(i,a,n) for(int i=(a), i##_len=(n); i<i##_len; ++i)
#define rrep(i,a,n) for(int i=(a), i##_len=(n); i>i##_len; --i)
constexpr int dx[] = {1, 0, -1,  0};
constexpr int dy[] = {0, 1,  0, -1};

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

    int H=mat.size();
    int W=mat[0].size();
    while(!vecRC.empty()) {
        int y, x;
        tie(y, x) = vecRC.back(); vecRC.pop_back();
        rep(i, 0, 4){
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (0 <= ny && ny < H && 0 <= nx && nx < W && mat[ny][nx] != '#'){
                if (mat[ny][nx] == 'g') {
                    return true;
                }
                mat[ny][nx] = '#';
                vecRC.emplace_back( make_pair(ny, nx) );
            }
        }
    }
    return false;
}

int main(){
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
