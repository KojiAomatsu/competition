#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

template <typename... Args>
auto printll(Args... xs) -> decltype(std::initializer_list<ll>{xs...}, std::declval<void>()) {
  for (auto &&x : {xs...}) {
    cout << x << " ";
  }
  cout << endl;
}

int main() {
  ll N;
  cin >> N;
  vector<ll> A(N);
  rep(i, 0, N) { cin >> A[i]; }
}
