#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

int main() {
  ll N, Q;
  cin >> N >> Q;
  vector<ll> A(N);
  rep(i, 0, N) { cin >> A[i]; }
  sort(A.begin(), A.end());
  rep(i, 0, Q) {
    ll xi;
    cin >> xi;
    auto it = lower_bound(A.begin(), A.end(), xi);
    ll bef = it - A.begin();
    cout << N - bef << endl;
  }
}