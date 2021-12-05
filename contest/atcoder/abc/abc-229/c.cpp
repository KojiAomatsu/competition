#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

int main() {
  ll N, W;
  cin >> N >> W;
  vector<P> chs(N);
  rep(i, 0, N) {
    ll ai, bi;
    cin >> ai >> bi;
    chs[i] = {ai, bi};
  }
  sort(chs.begin(), chs.end());
  reverse(chs.begin(), chs.end());

  ll cnt = 0;
  ll del = 0;
  for (auto ch : chs) {
    if (cnt + ch.second <= W) {
      del += ch.first * ch.second;
      cnt += ch.second;
    } else {
      del += ch.first * (W - cnt);
      break;
    }
  }
  cout << del << endl;
  return 0;
}