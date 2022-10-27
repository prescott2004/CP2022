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
    sl S;
    for (ll i = 0; i < N; i++)
    {
        S.emplace(A[i]);
    }
    vl B;
    for (auto &e : S)
    {
        B.emplace_back(e);
    }
    vl D(N);
    for (ll i = 0; i < B.size(); i++)
    {
        D[i] = i == 0 ? B[i] : B[i] - B[i - 1];
    }
    for (ll i = 0; i < N - B.size(); i++)
    {
        D.emplace_back(INFTY);
    }
    ll r = N;
    ll p = 0;
    ll ans = 0;
    while (p < r)
    {
        if (D[p] == 1)
        {
            ++p;
            ++ans;
        }

        else
        {
            if (p <= r - 2)
            {
                if (D[p] != INFTY)
                {
                    --D[p];
                }
                ++ans;
                r -= 2;
            }
            else
            {
                break;
            }
        }
    }
    return ans;
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