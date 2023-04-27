int main() {
  // variable declarations
  int sum;
  int win;
  int iter;

  // pre-conditions
  (sum = 0);
  (win = 0);
  (iter = 0);

  // loop body
  while ((sum < 21)) {
    {
    int a;
    assume( (a >= 1) );
    assume( (a <= 3) );

    int b;
    (b = ??);
    // assume( (b >= 1) );
    // assume( (b <= 3) );

    (sum = (sum + a));

    if(sum >= 21) {
        win = 1;
    }

    (sum = (sum + b));
    (iter = (iter + 1));
    }
  }
  // post-condition
  assert( (win > 0) );
}
