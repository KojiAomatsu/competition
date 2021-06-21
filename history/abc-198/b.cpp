#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

int main() {
  string N;
  cin >> N;
  ll len = N.size();
  bool flag = false;
  rep(i, 0, 10) {
    string ne = string(i, '0') + N;
    string rev = ne;
    reverse(rev.begin(), rev.end());
    if (ne == rev) {
      flag = true;
      break;
    }
  }
  cout << (flag ? "Yes" : "No") << endl;
}
