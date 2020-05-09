//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
typedef int64_t int64;
typedef uint32_t uint;
typedef uint64_t uint64;
using namespace std;

//---

template <typename T>
inline void print(const T& rhs){ std::cout<<" = "<<rhs<<std::endl; }
template <typename T>
inline void print(const std::vector<T>& rhs){
    std::cout<<" = [ ";
    for(uint i=0; i<rhs.size(); ++i){ std::cout<<rhs[i]<<' '; }
    std::cout<<"]"<<std::endl;
}
template <typename T>
inline void print(const std::vector<std::vector<T>>& rhs){
    std::cout<<" = "<<std::endl;
    std::cout<<"[[ ";
    for(uint p=0; p<rhs.size(); ++p){
        if(p!=0){ std::cout<<" [ "; }
        for(uint q=0; q<rhs[p].size(); ++q){
            std::cout<<rhs[p][q]<<' ';
        }
        if(p!=rhs.size()-1){ std::cout<<"]"<<std::endl; }
    }
    std::cout<<"]]"<<std::endl;
}
template <typename TL, typename TR>
inline void print(const std::vector<std::pair<TR,TL>>& rhs){
    std::cout<<" = [";
    uint i=0;
    for(; i<rhs.size()-1; ++i){ std::cout<<"[f: "<<rhs[i].first<<", s: "<<rhs[i].second<<"], "; }
    std::cout<<"[f: "<<rhs[i].first<<", s: "<<rhs[i].second<<"]]" << endl;
}
#define printn(var) {printf("%s", #var);print(var);}
#define printn_all(var) {printf("%s(%d): ", __func__, __LINE__);printf("%s", #var);print(var);}

//---

int max_inR(vector<pair<int,int>>& vDisVal, vector<pair<int,int>>& v, int idx_in){
    int ret = 0;
    while(v.size() != 0){
        int val, idx;
        tie(val, idx) = v[0];
        if(idx>=idx_in){
            v.erase(v.begin()+0);
            continue;
        }
        int x, y; tie(x, y) = vDisVal[idx];
        ret = val - 2*x;
        break;
    }
    return max(0, ret);
}
int max_inL(vector<pair<int,int>>& vDisVal, vector<pair<int,int>>& v, int idx_in){
    int ret = 0;
    while(v.size() != 0){
        int val, idx;
        tie(val, idx) = v[0];
        if(idx<=idx_in){
            v.erase(v.begin()+0);
            continue;
        }
        int x, y; tie(x, y) = vDisVal[idx];
        ret = val - 2*x;
        break;
    }
    return max(0, ret);
}

int main(){
//    ios_base::sync_with_stdio(false);
//    cin.tie(NULL);
    
    int N, C; cin >> N >> C;
    vector<pair<int,int>> vDisVal(N);
    vector<pair<int,int>> vValIdx_R;      // clockwise
    vector<pair<int,int>> vValIdx_R_sort; // clockwise
    vector<pair<int,int>> vValIdx_L;      // counterclockwise
    vector<pair<int,int>> vValIdx_L_sort; // counterclockwise
    for(int i=0; i<N; ++i){
        int x, y; cin >> x >> y;
        vDisVal[i] = make_pair(x, y);
    }
//    printn(vDisVal);
    
    // R
    int prevVal=0, prevX=0;
    for(int i=0; i<N; ++i){
        int x, y; tie(x, y) = vDisVal[i];
        int val = prevVal + y - (x-prevX);
        vValIdx_R.push_back( make_pair(val, i) );
        prevVal = val;
        prevX   = x;
    }
    printn(vValIdx_R);
    vValIdx_R_sort = vValIdx_R;
    sort(vValIdx_R_sort.begin(), vValIdx_R_sort.end());
    // L
    prevVal=0; prevX=0;
    for(int i=N-1; i>=0; --i){
        int x, y; tie(x, y) = vDisVal[i];
        x = C-x;
        int val = prevVal + y - (x-prevX);
        vValIdx_L.push_back( make_pair(val, i) );
        prevVal = val;
        prevX   = x;
    }
    printn(vValIdx_L);
    vValIdx_L_sort = vValIdx_L;
    sort(vValIdx_L_sort.begin(), vValIdx_L_sort.end());
    
    int sum=INT_MIN;
    // R
    for(int i=0; i<N; ++i){
        int x, y; tie(x, y) = vDisVal[i];
        int val, idx; tie(val, idx) = vValIdx_R[i];
        int tmp = val + max_inR(vDisVal, vValIdx_L_sort, idx);
        sum = max(sum, tmp);
    }
    // L
    for(int i=0; i<N; ++i){
        int val, idx; tie(val, idx) = vValIdx_L[i];
        int tmp = val + max_inL(vDisVal, vValIdx_R_sort, idx);
        sum = max(sum, tmp);
    }
    
    cout << sum << endl;
    
    return 0;
}
