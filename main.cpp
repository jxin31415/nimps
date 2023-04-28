#include "util.h"
#include "verifier.h"
#include "enumerate.h"
#include "game.h"

using namespace std;

vector<string> vars = {"a", "sum", "iter"}; // "a" is the other player's moves
vector<int> consts = {0, 1, 2, 4};
vector<int> valid_moves = {1, 2, 3};

bool verif_wrapper(ast_ptr node, string game_str, size_t hole_pos, vector<ast_ptr>& nums, vector<ast_ptr>& bools) {
    string copy = game_str;
    copy.replace(hole_pos, 2, node->to_string());

    return verifier(node, copy, nums, bools);
}

string read_game() {
    ifstream t("game.fun");
    stringstream buffer;
    buffer << t.rdbuf();
    return buffer.str();
}

int main() {
    auto start = chrono::steady_clock::now();

    // Input Parsing
    string game_str = read_game();

    // Adding encoding for valid moves
    string valid_moves_str = "";
    for(int move: valid_moves) {
        valid_moves_str.append(vars[0] + "==" + to_string(move) + " || ");
    }
    valid_moves_str.resize(valid_moves_str.size() - 4); // Remove the last ||
    size_t fun_pos = game_str.find("fun");
    game_str.insert(fun_pos + 3, "[(" + valid_moves_str + ")]");

    // Identifying location for loop invariant
    size_t inv_pos = game_str.find("[]");
    game_str.insert(inv_pos + 1, "?inv && (" + valid_moves_str + ")");
    
    // Finding the program hole
    size_t hole_pos = game_str.find("??");
    if (hole_pos == string::npos) {
        cout << "No holes found" << endl;
        return 0;
    }

    cout << "Now enumerating over programs..." << endl;
    vector<ast_ptr> nums;
    vector<ast_ptr> bools;
    setup_rand_games(valid_moves);
    bottom_up(vars, consts, nums, bools);
    
    for(ast_ptr node: nums) {
        if (verif_wrapper(node, game_str, hole_pos, nums, bools)) {
            cout << "Strategy found and verified!" << endl;
            auto end = chrono::steady_clock::now();
            cout << "Elapsed(s)=" << chrono::duration_cast<chrono::seconds>(end - start).count() << endl;
            return 0;
        }
    }

    cout << "No valid strategy found :(" << endl;
    auto end = chrono::steady_clock::now();
    cout << "Elapsed(s)=" << chrono::duration_cast<chrono::seconds>(end - start).count() << endl;
    return 0;
}