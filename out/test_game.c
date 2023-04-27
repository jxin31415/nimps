int main() {
  // variable declarations & preconditions
  int sum = 0;
  int win = 0;
  int iter = 0;

  // loop body
  while (sum < 21) {
    int a;
    assume(a >= 1);
    assume(a <= 3);

    int b = ((iter<sum)||(iter<a));
    // assume(b >= 1);
    // assume(b <= 3);

    sum = sum + a;

    if(sum >= 21) {
        win = 1;
    }

    sum = sum + b;
    iter = iter + 1;
  }
  // post-condition
  assert(win > 0);
}
