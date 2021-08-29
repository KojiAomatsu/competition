#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

int main() {
  ll N;
  cin >> N;
  vector<ll> S(N);
  vector<ll> T(N);
  rep(i, 0, N) { cin >> S[i]; }
  rep(i, 0, N) { cin >> T[i]; }
  priority_queue<P, vector<P>, greater<P>> times;
  rep(i, 0, N) { times.push({T[i], i}); }

  vector<bool> vis(N, false);
  vector<ll> ans(N);
  while (!times.empty()) {
    P top = times.top();
    times.pop();
    ll idx = top.second == N ? 0 : top.second;
    if (vis[idx]) {
      continue;
    }
    ans[idx] = top.first;
    vis[idx] = true;
    times.push({top.first + S[idx], idx + 1});
  }
  rep(i, 0, N) { cout << ans[i] << endl; }
}