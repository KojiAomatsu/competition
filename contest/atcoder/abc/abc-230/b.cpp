#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

int main() {
  string S;
  cin >> S;

  set<ll> idxs;
  rep(i, 0, S.size()) {
    if (S[i] == 'o') {
      idxs.insert(i);
    }
  }

  vector<set<ll>> anss;
  rep(i, 0, 3) {
    set<ll> an;
    rep(j, 0, S.size()) {
      if (j % 3 == i) {
        an.insert(j);
      }
    }
    anss.push_back(an);
  }

  for (auto ans : anss) {
    if (idxs == ans) {
      cout << "Yes" << endl;
      return 0;
    }
  }
  cout << "No" << endl;
}