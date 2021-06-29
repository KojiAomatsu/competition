#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

int main() {
  string N;
  cin >> N;
  map<int, int> a;
  int sum;
  rep(i, 0, N.size()) {
    a[(N[i] - '0') % 3]++;
    sum += (N[i] - '0');
    sum %= 3;
  }
  if (sum == 0) {
    cout << 0 << endl;
    return 0;
  }
  if (sum == 1) {
    if (a[1] >= 1 && a[1] + a[2] + a[0] > 1) {
      cout << 1 << endl;
      return 0;
    } else if (a[2] >= 2 && a[1] + a[2] + a[0] > 2) {
      cout << 2 << endl;
      return 0;
    }
  }
  if (sum == 2) {
    if (a[2] >= 1 && a[1] + a[2] + a[0] > 1) {
      cout << 1 << endl;
      return 0;
    } else if (a[1] >= 2 && a[1] + a[2] + a[0] > 2) {
      cout << 2 << endl;
      return 0;
    }
  }
  cout << -1 << endl;
}
