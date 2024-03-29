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
vector<vl> B;
void solver()
{
    B[0][0] = 0;
    queue<pll> Q;
    Q.emplace(0, 0);
    ll i, j, k, l1, l2;
    while (!Q.empty())
    {
        auto [i, j] = Q.front();
        Q.pop();
        for (k = 0; k < N; k++)
        {
            // (l-j)*(l-j)=M-(k-i)*(k-i)
            ll r = M - (k - i) * (k - i);
            if (r >= 0 && (ll)sqrt(r) * (ll)sqrt(r) == r)
            {
                auto check = [&](ll l) -> void
                {
                    if (l >= 0 && l < N && B[k][l] == -1)
                    {
                        B[k][l] = B[i][j] + 1;
                        Q.emplace(k, l);
                    }
                };
                l1 = j + (ll)sqrt(r);
                l2 = j - (ll)sqrt(r);
                check(l1);
                check(l2);
            }
        }
    }
    for (ll i = 0; i < N; i++)
    {
        for (ll j = 0; j < N; j++)
        {
            cout << B[i][j] << ' ';
        }
        cout << endl;
    }
}
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N >> M;
    B.resize(N, vl(N, -1));
    solver();
}
