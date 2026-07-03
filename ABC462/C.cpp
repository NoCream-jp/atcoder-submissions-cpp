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
using vi = vector<ll>;
using vll = vector<ll>;
using vvi = vector<vector<ll>>;
using vvll = vector<vector<ll>>;
using vs = vector<string>;
using pii = pair<ll, ll>;
using pll = pair<ll, ll>;
using uset = unordered_set<ll>;
using umap = unordered_map<ll, ll>;


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

template <typename T>
void printVec(const T& arr) {
  for (const auto& e : arr) {
      cout << e << " ";
  }
  cout << "\n";
}

template <typename T>
void printGrid(const vector<vector<T>>& arr) {
  for (const auto& e : arr) {
      printVec(e);
  }
}
// --------------------------------------------------------

/*
xj < xi かつ yj < yi　なjが存在しないようなiの個数を数える
xを昇順に見ていって、一番小さいyならセーフ

*/

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  ll n; cin >> n;
  vvll p(n);
  rep(i, n) {
    ll x, y; cin >> x >> y;
    p[i] = {x, y};
  }
  
  // xでソート
  sort(all(p));
  
  ll ans = 0;
  // y
  ll mn = INF;
  rep(i, n) {
    ll x = p[i][0], y = p[i][1];
    if (y < mn) {
      ans++;
      mn = y;
    }
  }

  cout << ans << endl;

  return 0;
}