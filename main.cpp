#include "util.h"
#include "verifier.h"
#include "enumerate.h"
#include "game.h"

using namespace std;

vector<string> vars = {"sum", "a", "iter"};
vector<int> consts = {0, 1, 2, 4};
vector<int> valid_moves = {1, 2, 3};

bool verif_wrapper(ast_ptr node, string game_str, size_t hole_pos) {
    string copy = game_str;
    copy.replace(hole_pos, 2, node->to_string());

    string out_file = "out/test_game.fun";
    ofstream out(out_file);
    out << copy;
    out.close();

    return verifier(node, out_file);
}

string read_game() {
    ifstream t("game.fun");
    stringstream buffer;
    buffer << t.rdbuf();
    return buffer.str();
}

int main() {

    string game_str = read_game();
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
        if (verif_wrapper(node, game_str, hole_pos)) {
            cout << "Strategy found and verified!" << endl;
            return 0;
        }
    }

    cout << "No valid strategy found :(" << endl;
    return 0;
}