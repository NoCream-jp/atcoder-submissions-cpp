# C++ データ構造チートシート（競プロ用・完全版）

# ===== vector =====
vector<int> v;

v.push_back(x);
v.pop_back();

v.insert(v.begin()+i, x);
v.erase(v.begin()+i);

v[i];
v.at(i);
v.front();
v.back();

v.size();
v.empty();

v.clear();
v.resize(n);
v.assign(n, x);

v.begin();
v.end();


# ===== queue（FIFO） =====
queue<int> q;

q.push(x);
q.pop();

q.front();
q.back();

q.size();
q.empty();


# ===== deque（両端キュー） =====
deque<int> dq;

dq.push_back(x);
dq.push_front(x);

dq.pop_back();
dq.pop_front();

dq.front();
dq.back();

dq[i];

dq.size();
dq.empty();


# ===== stack（LIFO） =====
stack<int> st;

st.push(x);
st.pop();

st.top();

st.size();
st.empty();


# ===== priority_queue（ヒープ） =====
// 最大
priority_queue<int> pq;

// 最小
priority_queue<int, vector<int>, greater<int>> pq;

pq.push(x);
pq.pop();
pq.top();

pq.size();
pq.empty();


# ===== unordered_map（ハッシュマップ） =====
unordered_map<string,int> mp;

mp[key] = value;
mp[key]++;

mp[key];
mp.at(key);

mp.count(key);

mp.erase(key);

mp.size();
mp.empty();

for (auto [k, v] : mp) {
    cout << k << ": " << v << ", ";
  }cout << endl;

for (auto [k, v] : mp) {}


# ===== unordered_set（ハッシュ集合） =====
unordered_set<int> st;

st.insert(x);
st.erase(x);

st.count(x);

st.size();
st.empty();


# ===== map（順序付き） =====
map<int,int> mp;

mp[key] = value;

mp.count(key);
mp.find(key);

mp.erase(key);

mp.begin();
mp.end();

mp.lower_bound(x);
mp.upper_bound(x);


# ===== set（順序付き集合） =====
set<int> st;

st.insert(x);
st.erase(x);

st.count(x);

st.lower_bound(x);
st.upper_bound(x);

st.begin();
st.end();


# ===== アルゴリズム（二分探索など） =====
sort(v.begin(), v.end());

binary_search(v.begin(), v.end(), x);

lower_bound(v.begin(), v.end(), x);
upper_bound(v.begin(), v.end(), x);

upper_bound(v.begin(), v.end(), x)
- lower_bound(v.begin(), v.end(), x);


# ===== よく使う補助 =====
pair<int,int> p;

p.first;
p.second;

using ll = long long;
using pii = pair<int,int>;


# ===== 重要注意 =====
- 二分探索系はソート必須
- queue / stack はランダムアクセス不可
- priority_queue は要素更新不可
- unordered_map は最悪計算量に注意
- vector<bool> は遅い場合あり


# ===== 競プロ頻出 =====
// 座標圧縮
vector<int> comp = v;
sort(comp.begin(), comp.end());
comp.erase(unique(comp.begin(), comp.end()), comp.end());

int idx = lower_bound(comp.begin(), comp.end(), x) - comp.begin();


# ===== 使い分け =====
vector → 基本
queue → BFS
deque → 0-1 BFS
stack → DFS
priority_queue → 最短経路
unordered_map/set → 高速探索
map/set → 順序付き探索