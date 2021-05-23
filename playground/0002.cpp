#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<tuple<string, long long>> input(N);
  for (int i = 0; i < N; i++) {
    string a;
    int b;
    cin >> a >> b;
    input[i] = tuple(a, b);
  }

  sort(input.begin(), input.end(),
       [](tuple<string, long long> a, tuple<string, long long> b) {
         return get<1>(a) > get<1>(b);
       });
  cout << get<0>(input[1]) << endl;
}