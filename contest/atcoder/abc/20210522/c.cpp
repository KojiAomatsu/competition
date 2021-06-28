#include <bits/stdc++.h>
using namespace std;

int main() {
  long long N;
  cin >> N;
  vector<vector<long long>> input(3, vector<long long>(N));
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < N; j++) {
      cin >> input[i][j];
    }
  }

  std::vector<long long> nums(N, 0);
  for (int i = 0; i < N; i++) {
    nums[input[0][i] - 1] += 1;
  }

  long long counter = 0;
  for (long long i = 0; i < N; i++) {
    long long c = input[2][i];
    long long b = input[1][c - 1];
    counter += nums[b - 1];
  }
  cout << counter << endl;
}