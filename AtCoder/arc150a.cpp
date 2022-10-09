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
ll T, N, K;
string S;

bool solver()
{
    ll free_l = 0, free_r = 0;
    ll l = -1, r = -1;
    for (ll i = 0; i < N; i++)
    {
        if (S[i] == '1')
        {
            if (l == -1)
            {
                l = i;
            }
            r = i + 1;
        }
    }
    // 1が1個も含まれなかった場合
    if (l == -1)
    {
        ll cnt_all = 0, cnt_k = 0;
        for (ll i = 0; i < N; i++)
        {
            if (S[i] == '?')
            {
                l = i;
                r = i + 1;
                ll j;
                for (j = i + 1; j < N; j++)
                {
                    if (S[j] == '?')
                    {
                        r = j + 1;
                    }
                    else
                    {
                        break;
                    }
                }
                // cout << l << ' ' << r << endl;
                i = j;
                if (r - l >= K)
                {
                    ++cnt_all;
                }
                if (r - l == K)
                {
                    ++cnt_k;
                }
            }
        }
        if (cnt_all == 1 && cnt_k == 1)
        {
            return true;
        }
        return false;
    }
    // [l,r)の間隔はK以内
    if (r - l > K)
    {
        return false;
    }
    // [l,r)に0が存在してはいけない
    for (ll i = l; i < r; i++)
    {
        if (S[i] == '0')
        {
            return false;
        }
    }
    for (ll i = l - 1; i > -1; i--)
    {
        if (S[i] == '?')
        {
            ++free_l;
        }
        else
        {
            break;
        }
    }
    for (ll i = r; i < N; i++)
    {
        if (S[i] == '?')
        {
            ++free_r;
        }
        else
        {
            break;
        }
    }
    ll remnant = K - (r - l);
    if (remnant > free_l + free_r)
    {
        return false;
    }
    else if (!free_l || !free_r || !remnant)
    {
        return true;
    }
    else if (remnant == free_l + free_r)
    {
        return true;
    }
    else
    {
        return false;
    }
}
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> T;
    vs ans;
    for (ll i = 0; i < T; i++)
    {
        S.resize(0);
        cin >> N >> K >> S;
        if (solver())
        {
            ans.emplace_back("Yes\n");
        }
        else
        {
            ans.emplace_back("No\n");
        }
    }
    for (auto e : ans)
    {
        cout << e;
    }
}