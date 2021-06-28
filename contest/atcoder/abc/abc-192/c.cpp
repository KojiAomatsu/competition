#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

// 文字列変換 %lld , %d など

int main() {
  string N;
  ll K;
  cin >> N >> K;
  auto conv = [](string s) {
    string sorted = s;
    string reversed = s;
    sort(sorted.begin(), sorted.end());
    sort(reversed.begin(), reversed.end());
    reverse(reversed.begin(), reversed.end());

    ll so;
    ll re;
    sscanf(sorted.c_str(), "%lld", &so);
    sscanf(reversed.c_str(), "%lld", &re);
    return to_string(re - so);
  };

  rep(i, 0, K) { N = conv(N); }
  cout << N << endl;
}
