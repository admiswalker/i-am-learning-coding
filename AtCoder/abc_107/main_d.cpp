// ref:
// https://kamojirobrothers.hatenablog.com/entry/2018/10/30/215345
// https://drken1215.hatenablog.com/entry/2018/09/08/011500
// https://ta7uw.hatenablog.com/entry/2019/09/29/162635
//
// https://www.slideshare.net/iwiwi/ss-3578491
// https://www.slideshare.net/hcpc_hokudai/binary-indexed-tree

#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
typedef int64_t int64;
typedef uint32_t uint;
typedef uint64_t uint64;

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
#define printn(var) {printf("%s", #var);print(var);}
#define printn_all(var) {printf("%s(%d): ", __func__, __LINE__);printf("%s", #var);print(var);}


template <typename T>
class BIT{
private:
    vector<int> vBit;
    
public:
    BIT(int size): vBit(size+1,(T)0) {}
    ~BIT(){}
    
    void add(int idx, T val);
    T sum(int end);            // sum [1, end) // 1-indexed
    T sum(int begin, int end); // sum [begin, end)
    T lower_bound(T w);        // get min-x with v1 + v2 + ... + vx >= w.
};
template<typename T>
void BIT<T>::add(int i, T val){
    for(; i<(int)vBit.size(); i+=i&-i){ vBit[i] += val; }
}
template<typename T>
T BIT<T>::sum(int i){
    T s = (T)0;
    for(; i>0; i-=i&-i){ s += vBit[i]; }
    return s;
}
template<typename T>
T BIT<T>::sum(int begin, int end){ return sum(end-1) - sum(begin-1); } // begin and end are 1-indexed.
/*
template<typename T>
T BIT<T>::lower_bound(T w){
    if(w<=vBit[0]){ return 0; }
    int sum_i=0;
    int i=1;
    while(i*2<vBit.size()){ i*=2; }
    for(; i>0; i/=2){
        int idx = sum_i+i;
        if(idx<vBit.size() && w>vBit[idx]){
            w -= vBit[idx];
            sum_i += i;
        }
    }
    return sum_i+1;
}
//*/

int main(){
//    ios_base::sync_with_stdio(false);
//    cin.tie(NULL);
    
    int64 N; cin >> N;
    vector<int> vA(N); for(int i=0; i<N; ++i){ cin >> vA[i]; }
    
    const int bias=N+1;
    int low=0, high=INT_MAX;
    while(high-low>1){
        int64 mid = (high+low)/2;
        
        int64 num=0, sum=0;
        BIT<int64> bit(N*2+1); bit.add(sum+bias, 1);
        for(uint i=0; i<N; ++i){
            sum += vA[i]<=mid ? 1:-1;
            num += bit.sum(sum+bias-1); // same as below
//            num += bit.sum(1, sum+bias);
            bit.add(sum+bias, 1);
        }
        
        if(num > (N+1)*N/2/2){ high = mid;
        }        else        { low  = mid; }
    }
    cout << high << endl;
    
    return 0;
}
