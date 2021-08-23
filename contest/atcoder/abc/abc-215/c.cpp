#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

int main() {
  string S;
  cin >> S;
  sort(S.begin(), S.end());
  ll K;
  cin >> K;
  rep(i, 0, K - 1) { next_permutation(S.begin(), S.end()); }
  cout << S << endl;
}
