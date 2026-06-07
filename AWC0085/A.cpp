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

void printVec(vll& arr) {
  rep(i, arr.size()) {
    cout << arr[i] << " ";
  }
  cout << endl;
}
// --------------------------------------------------------

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  ll n; cin >> n;
  vll s(n * 2); // 二分木みたいにそれぞれlogかけてmaxで埋めていく
  rep(i, n) cin >> s[i];

  printVec(s);
  
  rep(i, n) {
    
  }


  return 0;
}