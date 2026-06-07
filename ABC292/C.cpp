/*
Here is my coding space
    Caffeineholic
                    ) ) )
                    ( ( (
                    ████╗
                    ████╝ < before i get cold
*/
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
using qii = queue<pair<int, int>>;


const int MOD = 998244353;
const ll INF = 1LL << 60;
const int drct[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()

// --------------------------------------------------------
void yesno(bool b) {
    cout << (b ? "Yes" : "No") << endl;
}
// --------------------------------------------------------

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  ll n; cin >> n;
  ll ans = 0;

  for(ll x = 1; x < n; x++) {

    ll y = n-x;
    ll a = 0, c = 0;

    for(ll i = 1;  i * i <= x; i++) {
      if(x % i == 0) {
        a++;
        if (i * i != x) {
          a++;
        }
      }
    }

    for(ll i = 1; i * i <= y; i++) {
      if(y % i == 0) {
        c++;
        if (i * i != y) {
          c++;
        }
      }
    }

    ans += a * c;
  }

  cout << ans << endl;

  return 0;
}