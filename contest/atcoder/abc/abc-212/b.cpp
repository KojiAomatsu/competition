#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

int main() {
  string s;
  cin >> s;
  vector<int> sint(4);
  rep(i, 0, 4) { sint[i] = s[i] - '0'; }
  int ze = sint[0];
  if (sint[1] == ze && sint[2] == ze && sint[3] == ze) {
    cout << "Weak" << endl;
    return 0;
  }

  bool is_weak = true;
  rep(i, 1, 4) {
    if (sint[i] != (ze + i) % 10) {
      is_weak = false;
      break;
    }
  }
  cout << (is_weak ? "Weak" : "Strong") << endl;
}