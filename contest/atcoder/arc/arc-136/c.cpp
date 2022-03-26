#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

int main() {
  ll N;
  cin >> N;
  vector<ll> A(2 * N);
  rep(i, 0, N) {
    cin >> A[i];
    A[i + N] = A[i];
  }

  priority_queue<P> pq;

  // 0とNの時は特別に計算
  rep(i, 1, N - 1) {
    if (A[i - 1] > A[i] && A[i + 1] > A[i]) {
    }
  }
}