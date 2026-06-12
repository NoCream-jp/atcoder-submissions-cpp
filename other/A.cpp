/*
https://onlinejudge.u-aizu.ac.jp/problems/2946
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
 * 直進するときは偶数の場合は1/1で進める。
 * 奇数の場合は最後だけ3/4で進む。それまでは1/1。
 * 
 * 最後の斜め１マスのみ１歩でできる。
 */

 
int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  ll x, y;
  while (cin >> x >> y) {
    ll a = max(abs(x), abs(y));
    ll b = min(abs(x), abs(y));
    
    ll ans;
    if (b == 0) {
      if (a == 0) {
        ans = 0;
      } else if (a == 1) {
        ans = 1;
      } else {
        ans = a + a % 2;
      }
    } else { 
      if (a % 2 == 1 && b % 2 == 1) {
        ans = a + b - 1;
    } else {
        ans = a + b;
      }
    }
    cout << ans << endl;
  }
  return 0;
}