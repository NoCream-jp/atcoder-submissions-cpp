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

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  /*
  常に最小のスライムを触れるようにheapq
  hashmapに数を保存していく
  最終的にhashmapを走査して値を持つ物の数を数えるだけ
  */

  ll n; cin >> n;
  // 最小
  priority_queue<ll, vector<ll>, greater<ll>> pq;
  umap mp;
  rep(i, n) {
    ll s, c; cin >> s >> c;
    mp[s] += c;
  }

  for (auto [k, v] : mp) {
    pq.push(k);
  }

  while (pq.size()) {
    ll value, num;
    value = pq.top();
    pq.pop();
    num = mp[value];
    ll next = value * 2;
    ll next_num = num / 2;

    // 小さい側が余る場合
    mp[value] = num % 2;
    // まだ2個以上ある場合
    if (next_num) {
      mp[next] += next_num;
      pq.push(next);
    }
  }

  ll ans = 0;
  for (auto [k, v] : mp) {
    if (0 < v) {
      ans++; // 1個確定
    }
  }

  cout << ans << endl;

  return 0;
}