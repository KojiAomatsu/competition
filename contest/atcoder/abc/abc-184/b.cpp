#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

int main() {
  ll N, X;
  cin >> N >> X;
  string s;
  cin >> s;
  rep(i, 0, N) {
    if (s[i] == 'o') {
      X += 1;
    } else {
      X = max(X - 1, 0LL);
    }
  }
  cout << X << endl;
}
