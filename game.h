#pragma once

#include "util.h"

using namespace std;

bool game(vector<int> player_a, hole hole) {
  // variable declarations & preconditions
  int sum = 0;
  int iter = 0;

  // loop body
  while (sum < 21) {
    int a = player_a[iter];
    assume(a >= 1);
    assume(a <= 3);

    int b = (*hole)(vector<string> {"a", "sum", "iter"}, vector<int> {a, sum, iter});
    assume(b >= 1);
    assume(b <= 3);

    sum = sum + a;

    if(sum < 21 && sum + b >= 21) {
        return false;
    }

    sum = sum + b;
    iter = iter + 1;
  }

  return true;
}
