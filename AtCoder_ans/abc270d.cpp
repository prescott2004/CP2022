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
int N,K;
vl A;
ll solver(){
    // dp[手番][残りの個数]=そこから始めたときの高橋君の石の個数の最大値
    vector<vl> dp(2,vl(N+1,0));
    for(ll i = 0; i < N; i++)
    {
        dp[1][i+1]=INFTY;
        for(ll j = 0; j < K; j++)
        {
            if(A[j]<=i+1){
            dp[0][i+1]=max(dp[0][i+1],dp[1][i+1-A[j]]+A[j]);
            dp[1][i+1]=min(dp[1][i+1],dp[0][i+1-A[j]]);
            }
        }
    }
    return dp[0][N];
}
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin>>N>>K;
    A.resize(K);
    for(ll i = 0; i < K; i++)
    {
        cin>>A[i];
    }
    // メモ化再帰
    cout<<solver()<<endl;
}