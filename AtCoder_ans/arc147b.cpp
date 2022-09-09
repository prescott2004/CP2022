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
vl P;
void solver(){
    bool flg=false;
    vs ans;
    do
    {
        flg=false;
        for(ll i = 0; i < N-2; i++)
        {
            if(P[i]%2!=i%2 && P[i]%2!=P[i+2]%2){
                ans.emplace_back("B "+to_string(i+1));
                swap(P[i],P[i+2]);
                flg=true;
            }
        }
    }while(flg);
    do{
        flg=false;
        for(ll i = 0; i < N-1; i++)
        {
            if(P[i]%2==i%2 && P[i]%2!=P[i+1]%2){
                ans.emplace_back("A "+to_string(i+1));
                swap(P[i],P[i+1]);
                flg=true;
                ++i;
            }
        }
    }while(flg);
    do{
        flg=false;
        for(ll i = 0; i < N-2; i++)
        {
            if(P[i]>P[i+2]){
                ans.emplace_back("B "+to_string(i+1));
                swap(P[i],P[i+2]);
                flg=true;
            }
        }
    }while(flg);
    cout<<ans.size()<<endl;
    for(string& e:ans)
    {
        cout<<e<<endl;
    }
}
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin>>N;
    P.resize(N);
    for(ll i = 0; i < N; i++)
    {
        cin>>P[i];
    }
    solver();
}