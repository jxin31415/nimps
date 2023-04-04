#include "util.h"
#include "inv_gen.h"
#include "enumerate.h"

using namespace std;

string game;
size_t hole_pos;

bool verifier(ast_ptr node) {
    string copy = game;
    copy.replace(hole_pos, 2, node->to_string());

    ofstream out_file("out/test_game.c");
    out_file << copy;
    out_file.close();
    
    // Verify with a loop invariant generator

    return false;
}

string read_game() {
    ifstream t("game.c");
    stringstream buffer;
    buffer << t.rdbuf();
    return buffer.str();
}

int main() {

    game = read_game();
    hole_pos = game.find("??");
    if (hole_pos == string::npos) {
        cout << "No holes found" << endl;
        return 0;
    }

    vector<string> vars = {"running_sum", "player_a"};
    vector<int> consts = {0, 1, 2, 4};

    ast_ptr ans = bottom_up(vars, consts, verifier);
    
    return 0;
}