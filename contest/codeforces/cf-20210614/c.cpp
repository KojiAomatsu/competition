#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

ll modPow(long long a, long long n, long long p) {
  if (n == 0)
    return 1; // 0乗にも対応する場合
  if (n == 1)
    return a % p;
  if (n % 2 == 1)
    return (a * modPow(a, n - 1, p)) % p;
  long long t = modPow(a, n / 2, p);
  return (t * t) % p;
}

ll solve(ll num, vector<ll> li, vector<ll> li2) {
  map<ll, vector<ll>> edges;
  rep(i, 0, num) {
    edges[li[i]].push_back(li2[i]);
    edges[li2[i]].push_back(li[i]);
  }

  bool vis[num + 1] = {};
  ll par[num + 1] = {};
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
  rep(i, 1, num + 1) {
    if (!vis[i]) {
      con = {};
      dfs(i);
      cons.push_back(con);
    }
  }

  ll count = cons.size();
  ll ans = modPow(2, count, 1E9 + 7);

  return ans;
}

int main() {
  ll N;
  cin >> N;
  rep(i, 0, N) {
    ll le;
    cin >> le;
    vector<ll> li(le);
    rep(j, 0, le) { cin >> li[j]; }
    vector<ll> li2(le);
    rep(j, 0, le) { cin >> li2[j]; }
    cout << solve(le, li, li2) << endl;
  }
}
