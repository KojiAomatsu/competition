#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

int main() {
  string X;
  ll N;
  cin >> X >> N;
  map<char, char> mp;
  map<char, char> rmp;
  rep(i, 0, 26) {
    mp[X[i]] = 'a' + i;
    rmp['a' + i] = X[i];
  }

  vector<string> S(N);
  vector<string> newS(N);
  rep(i, 0, N) {
    cin >> S[i];
    string ns = "";
    rep(j, 0, S[i].size()) { ns += mp[S[i][j]]; }
    newS[i] = ns;
  }
  sort(newS.begin(), newS.end());
  for (auto st : newS) {
    rep(i, 0, st.size()) { cout << rmp[st[i]]; }
    cout << endl;
  }
}