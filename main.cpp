#include "util.h"
#include "verifier.h"
#include "enumerate.h"
#include "game.h"

using namespace std;

vector<string> vars = {"sum", "a", "iter"};
vector<int> consts = {0, 1, 2, 4};
vector<int> valid_moves = {1, 2, 3};

string game_str;
size_t hole_pos;

bool verif_wrapper(ast_ptr node) {
    string copy = game_str;
    copy.replace(hole_pos, 2, node->to_string());

    string out_file = "out/test_game.c";
    ofstream out(out_file);
    out << copy;
    out.close();

    return verifier(node, out_file);
}

string read_game() {
    ifstream t("game.c");
    stringstream buffer;
    buffer << t.rdbuf();
    return buffer.str();
}

int main() {

    game_str = read_game();
    hole_pos = game_str.find("??");
    if (hole_pos == string::npos) {
        cout << "No holes found" << endl;
        return 0;
    }

    setup_rand_games(valid_moves);
    ast_ptr ans = bottom_up(vars, consts, verif_wrapper);
    
    return 0;
}