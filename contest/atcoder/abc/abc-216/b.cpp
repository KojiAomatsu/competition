#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

int main() {
  ll N;
  cin >> N;
  vector<string> S(N);
  vector<string> T(N);
  rep(i, 0, N) { cin >> S[i] >> T[i]; }
  bool dup = false;
  rep(i, 0, N) {
    rep(j, 0, N) {
      if (i == j) continue;
      if (S[i] == S[j] && T[i] == T[j]) {
        dup = true;
        break;
      }
    }
    if (dup) {
      break;
    }
  }
  cout << (dup ? "Yes" : "No") << endl;
}