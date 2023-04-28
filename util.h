#pragma once

#include <string>
#include <vector>
#include <iostream>
#include <random>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <sstream>
#include <assert.h>
#include <stdlib.h>
#include <cstdlib>
#include <experimental/filesystem>
#include <memory>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>
#include <cmath>
#include <cassert>
#include <numeric>
#include <math.h>
#include <cstring>
#include <optional>
#include <chrono>

using namespace std;

#undef assert

// ----- Baselines -----
const bool OBSERVATIONAL_EQUIVALENCE = true;
const bool RANDOM_OPPONENT = true;
const bool ADVERSARIAL_OPPONENT = false;
const bool TYPE_DIRECTED = true;

void assume(bool constraint) {} // Dummy assume
void assert(bool constraint) {} // Dummy assert

typedef int (*hole)(vector<string>, vector<int>);