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
ll N,M;
ll u,v;
ll sum=0;
vl A;
vector<vl> G;
bool solve(ll x,vl cost){
    stack<ll> s;
    for(ll i = 0; i < N; i++)
    {
        if(cost[i]<=x){
            s.emplace(i);
        }
    }
    while(!s.empty()){
        // exclude node p
        ll p=s.top();
        s.pop();
        // add node p's adjacent nodes
        for(ll i = 0; i < G[p].size(); i++)
        {
            ll j=G[p][i];
            if(cost[j]>0){
                cost[j]-=A[p];
                if(cost[j]+A[p]>x&&cost[j]<=x)
                    s.emplace(j);
            }
            if(cost[j]<0){
                error();
            }
        }
        cost[p]=0;
    }
    for(ll i = 0; i < N; i++)
    {
        if(cost[i]){return false;}
    }
    return  true;
}
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin>>N>>M;
    A.resize(N);
    G.resize(N);
    for(ll i = 0; i < N; i++)
    {
        cin>>A[i];
        sum+=A[i];
    }
    vl cost(N,0);
    for(ll i = 0; i < M; i++)
    {
        cin>>u>>v;
        cost[u-1]+=A[v-1];
        cost[v-1]+=A[u-1];
        G[u-1].emplace_back(v-1);
        G[v-1].emplace_back(u-1);
    }
    ll l=0,r=sum,ans,x;
    while(l<=r){
        x=(r+l)/2;
        if(solve(x,cost)){
            ans=x;
            r=x-1;
        }else{
            l=x+1;
        }
    }
    cout<<ans<<endl;

}