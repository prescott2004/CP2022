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
vl A;
ll solver()
{
    vl E, O;
    for (ll i = 0; i < N; i++)
    {
        if (A[i] % 2)
        {
            O.emplace_back(A[i]);
        }
        else
        {
            E.emplace_back(A[i]);
        }
    }
    sort(O.begin(), O.end());
    sort(E.begin(), E.end());
    if (O.size() <= 1 && E.size() <= 1)
    {
        return -1;
    }
    else if (O.size() <= 1)
    {
        return E.back() + E[E.size() - 2];
    }
    else if (E.size() <= 1)
    {
        return O.back() + O[O.size() - 2];
    }
    else
    {
        return max(E.back() + E[E.size() - 2], O.back() + O[O.size() - 2]);
    }
}
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N;
    A.resize(N);
    for (ll i = 0; i < N; i++)
    {
        cin >> A[i];
    }
    cout << solver() << endl;
}