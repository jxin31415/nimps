#pragma once

#include "util.h"
#include "ast.h"

using namespace std;

vector<envt> test_vec(100);
void setup_test_vec(vector<string>& vars) {
    for(int t = 0; t < test_vec.size(); t++) {
        envt env;
        for(string each: vars) {
            env.set(each, rand());
        }
        test_vec[t] = env;
    }
}

string gen_hash(ast_ptr tree) {
    string hash = "";
    for(envt env: test_vec) {
        hash += to_string(tree->interpret(env));
        hash += " ";
    }
    return hash;
}

void insert(ast_ptr node, vector<ast_ptr>* progs, set<string>* set) {
    string hash = gen_hash(node); // If using observational equivalence, check output on random test vectors

    if(!OBSERVATIONAL_EQUIVALENCE) { // If not, compare syntax directly
        hash = node->to_string();
    }

    if(set->count(hash) == 0) {
        progs->push_back(node);
        set->insert(hash);
    }
}

void bottom_up(vector<string>& vars, vector<int>& consts, vector<ast_ptr>& nums, vector<ast_ptr>& bools, int global_bound=3) {

    // Utilize observational equivalence using "test vectors"
    setup_test_vec(vars);

    vector<ast_ptr>* trees_num = new vector<ast_ptr>();
    vector<ast_ptr>* trees_bool = new vector<ast_ptr>();
    set<string>* visited_num = new set<string>();
    set<string>* visited_bool = new set<string>();

    if(!TYPE_DIRECTED) {
        trees_bool = trees_num;
        visited_bool = visited_num;
    }

    for(string each: vars) {
        insert(make_shared<Var>(each), trees_num, visited_num);
    }

    for(int each: consts) {
        insert(make_shared<Const>(each), trees_num, visited_num);
    }

    insert(make_shared<Const>(0), trees_bool, visited_bool);
    insert(make_shared<Const>(1), trees_bool, visited_bool);

    int size = 1;
    while(size < global_bound) {
        int count_nums = trees_num->size();
        int count_bool = trees_bool->size();

        // Conditional Statement
        for(int c = 0; c < count_bool; c++) {
            for(int t = 0; t < count_nums; t++) {
                for(int f = 0; f < count_nums; f++) {
                    insert(make_shared<Cond>((*trees_bool)[c], (*trees_num)[t], (*trees_num)[f]), trees_num, visited_num);
                }
            }
        }

        // Binary Ops on NUM
        for(int a = 0; a < count_nums; a++) {
            for(int b = 0; b < count_nums; b++) {
                insert(make_shared<Plus>((*trees_num)[a], (*trees_num)[b]), trees_num, visited_num);
                insert(make_shared<Minus>((*trees_num)[a], (*trees_num)[b]), trees_num, visited_num);
                insert(make_shared<Times>((*trees_num)[a], (*trees_num)[b]), trees_num, visited_num);
                insert(make_shared<Lt>((*trees_num)[a], (*trees_num)[b]), trees_bool, visited_bool);
                insert(make_shared<Eq>((*trees_num)[a], (*trees_num)[b]), trees_bool, visited_bool);
            }
        }

        // Binary Ops on BOOL
        for(int a = 0; a < count_bool; a++) {
            for(int b = 0; b < count_bool; b++) {
                insert(make_shared<And>((*trees_bool)[a], (*trees_bool)[b]), trees_bool, visited_bool);
                insert(make_shared<Or>((*trees_bool)[a], (*trees_bool)[b]), trees_bool, visited_bool);
            }
        }

        size++;
    }

    cout << "Enumerated over " << trees_num->size() + trees_bool->size() << " programs" << endl;

    for(ast_ptr each: *trees_num) {
        nums.push_back(each);
    }
    for(ast_ptr each: *trees_bool) {
        bools.push_back(each);
    }
}