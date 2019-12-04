#include <bits/stdc++.h>
using namespace std;

template<typename T>
T maxVal(const vector<T>& rhs){
    T lhs=rhs[0];
    for(uint64_t i=1; i<rhs.size(); ++i){
        if(rhs[i]>lhs){ lhs=rhs[i]; }
    }
    return lhs;
}

struct sAB{
    uint64_t width;
    uint64_t imp;   // importance
};

const int BITS_COUNT_TABLE[256] = {
    0, 1, 1, 2, 1, 2, 2, 3, 1, 2, 2, 3, 2, 3, 3, 4,
    1, 2, 2, 3, 2, 3, 3, 4, 2, 3, 3, 4, 3, 4, 4, 5,
    1, 2, 2, 3, 2, 3, 3, 4, 2, 3, 3, 4, 3, 4, 4, 5,
    2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6,
    1, 2, 2, 3, 2, 3, 3, 4, 2, 3, 3, 4, 3, 4, 4, 5,
    2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6,
    2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6,
    3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7,
    1, 2, 2, 3, 2, 3, 3, 4, 2, 3, 3, 4, 3, 4, 4, 5,
    2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6,
    2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6,
    3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7,
    2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6,
    3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7,
    3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7,
    4, 5, 5, 6, 5, 6, 6, 7, 5, 6, 6, 7, 6, 7, 7, 8,
};
int numofbits2(uint64_t bits){
    int num = 0;
    for (int i=0 ; i<sizeof(bits) ; i++ ) {
        num += BITS_COUNT_TABLE[((unsigned char*)&bits)[i]];
    }
    return num;
    // ref: http://www.nminoru.jp/~nminoru/programming/bitcount.html
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    uint64_t W;    cin >> W;
    uint64_t N, K; cin >> N >> K;
    vector<struct sAB> vecAB(N);
    for(uint64_t i=0; i<vecAB.size(); ++i){
        cin >> vecAB[i].width >> vecAB[i].imp;
    }
    
    uint64_t numChoices = (uint64_t)1 << vecAB.size();
    
    uint64_t ans=0;
    for(uint64_t n=0; n<numChoices; ++n){
        int num=numofbits2(n);
        if(num>K){ continue; }
        
        uint64_t width=0;
        uint64_t imp=0;
        for(uint64_t i=0; i<vecAB.size(); ++i){
            if( !(n&((uint64_t)1<<i)) ){ continue; }
            width += vecAB[i].width;
            imp   += vecAB[i].imp;
        }
        if(width>W){ continue; }
        
        if(ans<imp){ ans=imp; }
    }
    
    cout << ans << endl;
    
    return 0;
}
