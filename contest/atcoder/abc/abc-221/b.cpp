#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

int main() {
  string S, T;
  cin >> S >> T;
  if (S == T) {
    cout << "Yes" << endl;
    return 0;
  }
  rep(i, 0, S.size() - 1) {
    swap(S[i], S[i + 1]);
    if (S == T) {
      cout << "Yes" << endl;
      return 0;
    }
    swap(S[i], S[i + 1]);
  }

  cout << "No" << endl;
  return 0;
}
