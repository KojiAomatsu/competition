#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

int main() {
  ll N;
  cin >> N;
  vector<string> oks;
  set<string> ngs;
  rep(i, 0, N) {
    string s;
    cin >> s;
    if (s[0] == '!')
      ngs.insert(s.substr(1));
    else
      oks.push_back(s);
  }
  for (auto ok : oks) {
    if (ngs.count(ok)) {
      cout << ok << endl;
      return 0;
    }
  }
  cout << "satisfiable" << endl;
}
