#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

int main() {
  string a, b;
  cin >> a >> b;
  bool is_easy = true;
  int le = min(a.size(), b.size());
  rep(i, 0, le) {
    int pa = a.size() - 1 - i;
    int pb = b.size() - 1 - i;
    int na = a[pa] - '0';
    int nb = b[pb] - '0';
    if (na + nb > 9) is_easy = false;
  }
  cout << (is_easy ? "Easy" : "Hard") << endl;
  return 0;
}