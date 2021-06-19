#include <bits/stdc++.h>
using namespace std;
using ll = long long;
typedef pair<ll, ll> P;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

void solve(ll len, ll tar, string str) {
  ll cnt = 1;
  while (true) {
    if (cnt > tar) {
      break;
    }
    if (str.size() <= cnt * 2) {
      str = str + str;
    }
    auto a = str.substr(0, cnt);
    auto b = str.substr(cnt, cnt);
    if (a < b) {
      str = a;
      while (str.size() <= tar) {
        str = str + str;
      }
      break;
    }
    cnt *= 2;
  }
  str = str + str;
  cout << str.substr(0, tar) << endl;
}

int main() {
  ll N, K;
  string S;
  cin >> N >> K >> S;
  solve(N, K, S);
}
