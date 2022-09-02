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
string S;
string A[] = {"dream", "dreamer", "erase", "eraser", "dreamerase", "dreameraser"};
ll check(ll p)
{
    for (ll i = 5; i >= 0; i--)
    {
        if (p + A[i].size() <= S.size() && S.substr(p, A[i].size()) == A[i])
        {
            return A[i].size();
        }
    }
    return 0;
}
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> S;
    ll p = 0;
    ll tmp;
    bool ans = true;
    while (p < S.size())
    {
        if (S[p] == 'd' || S[p] == 'e')
        {
            tmp = check(p);
            p += tmp;
            if (tmp == 0)
            {
                ans = false;
            }
        }
        else
        {
            ans = false;
        }
        if (!ans)
        {
            break;
        }
    }
    if (ans)
    {
        cout << "YES\n";
    }
    else
    {
        cout << "NO\n";
    }
}