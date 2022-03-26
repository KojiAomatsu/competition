#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

int main() {
  ll N;
  cin >> N;
  vector<ll> A(N);
  rep(i, 0, N) { cin >> A[i]; }
  ll cur = A[0];
  rep(i, 1, N) {
    if (cur >= A[i]) {
      break;
    } else {
      cur = A[i];
    }
  }
  cout << cur << endl;
  return 0;
}