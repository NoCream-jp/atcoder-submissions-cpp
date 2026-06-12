/*
https://onlinejudge.u-aizu.ac.jp/challenges/sources/JAG/Prelim/3204?year=2020
*/
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vector<int>>;
using vvll = vector<vector<ll>>;
using vs = vector<string>;
using vc = vector<char>;
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

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  string str;
  while (1) {
    cin >> str;
    if (str == "#") break;
    vc stack;

    ll idx = 0;
    // 右に何個まで見に行けるか(x2
    ll right = 2;
    ll ridx = 0;
    ll ans = 0;
    while (1) {
      if (str[idx] == '(') { 
        right *= 2;
        while (ridx++ < idx + right) {
          
        }
      } else {
        right = 2;
      }
    }
  }

  return 0;
}