#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

vector<ll> edges[110000];
ll leng[110000];
bool vends[110000];
ll mx = 0;

ll dfs(ll v) {
  vector<ll> es = edges[v];
  ll le = 0;
  for (auto e : es) {
    if (vends[e]) {
      le = max(le, leng[e] + 1);
      continue;
    }
    ll chi = dfs(e) + 1;
    le = max(le, chi);
  }
  vends[v] = true;
  leng[v] = le;
  return le;
}

int main() {
  ll N, M;
  cin >> N >> M;
  rep(i, 0, M) {
    ll xi, yi;
    cin >> xi >> yi;
    xi--;
    yi--;
    edges[xi].push_back(yi);
  }

  rep(i, 0, N) {
    if (vends[i]) {
      continue;
    }
    mx = max(mx, dfs(i));
  }

  cout << mx << endl;
}