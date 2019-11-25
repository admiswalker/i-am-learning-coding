#include <bits/stdc++.h>
using namespace std;

bool isEqual(const char* pTarget, int t_len, const string& word){
    if(t_len<=word.size()){ return false; }
    
    for(int i=0; i<word.size(); ++i){
        if(pTarget[i]!=word[i]){ return false; }
    }
    return true;
}

int search(const string& target, const vector<string>& vecWord){
    int num=0;
    
    for(int i=0; i<target.size(); ++i){
        for(int n=0; n<vecWord.size(); ++n){
            if(isEqual(&target[i], target.size()-i+1, vecWord[n])){ ++num; i+=vecWord[n].size()-1; break; } // 1ms
//            if(target.compare(i, vecWord[n].size(), vecWord[n])==0){ ++num; i+=vecWord[n].size()-1; break; } // 1~ 2ms
//            if(target.substr(i,vecWord[n].size())==vecWord[n]){ ++num; i+=vecWord[n].size()-1; break; } // 2ms
        }
    }
    
    return num;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T; cin >> T;
    vector<string> vecStr(T);
    for(int i=0; i<T; ++i){ cin >> vecStr[i]; }
    
    const vector<string> vecWord={"tokyo", "kyoto"};
    for(int i=0; i<vecStr.size(); ++i){
        cout << search(vecStr[i], vecWord) << endl;
    }
    
    return 0;
}
