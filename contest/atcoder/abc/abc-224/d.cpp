#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

int main() {
  ll M;
  cin >> M;
  vector<vector<ll>> uv(10);
  rep(i, 0, M) {
    ll ui, vi;
    cin >> ui >> vi;
    uv[ui].push_back(vi);
    uv[vi].push_back(ui);
  }
  vector<ll> st;
  rep(i, 0, 8) {
    ll pi;
    cin >> pi;
    st.push_back(pi);
  }

  vector<ll> ansb(9, 0);
  rep(i, 0, st.size()) { ansb[st[i] - 1] = st[i]; }

  st.push_back(0); // 0 means empty
  ll times = 0;
  ll memoc = 1;
  if (st == ansb) {
    cout << 0 << endl;
    return 0;
  }
  set<vector<ll>> bs;
  bs.insert(st);

  queue<tuple<ll, vector<ll>, ll>> q;
  q.push({0, st, 9});

  while (q.size() != 0) {
    auto banmen = q.front();
    q.pop();
    ll times = get<0>(banmen);
    vector<ll> board = get<1>(banmen);
    ll pos0 = get<2>(banmen);
    for (auto ed : uv[pos0]) {
      vector<ll> nb = board;
      swap(nb[ed - 1], nb[pos0 - 1]);
      if (nb == ansb) {
        cout << times + 1 << endl;
        return 0;
      }
      if (bs.find(nb) == bs.end()) {
        q.push({times + 1, nb, ed});
        bs.insert(nb);
      }
    }
  }
  cout << -1 << endl;
  return 0;
}