#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

int main() {
  ll N;
  cin >> N;
  rep(i, 0, N) {
    string s;
    cin >> s;
    ll si = s.size();
    set<ll> se;
    rep(j, 0, si) { se.insert(s[j] - '0'); }
    bool fla = true;
    rep(j, 0, 10) {
      if (j == 1 || j == 2 || j == 3) continue;
      if (se.count(j) != 0) {
        fla = false;
      }
    }
    if (fla) {
      cout << 1 << endl;
      continue;
    }
    bool flb = true;
    rep(j, 0, 10) {
      if (0 <= j && j <= 1) {
        if (se.count(j) != 0) {
          flb = false;
        }
      } else if (7 <= j) {
        if (se.count(j) != 0) {
          flb = false;
        }
      }
    }
    if (flb) {
      cout << 2 << endl;
      continue;
    }
    bool flc = true;
    rep(j, 0, 10) {
      if (0 <= j && j <= 3) {
        if (se.count(j) != 0) {
          flc = false;
        }
      }
    }
    if (flc) {
      cout << 3 << endl;
      continue;
    }
    cout << 4 << endl;
    continue;
  }
}