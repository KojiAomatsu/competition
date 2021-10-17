#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

int main() {
  string s;
  cin >> s;
  vector<string> ss;
  ll si = s.size();
  rep(i, 0, si) { ss.push_back(s.substr(i, si) + s.substr(0, i)); }
  sort(ss.begin(), ss.end());
  cout << ss[0] << endl;
  cout << ss[si - 1] << endl;
}