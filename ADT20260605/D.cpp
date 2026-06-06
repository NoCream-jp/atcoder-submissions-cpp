#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vector<int>>;
using vvll = vector<vector<ll>>;
using vs = vector<string>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using uset = unordered_set<int>;
using umap = unordered_map<int, int>;

const int MOD = 998244353;
const ll INF = 1LL << 60;
const int drct[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()

// --------------------------------------------------------

// --------------------------------------------------------
void answer(bool b) {
    cout << (b ? "Yes" : "No") << endl;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    vi a(n), b(m);
    rep(i, n) cin >> a[i];
    rep(i, m) cin >> b[i];
    vi c;
    c.insert(c.end(), all(a));
    c.insert(c.end(), all(b));

    sort(all(a));
    sort(all(b));
    sort(all(c));

    set<int> st(all(a));
    bool f = false;
    rep(i, n + m - 1) {
        int t1 = c[i];
        int t2 = c[i+1];

        if (st.count(t1) && st.count(t2)) {
            f = true;
            break;
        }
    }

    answer(f);

    return 0;
}