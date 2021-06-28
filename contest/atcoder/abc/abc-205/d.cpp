#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

int main() {
  ll N, Q;
  cin >> N >> Q;
  vector<ll> A(N);

  rep(i, 0, N) { cin >> A[i]; }

  sort(A.begin(), A.end());
  auto cnt = [&](ll nu) {
    auto it = upper_bound(A.begin(), A.end(), nu);
    return it - A.begin();
  };

  rep(i, 0, Q) {
    ll num;
    cin >> num;
    ll left = 0;           // NG
    ll right = 1E18 + 1E6; // OK
    while (right - left > 1) {
      ll mid = (right + left) / 2;
      ll c;
      c = mid - cnt(mid);
      if (c >= num) {
        right = mid;
      } else {
        left = mid;
      }
    }
    cout << right << endl;
  }
}
