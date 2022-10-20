#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vl = vector<ll>;
using vd = vector<double>;
using vs = vector<string>;
using vb = vector<bool>;
using mll = map<ll, ll>;
using mld = map<ll, double>;
using mls = map<ll, string>;
using mlb = map<ll, bool>;
using sl = set<ll>;
using sd = set<double>;
using ss = set<string>;
using pll = pair<ll, ll>;
using pls = pair<ll, string>;
using pld = pair<ll, double>;
using plb = pair<ll, bool>;
template <class T>
using pque = priority_queue<T>;
const ll INFTY = 1L << 62L;
void yes() { cout << "Yes\n"; }
void no() { cout << "No\n"; }
void error()
{
    for (ll i = 0; i < 1000000000000000; i++)
    {
        cout << "Error\n";
    }
}

ll N, M;
ll k, x;
vector<sl> VS;
bool solver()
{
    bool flg;
    for (ll i = 0; i < N; i++)
    {
        for (ll j = i + 1; j < N; j++)
        {
            flg = false;
            for (ll k = 0; k < M; k++)
            {
                if (VS[k].count(i) && VS[k].count(j))
                {
                    flg = true;
                    break;
                }
            }
            if (!flg)
            {
                return false;
            }
        }
    }
    return true;
}
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N >> M;
    VS.resize(M);
    for (ll i = 0; i < M; i++)
    {
        cin >> k;
        for (ll j = 0; j < k; j++)
        {
            cin >> x;
            VS[i].emplace(x - 1);
        }
    }
    if (solver())
    {
        yes();
    }
    else
    {
        no();
    }
}