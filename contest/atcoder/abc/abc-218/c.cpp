#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

int main() {
  ll N;
  cin >> N;
  vector<P> S;
  vector<P> T;
  rep(i, 0, N) {
    string sis;
    cin >> sis;
    rep(j, 0, N) {
      if (sis[j] == '#') {
        S.push_back({i, j});
      }
    }
  }
  rep(i, 0, N) {
    string tis;
    cin >> tis;
    rep(j, 0, N) {
      if (tis[j] == '#') {
        T.push_back({i, j});
      }
    }
  }
  if (S.size() != T.size()) {
    cout << "No" << endl;
    return 0;
  }
  if (S.size() == 0) {
    cout << "Yes" << endl;
    return 0;
  }
  sort(T.begin(), T.end());
  P baseT = T[0];
  rep(ti, 1, T.size()) {
    P ns = {T[ti].first - baseT.first, T[ti].second - baseT.second};
    T[ti] = ns;
  }
  bool ok = false;
  rep(z, 0, 4) {
    rep(si, 0, S.size()) {
      ll x = S[si].first;
      ll y = S[si].second;
      S[si] = {-y, x};
    }
    sort(S.begin(), S.end());
    P base = S[0];
    bool tmpOK = true;
    rep(si, 1, S.size()) {
      P check = {S[si].first - base.first, S[si].second - base.second};
      auto it = find(T.begin(), T.end(), check);
      if (it == T.end()) {
        tmpOK = false;
        break;
      }
    }
    if (tmpOK) {
      ok = true;
    }
  }

  cout << (ok ? "Yes" : "No") << endl;
}
