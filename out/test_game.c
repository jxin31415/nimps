void the_21_game(int a_moves[]) {
    int running_sum = 0;
    
    while(1) {
        // Player A
        int a_move = a_moves[0]; a_moves++;
        assume(a_move >= 1 && a_move <= 3);
        running_sum += a_move;

        if(running_sum >= 21) { // Player A loses!
            break;
        }

        // Player B
        int b_move = ((4*4)*(4*4));
        assert(b_move >= 1 && b_move <= 3);
        running_sum += b_move;

        if(running_sum >= 21) { // Player B should never lose!
            assert(0);
        }
    }
}

// void the_21_game(int a_moves[]) {
//     int running_sum = 0;
    
//     while(running_sum < 21) {
//         // Player A
//         int a_move = a_moves[0]; a_moves++;
//         assume(a_move >= 1 && a_move <= 3);

//         // Player B
//         int b_move = ??;
//         assert(b_move >= 1 && b_move <= 3);

//         running_sum += a_move;
//         running_sum += b_move;

//         assert(running_sum <= 21);
//     }
// }