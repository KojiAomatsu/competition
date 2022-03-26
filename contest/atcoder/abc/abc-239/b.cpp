#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

int main() {
  ll N;
  cin >> N;
  ll ans = N / 10;
  if (N < 0 && N % 10 != 0) {
    ans--;
  }
  cout << ans << endl;
}