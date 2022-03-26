#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

map<ll, vector<ll>> edges;
ll L[222000];
ll R[222000];
ll cur;

P dfs(int i, int par) {
  if (edges[i].size() == 1 && par != -1) {
    cur++;
    L[i] = R[i] = cur;
    return make_pair(cur, cur);
  }
  ll l = 1E9;
  ll r = 0;
  for (auto ed : edges[i]) {
    if (ed == par) continue;
    auto [li, ri] = dfs(ed, i);
    l = min(l, li);
    r = max(r, ri);
  }
  L[i] = l;
  R[i] = r;
  return make_pair(l, r);
}

int main() {
  ll N;
  cin >> N;
  rep(i, 0, N - 1) {
    ll ui, vi;
    cin >> ui >> vi;
    ui--;
    vi--;
    edges[ui].push_back(vi);
    edges[vi].push_back(ui);
  }
  dfs(0, -1);
  for (int i = 0; i < N; i++) {
    cout << L[i] << " " << R[i] << endl;
  }
}