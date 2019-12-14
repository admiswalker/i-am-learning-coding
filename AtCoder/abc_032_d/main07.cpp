// 速いコードを勉強する．
// 参考：https://atcoder.jp/contests/abc032/submissions/8123494


#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i, n)   for(ll i=0, i##_length=(n); i< i##_length; ++i)
#define all(v) (v).begin(), (v).end()

class Item{
public:
    ll value, weight, index;
    Item() {}
    Item(ll value, ll weight, ll index) : value(value), weight(weight), index(index) {}
};

class KnapsackBB{
public:
    vector<Item> items;
    ll N;
    ll W;
    //現在探索している商品の選び方　used_items[i]=true -> i番目の商品を選択
    vector<bool> used_items;
    //現時点で最適な商品の選び方　opt_items[i]=true -> i番目の商品を選択
    vector<bool> opt_items;
    //現時点で最適な商品の選び方をしたときの価値合計
    ll opt_value=0;

    KnapsackBB(vector<Item> &items, ll W) : items(items), N(items.size()), W(W) {}

    //分枝限定法で探索
    //index=index-1番目の商品までは選択が終わった、index番目からの商品はまだ調べてない
    //value=今のところの価値合計
    //weight=今のところの重さ合計
    void searchbb(int index,ll value,ll weight){
        //全部調べ終わった
        if(index==N){
            if(opt_value < value){
                opt_items=used_items;
                opt_value=value;
            }
            return;
        }

        //緩和問題を解く
        ll tmp_weight=weight;
        double tmp_value=value;
        for(int i=index;i<N;i++){
            if(tmp_weight+items[i].weight == W){
                //緩和問題の解が元の問題でも実現可能→暫定解として使えるかも
                tmp_value+=items[i].value;
                if(opt_value<tmp_value){
                    opt_value=tmp_value;
                    opt_items=used_items;
                    for(int j=index;j<=i;j++){
                        opt_items[j]=true;
                    }
                }
                return;
            }else if(tmp_weight+items[i].weight < W){
                tmp_value+=items[i].value;
                tmp_weight+=items[i].weight;
            }else{
                //重さの余りを詰める
                tmp_value+=(double)items[i].value*(W-tmp_weight)/items[i].weight;
                tmp_weight=W;
                break;
            }
        }

        //緩和問題ですら暫定解を超えられない→これ以上調査する意味がない
        if(tmp_value < opt_value){
            return;
        }

        //重量制限が許されれば、index番目を選ぶ場合で探索
        if(weight+items[index].weight <= W){
            used_items[index]=true;
            searchbb(index+1, value+items[index].value, weight+items[index].weight);
        }
        //index番目を選ばない場合で探索
        used_items[index]=false;
        searchbb(index+1, value, weight);
    }

    ll search(){
        //商品をコスパのよい順に並び替え
        sort(all(items), [](const Item &x, const Item &y) {
                return ((double)x.value/x.weight) > ((double)y.value/y.weight);
            });

        //暫定解として貪欲に選んでみる
        ll tmp_weight=0,tmp_value=0;
        vector<bool> tmp_items(N,false);
        rep(i,N){
            if(tmp_weight+items[i].weight <= W){
                tmp_value+=items[i].value;
                tmp_weight+=items[i].weight;
                tmp_items[i]=true;
            }else{
                break; 
            }
        }
        opt_items=tmp_items;
        opt_value=tmp_value;
        used_items.assign(N,false);
        searchbb(0,0,0);
        return opt_value;
    }
};

signed main(){
    ll N,W;
    cin >> N >> W;
    vector<Item> items(N);
    rep(i,N){
        cin >> items[i].value;
        cin >> items[i].weight;
        items[i].index = i;
    }

    //分枝限定法で探索
    KnapsackBB knapsack(items, W);
    ll opt_value = knapsack.search();
    cout << opt_value << endl;

    return 0;
}

