#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

int main() {
  ll N, K;
  cin >> N >> K;
  vector<ll> A(N);
  rep(i, 0, N) { cin >> A[i]; }
  sort(A.begin(), A.end());
  reverse(A.begin(), A.end());
  vector<ll> diffs(N + 1);
  rep(i, 0, N - 1) { diffs[i] = A[i] - A[i + 1]; }
  ll cnt = 0;
  ll stock = 0;
  rep(i, 0, N - 1) {
    ll diff = diffs[i];
    if (diff == 0) {
      stock++;
      continue;
    }
    K = K - 1;
    if (K == 0) {
      cnt += A[N];
      break;
    } else {
    }
  }
  cout << cnt << endl;
  return 0;
}