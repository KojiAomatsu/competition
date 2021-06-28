#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

int main() {
  ll N;
  cin >> N;

  vector<ll> li(N, 0);
  vector<ll> sm(N);
  vector<ll> mxli(N);
  ll mx = 0;

  rep(i, 0, N) {
    ll num;
    cin >> num;
    li[i] = num;

    mx = max(mx, num);
    mxli[i] = mx;
    if (i == 0) {
      sm[i] = num;
    } else {
      sm[i] = num + sm[i - 1];
    }
  }

  vector<ll> answers(N);
  rep(i, 0, N) {
    if (i == 0) {
      answers[i] = 2 * li[0];
    } else {
      answers[i] = mxli[i] * (i + 1) - mxli[i - 1] * i + sm[i] + answers[i - 1];
    }

    cout << answers[i];
    if (i == N - 1) {
      cout << endl;
    } else {
      cout << "\n";
    }
  }
}
