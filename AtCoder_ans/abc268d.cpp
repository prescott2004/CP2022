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
vs S;
ss T;

string solver()
{
    ll max_u = 16 - (N - 1);
    for (ll i = 0; i < N; i++)
    {
        max_u -= S[i].size();
    }
    vb used(N, false);
    // 答えがあればtrue,なければfalse
    auto dfs = [&](auto f, int i, string s, int u) -> string
    {
        // cout << i << ":" << s << endl;
        // i: 何単語目か
        // 全単語入れ終わった場合
        if (i == N)
        {
            s.pop_back();
            if (T.count(s) || s.size() < 3)
                return "-1";
            else
                return s;
        }
        //
        for (ll j = 0; j < N; j++)
        {
            if (used[j])
                continue;
            used[j] = true;
            string result = f(f, i + 1, s + S[j] + '_', u);
            if (result != "-1")
                return result;
            used[j] = false;
        }
        // アンダーラインを入れられる場合
        if (u && i)
        {
            string result = f(f, i, s + '_', u - 1);
            if (result != "-1")
                return result;
        }
        return "-1";
    };
    return dfs(dfs, 0, "", max_u);
}
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N >> M;
    S.resize(N);
    for (ll i = 0; i < N; i++)
    {
        cin >> S[i];
    }
    string t;
    for (ll i = 0; i < M; i++)
    {
        cin >> t;
        T.emplace(t);
    }
    cout << solver() << endl;
}