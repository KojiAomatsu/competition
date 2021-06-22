#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

int main() {
  ll N;
  cin >> N;
  ll now = 1;
  ll cnt = 0;
  while (true) {
    if ((N - now * (now + 1) / 2) < 0) {
      break;
    }
    if ((N - now * (now + 1) / 2) % now == 0) {
      cnt++;
    }
    now++;
  }
  cout << cnt * 2 << endl;
}
