#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

// DFSの実装例 深さ優先探索
bool vis[21];
ll par[21];
map<ll, vector<ll>> edges;
stack<ll> st;
vector<ll> con;
vector<vector<ll>> cons;
void dfs(ll num) {
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

int main() {
  ll N, M;
  cin >> N >> M;
  rep(i, 0, M) {
    ll ai, bi;
    cin >> ai >> bi;
    edges[ai].push_back(bi);
    edges[bi].push_back(ai);
  }

  vis[0] = true;
  rep(i, 1, N + 1) {
    if (!vis[i]) {
      con = {};
      dfs(i);
      cons.push_back(con);
    }
  }

  ll ans = 1;
  for (auto co : cons) {
    map<ll, ll> col;
    ll comb = 0;
    col[co[0]] = 1; // 1 for red, 2 for green, 3 for blue;
    rep(bit, 0, 1 << (co.size() - 1)) {
      for (ll i = 1; i < (ll)co.size(); ++i) {
        ll flag = bit & (1 << (co.size() - 1 - i));
        if (col[par[co[i]]] == 1) {
          col[co[i]] = flag ? 3 : 2;
        } else if (col[par[co[i]]] == 2) {
          col[co[i]] = flag ? 3 : 1;
        } else if (col[par[co[i]]] == 3) {
          col[co[i]] = flag ? 2 : 1;
        }
      }
      bool abl = true;
      for (ll i = 0; i < (ll)co.size(); ++i) {
        for (auto edge : edges[co[i]]) {
          if (col[edge] == col[co[i]]) {
            abl = false;
            break;
          }
          if (abl == false) break;
        }
      }
      if (abl) {
        comb += 1;
      }
    }
    comb *= 3;

    ans *= comb;
  }
  cout << ans << endl;
}
