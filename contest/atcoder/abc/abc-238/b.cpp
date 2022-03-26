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
  vector<bool> cuts(360, false);
  cuts[0] = true;
  ll sum = 0;
  for (auto a : A) {
    sum += a;
    sum %= 360;
    cuts[sum] = true;
  }
  ll last = 0;
  ll mx = 0;
  rep(i, 0, 360) {
    if (cuts[i]) {
      mx = max(mx, i - last);
      last = i;
    }
  }
  mx = max(mx, 360 - last);
  cout << mx << endl;
}