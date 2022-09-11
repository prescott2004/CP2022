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
vector<vl> DP(100001,vl(5,0)),V(100001,vl(5,0));
ll solver(){
    // DP[i][j]: i秒後に座標jにいる場合の大きさの合計の最大値
    for(ll i = 0; i < 100000; i++)
    {
        for(ll j = 0; j <=min(4ll,i+1); j++)
        {
            if(i>=j){
                DP[i+1][j]=DP[i][j];
            }
            if(j!=4&&i>=j+1){
                DP[i+1][j]=max(DP[i+1][j],DP[i][j+1]);
            }
            if(j!=0){
                DP[i+1][j]=max(DP[i+1][j],DP[i][j-1]);
            }
            DP[i+1][j]+=V[i+1][j];
        }
    }
    ll ans=0;
    for(ll i = 0; i < 5; i++)
    {
        ans=max(ans,DP[100000][i]);
    }
    return ans;
}
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin>>N;
    ll t,x,a;
    for(ll i = 0; i < N; i++)
    {
        cin>>t>>x>>a;
        V[t][x]=a;
    }
    cout<<solver()<<endl;
}