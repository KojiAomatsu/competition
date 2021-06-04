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

ll SameDigits(int digits, int num) {
  ll ans = 0;
  for (ll i = 0; i < digits; i++) {
    ans += num * pow(10, i);
  }
  return ans;
}

int main() {
  ll N;
  cin >> N;
  cout << GetDigit(N) << endl;
  cout << SameDigits(5, N) << endl;
}