#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

int main() {
  ll N;
  string S;
  cin >> N >> S;
  bool ans = 0;
  rep(i, 0, N) {
    ans = i;
    if (S[i] == '1') {
      break;
    }
  }
  cout << (ans % 2 == 0 ? "Aoki" : "Takahashi") << endl;
}