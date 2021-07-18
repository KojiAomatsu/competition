#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  ll N;
  cin >> N;
  vector<ll> A(N);
  vector<ll> B(N);
  vector<ll> C(N);
  rep(i, 0, N) { cin >> A[i]; }
  rep(i, 0, N) { cin >> B[i]; }
  rep(i, 0, N) { cin >> C[i]; }
  sort(A.begin(), A.end());
  sort(B.begin(), B.end());
  sort(C.begin(), C.end());

  int ans = 0;
  rep(i, 0, N) {
    ll b = B[i];
    auto ita = lower_bound(A.begin(), A.end(), b);
    ll oka = ita - A.begin() - 1;
    if (oka < 0) {
      continue;
    }
    auto itc = upper_bound(C.begin(), C.end(), b);
    ll okc = itc - C.begin();
    if (itc == C.end()) {
      continue;
    }
    A.erase(ita - 1);
    C.erase(itc);
    ans++;
  }
  cout << ans << endl;
}