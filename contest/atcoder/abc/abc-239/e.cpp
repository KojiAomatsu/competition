#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

int main() {
  ll N, Q;
  cin >> N >> Q;
  vector<ll> X(N);
  rep(i, 0, N) { cin >> X[i]; }
  vector<vector<ll>> edges(N);
  rep(i, 0, N - 1) {
    ll Ai, Bi;
    cin >> Ai >> Bi;
    Ai--;
    Bi--;
    edges[Ai].push_back(Bi);
    edges[Bi].push_back(Ai);
  }
  vector<priority_queue<ll, vector<ll>, greater<ll>>> mxs(N);

  function<void(ll, ll)> dfs = [&](ll cur, ll par) {
    priority_queue<ll, vector<ll>, greater<ll>> pq;
    pq.push(X[cur]);
    for (auto e : edges[cur]) {
      if (e == par) continue;
      dfs(e, cur);
      auto cppq = mxs[e];
      while (!cppq.empty()) {
        auto t = cppq.top();
        cppq.pop();
        pq.push(t);
      }
    }
    while (pq.size() > 20) {
      pq.pop();
    }
    mxs[cur] = pq;
    return;
  };

  dfs(0, -1);
  rep(i, 0, Q) {
    ll Vi, Ki;
    cin >> Vi >> Ki;
    Vi--;
    auto cppq = mxs[Vi];
    while (cppq.size() != Ki) {
      cppq.pop();
    }
    cout << cppq.top() << endl;
  }
}