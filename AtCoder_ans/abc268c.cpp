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
    vl d(N,0);
    for(ll i = 0; i < N; i++)
    {
        // 料理p[i]は何回回したら人が喜ぶか
        // p[i]->i
        ++d[(i-p[i]+N)%N];
        ++d[(i+1-p[i]+N)%N];
        ++d[(i-1-p[i]+N)%N];
    }
    ll ans=0;
    for(ll i = 0; i < N; i++)
    {
        ans=max(ans,d[i]);
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