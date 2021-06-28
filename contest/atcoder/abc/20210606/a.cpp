#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

int main() {
  ll N, K;
  cin >> N >> K;
  if (N == K) {
    cout << N << endl;
    return 0;
  }
  cout << (3 - N - K) << endl;
}