#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

int main() {
  ll N, X;
  cin >> N >> X;
  vector<ll> A(N);
  ll sum = 0;
  rep(i, 0, N) {
    cin >> A[i];
    if (i % 2 == 1) {
      sum += A[i] - 1;
    } else {
      sum += A[i];
    }
  }
  cout << (sum <= X ? "Yes" : "No") << endl;
}