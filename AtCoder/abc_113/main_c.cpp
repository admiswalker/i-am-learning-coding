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

string ssprintf(const char* format, ...){
    va_list args;
    va_start(args, format);
    char* buf;
#ifdef _WIN32
    int len = _vscprintf(format, args)+1;
    buf = (char*)malloc(len * sizeof(char));
    vsprintf_s(buf, len, format, args);
#else
    if(vasprintf(&buf, format, args) == -1){
        return std::string("");
    }
#endif
    std::string ret = buf;
    free(buf);
    va_end(args);
    return ret;
}

int main(){
//    ios_base::sync_with_stdio(false);
//    cin.tie(NULL);
    
    uint N, M; cin >> N >> M;
    vector<pair<int, int>> vPY(M);
    vector<vector<int>> vvPY(N);
    for(uint i=0; i<M; ++i){
        int P, Y; cin >> P >> Y;
        vvPY[P-1].push_back( Y );
        vPY[i].first  = P;
        vPY[i].second = Y;
    }
    for(uint i=0; i<vvPY.size(); ++i){
        sort(vvPY[i].begin(), vvPY[i].end());
    }
    
    unordered_map<string, string> ht;
    for(uint pi=0; pi<vvPY.size(); ++pi){
        for(uint yi=0; yi<vvPY[pi].size(); ++yi){
            int P = pi+1;
            int Y = vvPY[pi][yi];
            string key = ssprintf("%06d%06d", P, Y   ); // input
            string val = ssprintf("%06d%06d", P, yi+1); // output
            ht[key] = val;
        }
    }
    
    for(uint i=0; i<vPY.size(); ++i){
        int P = vPY[i].first;
        int Y = vPY[i].second;
        string key = ssprintf("%06d%06d", P, Y);
        cout << ht[key] << endl;
    }
    
    return 0;
}
