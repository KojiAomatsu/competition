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
  ll prev = -1;
  ll x = -1;
  rep(i, 0, N) {
    if (prev < A[i]) {
      prev = A[i];
      continue;
    }
    if (prev > A[i]) {
      x = prev;
      break;
    }
  }
  if (x == -1) {
    x = A[N - 1];
  }
  rep(i, 0, N) {
    if (A[i] == x) continue;
    cout << A[i] << " ";
  }
  cout << endl;
}