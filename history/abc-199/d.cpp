#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

int main() {
  ll N, M;
  cin >> N >> M;
  map<ll, vector<ll>> edges;
  rep(i, 0, M) {
    ll ai, bi;
    cin >> ai >> bi;
    edges[ai].push_back(bi);
    edges[bi].push_back(ai);
  }

  bool vis[N + 1] = {};
  ll par[N + 1] = {};
  vis[0] = true;
  stack<ll> st;
  vector<ll> con;
  vector<vector<ll>> cons;
  function<void(ll)> dfs = [&](ll num) {
    vis[num] = true;
    con.push_back(num);
    auto es = edges[num];
    for (auto e : es) {
      if (!vis[e]) {
        st.push(e);
        vis[e] = true;
        par[e] = num;
      }
    }
    while (!st.empty()) {
      auto top = st.top();
      st.pop();
      dfs(top);
    }
  };
  rep(i, 1, N + 1) {
    if (!vis[i]) {
      con = {};
      dfs(i);
      cons.push_back(con);
    }
  }

  ll ans = 1;
  for (auto co : cons) {
    ll comb = 1;
    vector<ll> col(co.size(), 0);
    col[0] = 1; // 1 for red, 2 for green, 3 for blue;
    rep(bit, 0, 1 << (co.size() - 1)) {
      for (int i = 0; i < co.size() - 1; ++i) {
        ll flag = bit & (1 << (co.size() - 2 - i));
        if (col[par[co[i + 1]]] == 1) {
          // 本当は既存の色を見て場合分けしたり
          col[i + 1] = flag ? 3 : 2;
        } else if (col[par[co[i + 1]]] == 2) {
          col[i + 1] = flag ? 3 : 1;
        } else if (col[par[co[i + 1]]] == 3) {
          col[i + 1] = flag ? 2 : 1;
        }
      }
    }
    comb *= 3;

    ans += comb;
  }
}
