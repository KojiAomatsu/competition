#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

bool judge(ll num) {
  ll rest = num % 11;
  ll mini = 111 * rest;
  return num >= mini;
}

int main() {
  ll N;
  cin >> N;
  rep(i, 0, N) {
    ll tmp;
    cin >> tmp;
    bool res = judge(tmp);
    cout << (res ? "Yes" : "No") << endl;
  }
}