// ref: https://drken1215.hatenablog.com/entry/2019/03/03/150200

//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
typedef int64_t int64;
typedef uint32_t uint;
typedef uint64_t uint64;

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

int main() {
    uint N; cin >> N;
    vector<int> vH(N);
    for(uint i=0; i<N; ++i){ cin>>vH[i]; }
    
    int cnt = 0;
    for(;;){
        if(*max_element(vH.begin(), vH.end()) == 0){ break; }
        
        for(uint i=0; i<N; ++i){
            if(vH[i]==0){ continue; }
            ++cnt;
            while(i<N && vH[i]!=0){ --vH[i]; ++i; }
        }
    }
    cout << cnt << endl;
}

/*
AC

int main(){
    uint N; cin >> N;
    vector<int> vH(N);
    for(uint i=0; i<N; ++i){ cin>>vH[i]; }
    
    int64 cnt=0ll;
    for(uint i=0;;){
        bool isUpdate=false;
        while( i<vH.size() && vH[i]==0 ){ ++i; } // skip empty
        while( i<vH.size() && vH[i]!=0 ){ --vH[i]; ++i; isUpdate=true; }
        if(isUpdate){ ++cnt; }
        
        if(i==vH.size()){
            if(!isUpdate && *max_element(vH.begin(), vH.end())==0){ break; }
            i=0;
        }
    }
    cout << cnt << endl;
    
    return 0;
}
//*/
/*
AC

int main(){
    uint N; cin >> N;
    vector<int> vH(N);
    for(uint i=0; i<N; ++i){ cin>>vH[i]; }
    
    int64 cnt=0ll;
    for(;;){
        if(*max_element(vH.begin(), vH.end())==0){ break; }
        
        for(uint i=0;;){
            bool isUpdate=false;
            while( i<vH.size() && vH[i]==0 ){ ++i; } // skip empty
            while( i<vH.size() && vH[i]!=0 ){ --vH[i]; ++i; isUpdate=true; }
            if(isUpdate){ ++cnt; }
            
            if(i==vH.size()){ break; }
        }
    }
    cout << cnt << endl;
    
    return 0;
}
//*/
/*
TLE

int main(){
    uint N; cin >> N;
    vector<int> vH(N);
    for(uint i=0; i<N; ++i){ cin>>vH[i]; }
    
    int64 cnt=0ll;
    for(uint i=0;;){
        while( i<vH.size() && vH[i]==0 ){ ++i; } // pass empty
        if(i==vH.size()){ i=0; continue; }
        
        while( i<vH.size() && vH[i]!=0 ){ --vH[i]; ++i; }
        ++cnt;
//        printn(vH);
        
        bool isAllZero=true;
        for(uint i2=0; i2<vH.size(); ++i2){ if(vH[i2]!=0){isAllZero=false;} }
        if(isAllZero){ break; }
    }
    cout << cnt << endl;
    
    return 0;
}
//*/
