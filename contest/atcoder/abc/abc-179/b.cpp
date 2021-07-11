#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

int main() {
  ll N;
  cin >> N;
  vector<ll> d1(N);
  vector<ll> d2(N);
  rep(i, 0, N) { cin >> d1[i] >> d2[i]; }

  ll sto = 0;
  rep(i, 0, N) {
    if (d1[i] == d2[i]) {
      sto++;
    } else {
      sto = 0;
    }
    if (sto == 3) {
      cout << "Yes" << endl;
      return 0;
    }
  }

  cout << "No" << endl;
  return 0;
}