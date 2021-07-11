#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

int main() {
  ll N;
  cin >> N;
  vector<ll> divs;
  for (ll i = 1; i * i <= N; i++) {
    if (N % i == 0) {
      cout << i << endl;
      if (i * i == N) {
        continue;
      }
      divs.push_back(i);
    }
  }
  reverse(divs.begin(), divs.end());
  for (auto d : divs) {
    cout << N / d << endl;
  }
}