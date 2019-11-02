#include <bits/stdc++.h>
using namespace std;

bool cmp(const char* lhs, const char* rhs, const int len){
    for(int i=0; i<len; ++i){
        if(lhs[i]!=rhs[i]){ return false; }
    }
    return true;
}

int main(){
    string str; cin >> str; std::reverse(str.begin(), str.end());
    
    string d2 = "dreamer"; // odered by greter length
    string e2 = "eraser";
    string d1 = "dream";
    string e1 = "erase";
    vector<string> vecDE = {d2, e2, d1, e1};
    for(int i=0; i<vecDE.size(); ++i){ std::reverse(vecDE[i].begin(), vecDE[i].end()); }
    
    for(int i=0; i!=str.size();){
        bool TF=false;
        for(int v=0; v<vecDE.size(); v++){
            if( cmp(&str[i], vecDE[v].c_str(), vecDE[v].size()) ){
                i += vecDE[v].size();
                TF=true;
                break;
            }
        }
        if(TF==false){ cout << "NO"; return 0; }
    }
    cout << "YES"; 
    
    return 0;
}

/*
#include <bits/stdc++.h>
using namespace std;

int main(){
    string str; cin >> str; std::reverse(str.begin(), str.end());
    
    string d2 = "dreamer"; // odered by greter length
    string e2 = "eraser";
    string d1 = "dream";
    string e1 = "erase";
    vector<string> vecDE = {d2, e2, d1, e1};
    for(int i=0; i<vecDE.size(); ++i){ std::reverse(vecDE[i].begin(), vecDE[i].end()); }
    
    for(;;){
        bool TF=false;
        for(int i=0; i<vecDE.size(); i++){
            if(str.compare(0, vecDE[i].size(), vecDE[i])==0){
                const char* pStr = str.c_str();
                string buf = &pStr[vecDE[i].size()];
                swap(str, buf);
                TF=true;
                break;
            }
        }
        if(TF==false){ cout << "NO"; return 0; }
        if(str.size()==0){ break; }
    }
    cout << "YES"; 
    
    return 0;
}
*/
