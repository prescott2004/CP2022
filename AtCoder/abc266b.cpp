#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vl = vector<ll>;
using vd = vector<double>;
using vs = vector<string>;
using vb = vector<bool>;
using mll = map<ll,ll>;
using mld = map<ll,double>;
using mls = map<ll,string>;
using mlb = map<ll,bool>;
using sl = set<ll>;
using sd = set<double>;
using ss = set<string>;
using pll = pair<ll,ll>;
using pls = pair<ll,string>;
using pld = pair<ll,double>;
using plb = pair<ll,bool>;
template <class T>
using pque = priority_queue<T>;
const ll INFTY = 1L << 62L;
void error(){
    for(ll i = 0; i < 1000000000000000; i++)
    {
        cout<<"Error\n";
    }
}
ll N;
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin>>N;
    ll ans=N%998244353;
    if(ans<0){
        ans+=998244353;
    }
    cout<<ans<<endl;
}