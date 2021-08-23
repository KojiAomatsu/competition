#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

int main() {
  ll N, M;
  cin >> N >> M;
  vector<ll> S(N);
  vector<ll> T(M);
  set<ll> sset;
  set<ll> tset;
  rep(i, 0, N) {
    cin >> S[i];
    sset.insert(S[i]);
  }
  rep(i, 0, M) {
    cin >> T[i];
    tset.insert(T[i]);
  }
  if ((tset.size() == 2 && sset.size() != 2) || (tset.size() == 1 && sset.size() == 1 && sset != tset)) {
    cout << -1 << endl;
    return 0;
  }

  if (sset.size() == 1) {
    cout << M << endl;
    return 0;
  }

  ll zer = S[0];
  ll posnum = 0;
  ll minum = 0;
  rep(i, 0, N) {
    if (zer != S[i]) {
      posnum = i;
      break;
    }
  }
  rep(i, 1, N) {
    if (zer != S[N - i]) {
      minum = i;
      break;
    }
  }
  ll num = min(posnum, minum);

  ll cur = T[0];
  ll ans = M;
  if (zer != cur) {
    ans += num;
  }
  rep(i, 1, M) {
    ll nx = T[i];
    if (nx == cur) {
      continue;
    } else {
      if (ans == M) {
        ans += num;
      } else {
        ans += 1;
      }
      cur = nx;
    }
  }
  cout << ans << endl;
}
