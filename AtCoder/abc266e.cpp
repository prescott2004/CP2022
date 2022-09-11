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
vd DP(101,0);
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin>>N;
    DP[1]=3.5;
    double tmp;
    for(ll i = 2; i < N+1; i++)
    {
        tmp=0;
        for(ll j = 1; j <= 6; j++)
        {
            if(j<DP[i-1]){
                tmp+=DP[i-1];
            }else{
                tmp+=j;
            }
        }
        DP[i]=tmp/6;
    }
    cout<<setprecision(7);
    cout<<DP[N]<<endl;
}