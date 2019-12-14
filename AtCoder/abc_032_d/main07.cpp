// 速いコードを勉強する．
// 参考：https://atcoder.jp/contests/abc032/submissions/8123494


#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//#include <boost/multiprecision/cpp_dec_float.hpp>
using namespace std;

/*
#ifdef LOCAL_DEV
	void debug_impl() { std::cerr << std::endl; }
	template<typename Head, typename... Tail> void debug_impl(Head head, Tail... tail) { std::cerr << " " << head << (sizeof...(tail) ? "," : ""); debug_impl(tail...); }
	#define debug(...) std::cerr << std::boolalpha << "(" << #__VA_ARGS__ << ") ="; debug_impl(__VA_ARGS__); std::cerr << std::noboolalpha;
#else
	#define debug(...)
#endif
#ifdef LOCAL_TEST
	#define BOOST_STACKTRACE_USE_ADDR2LINE
	#define BOOST_STACKTRACE_ADDR2LINE_LOCATION /usr/local/opt/binutils/bin/addr2line
	#define _GNU_SOURCE
	#include <boost/stacktrace.hpp>
	template<typename T> class dvector : public std::vector<T> {
	public:
		dvector() : std::vector<T>() {}
		explicit dvector(size_t n, const T& value = T()) : std::vector<T>(n, value) {}
		dvector(const std::vector<T>& v) : std::vector<T>(v) {}
		dvector(const std::initializer_list<T> il) : std::vector<T>(il) {}
		dvector(const typename std::vector<T>::iterator first, const typename std::vector<T>::iterator last) : std::vector<T>(first, last) {}
		dvector(const std::string::iterator first, const std::string::iterator last) : std::vector<T>(first, last) {}
		T& operator[](size_t n) {
			try { return this->at(n); } catch (const std::exception& e) {
				std::cerr << boost::stacktrace::stacktrace() << std::endl; return this->at(n);
			}
		}
		const T& operator[](size_t n) const {
			try { return this->at(n); } catch (const std::exception& e) {
				std::cerr << boost::stacktrace::stacktrace() << std::endl; return this->at(n);
			}
		}
	};
	class dbool {
	private:
		bool boolvalue;
	public:
		dbool() : boolvalue(false) {}
		dbool(bool b) : boolvalue(b) {}
		dbool(const dbool &b) : boolvalue(b.boolvalue) {}
		operator bool&() { return boolvalue; }
		operator const bool&() const { return boolvalue; }
	};
	template<typename T1, typename T2> std::ostream& operator<<(std::ostream& s, const std::pair<T1, T2>& p) { return s << "(" << p.first << ", " << p.second << ")"; }
	template<typename T> std::ostream& operator<<(std::ostream& s, const dvector<T>& v) {
		for (int i = 0, len = v.size(); i < len; ++i){ s << v[i]; if (i < len - 1) s << "\t"; } return s; }
	template<typename T> std::ostream& operator<<(std::ostream& s, const dvector< dvector<T> >& vv) {
		for (int i = 0, len = vv.size(); i < len; ++i){ s << vv[i] << std::endl; } return s; }
	template<typename T1, typename T2> std::ostream& operator<<(std::ostream& s, const std::map<T1, T2>& m) {
		s << "{" << std::endl; for (auto itr = m.begin(); itr != m.end(); ++itr){ s << "\t" << (*itr).first << " : " << (*itr).second << std::endl; } s << "}" << std::endl; return s; }
	template<typename T> std::ostream& operator<<(std::ostream& s, const std::set<T>& se) {
		s << "{ "; for (auto itr = se.begin(); itr != se.end(); ++itr){ s << (*itr) << "\t"; } s << "}" << std::endl; return s; }
	template<typename T> std::ostream& operator<<(std::ostream& s, const std::multiset<T>& se) {
		s << "{ "; for (auto itr = se.begin(); itr != se.end(); ++itr){ s << (*itr) << "\t"; } s << "}" << std::endl; return s; }
	#define vector dvector
	#define bool dbool
#endif
//*/
//#define int long long
using ll = long long;
//using bll = boost::multiprecision::cpp_int;
//using bdouble = boost::multiprecision::cpp_dec_float_100;
//constexpr int INF = 1e9;//INT_MAX=(1<<31)-1=2147483647
constexpr ll INF = (ll)1e18;//(1LL<<63)-1=9223372036854775807
constexpr ll MOD = (ll)1e9 + 7;
constexpr double EPS = 1e-9;
constexpr int dx[4]={1,0,-1,0};
constexpr int dy[4]={0,1,0,-1};
#define p(var) std::cout<<var<<std::endl
#define PI (acos(-1))
#define rep(i, n)   for(ll i=0, i##_length=(n); i< i##_length; ++i)
#define repeq(i, n) for(ll i=1, i##_length=(n); i<=i##_length; ++i)
#define all(v) (v).begin(), (v).end()
#define uniq(v) (v).erase(unique((v).begin(), (v).end()), (v).end());
template<typename T> inline void pv(vector<T> &v) { for(ll i=0, N=v.size(); i<N; i++) std::cout << v[i] << " \n"[i==N-1]; }
template<typename T> inline T gcd(T a, T b) { return b ? gcd(b,a%b) : a; }
template<typename T> inline T lcm(T a, T b) { return a / gcd(a,  b) * b; }
template<typename T1, typename T2> inline T1 power(T1 x, T2 n){ return n ? power(x*x%MOD,n/2)*(n%2?x:1)%MOD : 1; }
template<typename T1, typename T2> inline bool chmax(T1 &a, T2 b) { return a < b && (a = b, true); }
template<typename T1, typename T2> inline bool chmin(T1 &a, T2 b) { return a > b && (a = b, true); }

/*-----8<-----8<-----*/

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

