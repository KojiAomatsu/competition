#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

int main() {
  ll N;
  cin >> N;
  vector<ll> A(N);
  vector<ll> B(N);
  rep(i, 0, N) { cin >> A[i]; }
  rep(i, 0, N) { cin >> B[i]; }
  ll low = 1;
  ll high = 1000;
  rep(i, 0, N) {
    low = max(low, A[i]);
    high = min(high, B[i]);
  }
  if (low > high) {
    cout << 0 << endl;
  } else {
    cout << high - low + 1 << endl;
  }
}