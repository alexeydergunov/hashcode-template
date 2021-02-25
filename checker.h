#pragma once

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

namespace CheckerNamespace {
    ll validate(istream &fin, istream &fout) {
        // read input
        int n;
        fin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            fin >> a[i];
        }

        // read answer
        ll userScore;
        fout >> userScore;

        // evaluate and return score
        const ll realScore = accumulate(a.begin(), a.end(), 0LL);
        if (userScore == realScore) {
            return userScore;
        } else {
            return 0;
        }
    }
}
