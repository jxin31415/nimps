#pragma once

#include "util.h"

using namespace std;

struct envt {
    map<string, int> env;

    int get(string s) { return env[s]; }
    void set(string s, int n) { env[s] = n; }
};

class Node {
private:
public:
    virtual string to_string() = 0;
    virtual int interpret(envt env) = 0;
};

typedef shared_ptr<Node> ast_ptr;

class Const : public virtual Node {
private:
    int val;
public:
    Const(int v) { val = v; }

    string to_string() {
        return std::to_string(val);
    }

    int interpret(envt env) {
        return val;
    }
};

class Var : public virtual Node {
private:
    string name;
public:
    Var(string n) { name = n; }

    string to_string() {
        return name;
    }

    int interpret(envt env) {
        return env.get(name);
    }
};

class Plus : public virtual Node {
private:
    ast_ptr left;
    ast_ptr right;
public:
    Plus(ast_ptr l, ast_ptr r) { left = l; right = r; }
    
    string to_string() {
        return "("+ left->to_string() + "+" + right->to_string()+")";
    }

    int interpret(envt env) {
        return left->interpret(env) + right->interpret(env);
    }
};

class Minus : public virtual Node {
private:
    ast_ptr left;
    ast_ptr right;
public:
    Minus(ast_ptr l, ast_ptr r) { left = l; right = r; }
    
    string to_string() {
        return "("+ left->to_string() + "-" + right->to_string()+")";
    }

    int interpret(envt env) {
        return left->interpret(env) - right->interpret(env);
    }
};

class Times : public virtual Node {
private:
    ast_ptr left;
    ast_ptr right;
public:
    Times(ast_ptr l, ast_ptr r) { left = l; right = r; }
    
    string to_string() {
        return "("+ left->to_string() + "*" + right->to_string()+")";
    }

    int interpret(envt env) {
        return left->interpret(env) * right->interpret(env);
    }
};

class Lt : public virtual Node {
private:
    ast_ptr left;
    ast_ptr right;
public:
    Lt(ast_ptr l, ast_ptr r) { left = l; right = r; }
    
    string to_string() {
        return "("+ left->to_string() + "<" + right->to_string()+")";
    }

    int interpret(envt env) {
        return left->interpret(env) < right->interpret(env);
    }
};

class Eq : public virtual Node {
private:
    ast_ptr left;
    ast_ptr right;
public:
    Eq(ast_ptr l, ast_ptr r) { left = l; right = r; }
    
    string to_string() {
        return "("+ left->to_string() + "==" + right->to_string()+")";
    }

    int interpret(envt env) {
        return left->interpret(env) == right->interpret(env);
    }
};

class And : public virtual Node {
private:
    ast_ptr left;
    ast_ptr right;
public:
    And(ast_ptr l, ast_ptr r) { left = l; right = r; }
    
    string to_string() {
        return "("+ left->to_string() + "&&" + right->to_string()+")";
    }

    int interpret(envt env) {
        return left->interpret(env) && right->interpret(env);
    }
};

class Or : public virtual Node {
private:
    ast_ptr left;
    ast_ptr right;
public:
    Or(ast_ptr l, ast_ptr r) { left = l; right = r; }
    
    string to_string() {
        return "("+ left->to_string() + "||" + right->to_string()+")";
    }

    int interpret(envt env) {
        return left->interpret(env) || right->interpret(env);
    }
};

class Cond : public virtual Node {
private:
    ast_ptr cond;
    ast_ptr tcase;
    ast_ptr fcase;
public:
    Cond(ast_ptr c, ast_ptr t, ast_ptr f) { cond = c; tcase = t; fcase = f; }
    
    string to_string() {
        return "(" + cond->to_string() + " ? " + tcase->to_string() + " : " + fcase->to_string() + ")";
    }

    int interpret(envt env) {
        if (cond->interpret(env)) {
            return tcase->interpret(env);
        } else {
            return fcase->interpret(env);
        }
    }
};