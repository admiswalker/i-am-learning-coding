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

void test_print(){
    uint i=123;
    printn(i);
    
    vector<int> v={1,2,3};
    printn(v);
    
    vector<vector<int>> vv={{1,2,3}, {4,5,6}, {7,8,9}};
    printn(vv);
    
    vector<vector<int>> vv0={{}};
    printn(vv0);
}

int main(){
//    ios_base::sync_with_stdio(false);
//    cin.tie(NULL);
    
    int A, B; cin >> A >> B;
    int ans=0;
    
    cout << ans << endl;
    
//    test_print();
    
    return 0;
}
