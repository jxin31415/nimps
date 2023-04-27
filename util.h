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

void assume(bool constraint) {} // Dummy assume
void assert(bool constraint) {} // Dummy assert

typedef int (*hole)(vector<string>, vector<int>);