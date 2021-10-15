#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

int main() {
  ll N, P;
  cin >> N >> P;
  ll cn = 0;
  rep(i, 0, N) {
    ll ai;
    cin >> ai;
    if (ai < P) cn++;
  }
  cout << cn << endl;
}
