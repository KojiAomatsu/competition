#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

int main() {
  int N;
  string S;
  cin >> N >> S;
  cout << (S[N - 1] == 'o' ? "Yes" : "No") << endl;
}
