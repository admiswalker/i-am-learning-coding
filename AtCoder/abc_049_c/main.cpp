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
