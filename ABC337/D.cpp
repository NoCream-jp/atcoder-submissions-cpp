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

struct PrefixSum2D {
  int H, W;
  vector<vector<ll>> S;
  PrefixSum2D(const vector<vector<ll>>& grid) {
      H = grid.size();
      W = (H > 0) ? grid[0].size() : 0;
      S.assign(H + 1, vector<ll>(W + 1, 0));
      for (int i = 0; i < H; i++) {
          for (int j = 0; j < W; j++) {
              S[i + 1][j + 1] = grid[i][j] + S[i][j + 1] + S[i + 1][j] - S[i][j];
          }
      }
  }
  // [r1, r2], [c1, c2] の閉区間の和を返す
  ll query(int r1, int c1, int r2, int c2) {
      if (r1 > r2 || c1 > c2) return 0;
      r1 = max(0, r1); c1 = max(0, c1);
      r2 = min(H - 1, r2); c2 = min(W - 1, c2);
      return S[r2 + 1][c2 + 1] - S[r1][c2 + 1] - S[r2 + 1][c1] + S[r1][c1];
  }
};
// --------------------------------------------------------

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  ll h, w, k; cin >> h >> w >> k;
  vs grid(h);
  rep(i, h) cin >> grid[i];

  PrefixSum2D ps(grid);
  
  
  

  return 0;
}