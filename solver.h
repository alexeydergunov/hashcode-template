#pragma once

#include "checker.h"

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <cmath>
#include <cstring>
#include <cassert>
#include <cstdlib>
#include <functional>
#include <numeric>
#include <random>
#include <ctime>
#include <chrono>
using namespace std;
#define sz(v) ((int)((v).size()))
#define all(v) (v).begin(),(v).end()
typedef pair<int, int> ii;
typedef long long ll;

struct Input {
    // TODO describe input struct
    int n;
    vector<int> a;
};

struct Answer {
    // TODO describe output struct
    ll score;
};

Input readInput(istream& fin) {
    // TODO read input struct
    Input I;
    fin >> I.n;
    I.a.resize(I.n);
    for (auto& x : I.a) {
        fin >> x;
    }
    return I;
}

void writeAnswer(const Answer& A, ostream& fout) {
    // TODO write output struct
    fout << A.score << '\n';
    fout.flush();
}

ll evaluate(istream& fin, istream& fout) {
    ll score = CheckerNamespace::validate(fin, fout);
    return score;
}

Answer solve(const Input &I, unordered_map<string, string>& constants) {
    //const auto seed = chrono::steady_clock::now().time_since_epoch().count();
    auto seed = seed_seq(all(constants["seed"]));
    mt19937 rng(seed);

    // TODO solve the problem, return answer
    Answer A;
    A.score = accumulate(all(I.a), 0LL);
    return A;
}
