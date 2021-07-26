#include <bits/stdc++.h>
using namespace std;
using ll = long long;
typedef pair<ll, ll> P;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

int main() {
  ll N;
  cin >> N;
  rep(i, 0, N) {
    ll le;
    cin >> le;
    vector<vector<ll>> scores(le, vector<ll>(5));
    rep(j, 0, le) {
      rep(k, 0, 5) { cin >> scores[j][k]; }
    }
    set<ll> cands;
    rep(j, 0, le) { cands.insert(j); }
    rep(j, 0, le) {
      if (cands.find(j) == cands.end()) continue;
      // set に対して iterator の for loop
      for (auto itr = cands.cbegin(); itr != cands.cend(); itr++) {
        auto cand = *itr;
        if (scores[j][0] == scores[cand][0]) continue;
        ll wins = 0;
        rep(k, 0, 5) {
          if (scores[j][k] <= scores[cand][k]) wins++;
        }

        if (wins >= 3) {
          if (cands.find(cand) != cands.end()) itr = cands.erase(itr); // erase は次のiteratorを返す
        } else {
          cands.erase(j);
          break;
        }
      }
    }
    if (cands.size() == 0) {
      cout << -1 << endl;
    } else {
      for (auto c : cands) {
        bool ok = true;
        rep(t, 0, le) {
          if (c == t) continue;
          ll wins = 0;
          rep(k, 0, 5) {
            if (scores[c][k] <= scores[t][k]) wins++;
          }
          if (wins >= 3) {
            // ok
          } else {
            cout << -1 << endl;
            ok = false;
            break;
          }
        }
        if (ok) cout << c + 1 << endl;
      }
    }
  }
  return 0;
}