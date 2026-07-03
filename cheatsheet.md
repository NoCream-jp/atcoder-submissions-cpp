# C++ データ構造チートシート（競プロ用・完全版）

ans[i].erase(unique(all(ans[i])), ans[i].end());

# ===== string（文字列操作） =====

string s = "hello";
string t = "world";

# ■ 基本
s.size();          // 長さ
s.length();        // 同じ
s.empty();         // 空判定

s[i];              // i番目アクセス（char）
s.at(i);           // 範囲チェックあり

s.front();
s.back();


# ■ 連結・追加
s += t;
s = s + t;

s.push_back('a');
s.pop_back();


# ■ 部分文字列
string sub = s.substr(pos, len);   // posからlen文字


# ■ 検索
s.find("ll");     // 見つかれば位置、なければ string::npos
s.rfind("l");     // 後ろから検索

if (s.find("abc") != string::npos) {
    // 含まれる
}


# ■ 置換
s.replace(pos, len, "abc");   // 部分置換


# ■ 挿入・削除
s.insert(pos, "abc");
s.erase(pos, len);


# ■ 比較
if (s == t) {}
if (s < t) {}   // 辞書順比較


# ■ ソート
sort(s.begin(), s.end());   // 文字を並び替え


# ■ 反転
reverse(s.begin(), s.end());


# ■ カウント
count(s.begin(), s.end(), 'a');


# ■ 数値変換
int x = stoi("123");
long long y = stoll("123456789");

string str = to_string(123);


# ■ 1文字ずつ処理
for (char c : s) {}

for (int i = 0; i < s.size(); i++) {
    char c = s[i];
}


# ■ 大文字・小文字変換
#include <cctype>

char c = 'a';
toupper(c);   // 'A'
tolower(c);   // 'a'


# ■ split（疑似）
#include <sstream>

vector<string> split(string s) {
    vector<string> res;
    stringstream ss(s);
    string token;
    while (ss >> token) {
        res.push_back(token);
    }
    return res;
}


# ■ join（疑似）
string join(vector<string>& v, string sep) {
    string res;
    for (int i = 0; i < v.size(); i++) {
        if (i) res += sep;
        res += v[i];
    }
    return res;
}


# ■ 文字列 → 配列的に扱う
vector<char> vc(s.begin(), s.end());


# ■ 文字列の比較（部分）
s.compare(pos, len, t);   // 部分比較


# ■ eraseの注意
s.erase(remove(s.begin(), s.end(), 'a'), s.end());  // 'a'削除


# ■ next_permutation（順列）
sort(s.begin(), s.end());
do {
    // sを使う
} while (next_permutation(s.begin(), s.end()));


# ■ よくあるパターン

// 先頭削除
s.erase(s.begin());

// 末尾削除
s.pop_back();

// 先頭追加（非効率）
s = 'a' + s;


// ■ 注意
- findは見つからないと string::npos
- erase/remove イディオム重要
- 文字列連結は多用すると遅い場合あり
- s[i] は高速、at()は安全

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