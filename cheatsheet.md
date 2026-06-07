# C++ vector / queue / 二分探索 チートシート

---

# 1. vector（基本）

## 宣言・初期化
```cpp
#include <vector>
using namespace std;

vector<int> v;
vector<int> v(5);
vector<int> v(5, 10);
vector<int> v = {1,2,3};
```

## 要素操作
```cpp
v.push_back(10);
v.pop_back();

v.insert(v.begin() + 1, 100);
v.erase(v.begin() + 1);

v.clear();
```

## アクセス
```cpp
v[i];
v.at(i);
v.front();
v.back();
```

## サイズ
```cpp
v.size();
v.empty();
```

---

# 2. queue（キュー：FIFO）

## 基本
```cpp
#include <queue>

queue<int> q;
```

## 操作
```cpp
q.push(10);     // 追加
q.pop();        // 先頭削除（戻り値なし）

q.front();      // 先頭取得
q.back();       // 末尾取得

q.size();       // 要素数
q.empty();      // 空判定
```

## 使用例（BFS）
```cpp
queue<int> q;
q.push(start);

while (!q.empty()) {
    int now = q.front();
    q.pop();

    for (int next : graph[now]) {
        q.push(next);
    }
}
```

---

# 3. priority_queue（優先度付きキュー）

## 最大ヒープ（デフォルト）
```cpp
#include <queue>

priority_queue<int> pq;

pq.push(3);
pq.push(1);
pq.push(5);

pq.top(); // 最大値
pq.pop();
```

## 最小ヒープ
```cpp
priority_queue<int, vector<int>, greater<int>> pq;
```

---

# 4. 二分探索（超重要）

## binary_search（存在確認）
```cpp
#include <algorithm>

bool exists = binary_search(v.begin(), v.end(), 10);
```

※ 必ずソート済み！

---

## lower_bound（>= x の最初）
```cpp
auto it = lower_bound(v.begin(), v.end(), 10);

// indexに変換
int idx = it - v.begin();
```

---

## upper_bound（> x の最初）
```cpp
auto it = upper_bound(v.begin(), v.end(), 10);
```

---

## 個数カウント（xの出現回数）
```cpp
int count = upper_bound(v.begin(), v.end(), x)
          - lower_bound(v.begin(), v.end(), x);
```

---

# 5. 自作二分探索（テンプレ）

## 条件を満たす最小値を探す
```cpp
int left = 0, right = n; // [left, right)

while (left < right) {
    int mid = (left + right) / 2;

    if (条件(mid)) {
        right = mid;
    } else {
        left = mid + 1;
    }
}

// left が答え
```

---

## 条件を満たす最大値を探す
```cpp
int left = -1, right = n; // (left, right]

while (right - left > 1) {
    int mid = (left + right) / 2;

    if (条件(mid)) {
        left = mid;
    } else {
        right = mid;
    }
}

// left が答え
```

---

# 6. ソートと組み合わせ

```cpp
sort(v.begin(), v.end());

// 二分探索と併用
binary_search(v.begin(), v.end(), x);
```

---

# 7. 注意ポイント

- binary_search / lower_bound / upper_bound は **ソート必須**
- queueはランダムアクセス不可
- priority_queueは中身を直接変更できない
- 二分探索は境界バグが出やすい（区間に注意）

---

# 8. 競プロ頻出パターン

## 値の圧縮
```cpp
vector<int> comp = v;
sort(comp.begin(), comp.end());
comp.erase(unique(comp.begin(), comp.end()), comp.end());

int idx = lower_bound(comp.begin(), comp.end(), v[i]) - comp.begin();
```

---

## 「x以上で最小」を探す
```cpp
auto it = lower_bound(v.begin(), v.end(), x);
if (it != v.end()) {
    cout << *it << endl;
}
```

---

これで vector + queue + 二分探索はほぼ戦える🔥