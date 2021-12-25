#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

int main() {
  ll L, R;
  cin >> L >> R;
  L--;
  R--;
  string S;
  cin >> S;
  while (L < R) {
    swap(S[L], S[R]);
    L++;
    R--;
  }
  cout << S << endl;
}
