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
vl A;
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin>>N;
    A.resize(N);
    for(ll i = 0; i < N; i++)
    {
        cin>>A[i];
    }
    sort(A.begin(),A.end());
    deque<ll> D;
    for(ll i = 0; i < N; i++)
    {
        D.emplace_back(A[i]);
    }
    ll cnt=0,l,r;
    while(D.size()>1){
        l=D.front();
        r=D.back();
        D.pop_back();
        if(r%l){
            D.push_front(r%l);
        }
        ++cnt;
    }
    cout<<cnt<<endl;
}