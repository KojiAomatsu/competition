#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

#define FOR(i, a, n) for (ll i = (ll)a; i < (ll)n; ++i)
#define REP(i, n) FOR(i, 0, n)

// トポロジカルソート実装例

//グラフの隣接リスト
vector<int> g[200010];
//頂点の入次数を管理
int h[200010];

int main() {
  //頂点数v、辺の数e
  int v, e;
  cin >> v >> e;
  REP(i, e) {
    int s, t;
    cin >> s >> t;
    s--, t--;
    //頂点sから頂点tへの有向辺
    g[s].push_back(t);
    h[t]++;
  }

  //入次数が0の頂点の集合
  priority_queue<int, vector<int>, greater<ll>> st;

  //入次数が0の頂点であればstに追加
  REP(i, v) if (h[i] == 0) st.push(i);

  //ソートされた後のグラフ
  vector<int> ans;
  // stがなくなるまでループ
  while (st.size()) {
    // stの集合のから一つ取り出す
    int i = st.top();
    st.pop();
    ans.push_back(i);
    for (auto &j : g[i]) {
      //隣接する頂点の入次数をマイナス1
      h[j]--;
      //これによって入次数が0になればstに追加
      if (h[j] == 0) st.push(j);
    }
  }

  if (ans.size() != v) {
    cout << -1 << endl;
    return 0;
  }

  // ansを順に出力
  for (int i : ans)
    cout << i + 1 << " ";
  cout << endl;

  return 0;
}
