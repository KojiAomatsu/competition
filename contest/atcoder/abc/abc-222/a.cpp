#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

int main() {
  string N;
  cin >> N;

  ll ls = 4 - N.size();
  for (ll i = 0; i < ls; i++) {
    cout << "0";
  }
  cout << N << endl;
}
