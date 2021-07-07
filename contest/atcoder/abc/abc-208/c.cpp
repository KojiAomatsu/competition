#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

int main() {
  ll N, K;
  cin >> N >> K;
  vector<ll> a(N);
  rep(i, 0, N) { cin >> a[i]; }
  ll base = K / N;
  ll rem = K % N;
  vector<ll> cpa = a;
  sort(cpa.begin(), cpa.end());
  ll leas = cpa[rem];

  rep(i, 0, N) {
    if (a[i] >= leas) {
      cout << base << endl;
    } else {
      cout << base + 1 << endl;
    }
  }
}