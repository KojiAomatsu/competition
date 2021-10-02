#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

int main() {
  vector<string> S(3);
  rep(i, 0, 3) { cin >> S[i]; }
  string T;
  cin >> T;
  rep(i, 0, T.size()) {
    if (T[i] == '1') {
      cout << S[0];
    } else if (T[i] == '2') {
      cout << S[1];
    } else {
      cout << S[2];
    }
  }
  cout << endl;
  return 0;
}