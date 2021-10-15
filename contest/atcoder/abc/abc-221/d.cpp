#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

int main() {
  ll N;
  cin >> N;
  map<ll, ll> maps;
  rep(i, 0, N) {
    ll ai, bi;
    cin >> ai >> bi;
    maps[ai] += 1;
    maps[ai + bi] -= 1;
  }
  vector<ll> res(N + 1);
  ll curday = 0;
  ll cur = 0;
  for (auto m : maps) {
    ll days = m.first - curday;
    curday = m.first;
    res[cur] += days;
    cur += m.second;
  }

  rep(i, 1, res.size()) { cout << res[i] << " "; }
  cout << endl;
  return 0;
}
