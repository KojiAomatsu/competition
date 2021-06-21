#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

unsigned GetDigit(unsigned num) {
  unsigned digit = 0;
  while (num != 0) {
    num /= 10;
    digit++;
  }
  return digit;
}

int main() {
  ll N;
  cin >> N;
  ll cnt = 0;
  ll num = 1;
  while (true) {
    ll di = GetDigit(num);
    ll rep = num * pow(10, di) + num;
    if (rep <= N) {
      cnt++;
      num++;
    } else {
      break;
    }
  }
  cout << cnt << endl;
}
