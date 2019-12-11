#include <bits/stdc++.h>
using namespace std;

struct VW{
private:
public:
    VW(){}
    VW(const struct VW&  rhs){ v=rhs.v; w=rhs.w; }
    VW(const int64_t v_in, const int64_t w_in){
        v = v_in;
        w = w_in;
    }
    ~VW(){}
    int64_t v;
    int64_t w;
    
    bool operator==(const struct VW& rhs) const;
};
inline bool VW::operator==(const struct VW& rhs) const { return  (rhs.v==this->v && rhs.w==this->w); }

//*
namespace std{
    template<>
    class hash<struct VW>{
    private:
    public:
        inline std::size_t operator()(const struct VW& rhs) const;
    };
}
inline std::size_t std::hash<struct VW>::operator()(const struct VW& rhs) const {
    std::string bytes(reinterpret_cast<const char*>(&rhs), sizeof(struct VW));
    return std::hash<std::string>()(bytes);
}
//*/

/*
struct Hash{
    typedef std::size_t result_type;
    std::size_t operator()(const struct VW& rhs) const;
};
inline std::size_t Hash::operator()(const struct VW& rhs) const {
    std::string bytes(reinterpret_cast<const char*>(&rhs), sizeof(struct VW));
    return std::hash<std::string>()(bytes);
}
//*/

//int64_t dps(const vector<struct VW>& vecVW, unsigned int i, int64_t w){
int64_t dps(unordered_map<struct VW, int>& hT, const vector<struct VW>& vecVW, unsigned int i, int64_t w){
    if(i==vecVW.size()){ return 0; }
    
    auto itr = hT.find( VW(i, w) );
    if(itr != hT.end()){ return itr->second; }
    
    int64_t val;
    int64_t w_minusW = w - vecVW[i].w;
    if(w_minusW<0){
        val = dps(hT, vecVW, i+1, w);
//        val = dps(vecVW, i+1, w);
    }else{
        val = max(dps(hT, vecVW, i+1, w_minusW)+vecVW[i].v, dps(hT, vecVW, i+1, w));
//        val = max(dps(vecVW, i+1, w_minusW)+vecVW[i].v, dps(vecVW, i+1, w));
    }
    
    hT.insert( pair<struct VW,int64_t>(VW(i,w),val) );
    
    return val;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, W; cin >> N >> W;
    vector<struct VW> vecVW(N);
    for(unsigned int i=0; i<vecVW.size(); ++i){ cin >> vecVW[i].v >> vecVW[i].w; }
    
    unordered_map<struct VW, int> hashT;
//    unordered_map<struct VW, int, Hash> hashT;
    cout << dps(hashT, vecVW, 0, (int64_t)W) << endl;
//    cout << dps(vecVW, 0, (int64_t)W) << endl;
    
    return 0;
}
