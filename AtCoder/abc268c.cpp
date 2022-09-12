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
void yes(){cout<<"Yes\n";}
void no(){cout<<"No\n";}
void error(){
    for(ll i = 0; i < 1000000000000000; i++)
    {
        cout<<"Error\n";
    }
}
ll N;
vl p;
ll solver(){
    // d[i]:距離がiであるような人の数
    vl d(N,0);
    ll ans=0,tmp;
    for(ll i = 0; i < N; i++)
    {
        tmp=(p[i]-i+N)%N;
        ++d[tmp];
    }
    for(ll i = 0; i < N; i++)
    {
        ans=max(ans,d[i]+d[(i-1+N)%N]+d[(i+1)%N]);
    }
    return ans;
}
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin>>N;
    p.resize(N);
    for(ll i = 0; i < N; i++)
    {
        cin>>p[i];
    }
    cout<<solver()<<endl;
}