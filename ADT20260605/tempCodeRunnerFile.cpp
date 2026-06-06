#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vector<int>>;
using vvll = vector<vector<ll>>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

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

    string s;
    ll a, b;
    cin >> s >> a >> b;

    string ac = s[a - 1];
    string bc = s[b - 1];
    s[a - 1] = bc;
    s[b - 1] = ac;

    cout << s << endl;    

    return 0;
}