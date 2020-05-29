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

vector<int> cumulativeSum(const vector<int>& v){
    vector<int> v_cSum(v.size()+1, 0);
    for(uint i=0; i<v.size(); ++i){
        v_cSum[i+1] = v[i] + v_cSum[i];
    }
    return v_cSum;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, K; cin >> N >> K;
    vector<int> vX_b(4*K), vX_w(4*K);
    vector<int> vY_b(4*K), vY_w(4*K);
    for(int i=0; i<N; ++i){
        int x, y; char c; cin >> x >> y >> c;
        if(c=='B'){ ++vX_b[x % K]; ++vX_b[x % K + 2*K]; ++vY_b[y % K]; ++vY_b[y % K + 2*K];
        }   else  { ++vX_w[x % K]; ++vX_w[x % K + 2*K]; ++vY_w[y % K]; ++vY_w[y % K + 2*K]; }
    }
    
    vector<int> vX_b_cSum = cumulativeSum(vX_b);
    vector<int> vX_w_cSum = cumulativeSum(vX_w);
    vector<int> vY_b_cSum = cumulativeSum(vY_b);
    vector<int> vY_w_cSum = cumulativeSum(vY_w);
    
    int sum_max=0;
    for(int xk=0; xk<K; ++xk){
        for(int yk=0; yk<K; ++yk){
            // B: begin, E: end
            int xB_b = xk,     xE_b = xk + K;
            int xB_w = xk + K, xE_w = xk + K + K;
            
            int yB_b = yk,     yE_b = yk + K;
            int yB_w = yk + K, yE_w = yk + K + K;
            
            int sum_tmp_b = 0, sum_tmp_w = 0;
            sum_tmp_b += vX_b_cSum[xE_b] - vX_b_cSum[xB_b+1];
            sum_tmp_b += vY_b_cSum[yE_b] - vY_b_cSum[yB_b+1];
            sum_tmp_w += vX_w_cSum[xE_w] - vX_w_cSum[xB_w+1];
            sum_tmp_w += vY_w_cSum[yE_w] - vY_w_cSum[yB_w+1];
            
            sum_max = max(sum_max, sum_tmp_b + sum_tmp_w);
        }
    }
    
    cout << sum_max << endl;
    
    return 0;
}
