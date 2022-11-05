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
ll N;
vl P;
void solver()
{
    vl ans(P);
    vl s;
    ll first;
    for (ll i = N - 2; i >= 0; i--)
    {
        if (P[i] > P[i + 1])
        {
            for (ll j = i; j < N; j++)
            {
                if (P[j] < P[i])
                {
                    first = P[j];
                }
                s.emplace_back(P[j]);
            }
            ans.resize(i);
            break;
        }
    }
    sort(s.begin(), s.end());
    ans.emplace_back(first);
    for (ll i = s.size() - 1; i > -1; i--)
    {
        if (s[i] != first)
        {
            ans.emplace_back(s[i]);
        }
    }
    for (ll i = 0; i < N; i++)
    {
        cout << ans[i] << ' ';
    }
    cout << endl;
}
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N;
    P.resize(N);
    for (ll i = 0; i < N; i++)
    {
        cin >> P[i];
    }
    solver();
}