#include "checker.h"
#include "solver.h"

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

unordered_map<string, string> readConstants(int argc, char* argv[]) {
    unordered_map<string, string> result;
    result["seed"] = "322"; // default value
    for (int i = 2; i < argc; i++) {
        const string token = argv[i];
        const size_t pos = token.find("=");
        const string key = token.substr(0, pos);
        const string value = token.substr(pos + 1, sz(token) - pos - 1);
        cout << "Parsed constant: " << key << " = " << value << endl;
        result[key] = value;
    }
    return result;
}

int main(int argc, char* argv[]) {
    cout.setf(ios::fixed); cout.precision(15);
    cerr.setf(ios::fixed); cerr.precision(10);

    const string fullName = argv[1];

    unordered_map<string, string> constants = readConstants(argc, argv);
    cout << "Constants are read from command-line arguments" << endl;

    auto getInputFilename = [&]() {
        stringstream ss;
        ss << "tests/" << fullName << ".in";
        const string filename = ss.str();
        return filename;
    };
    const string inFilename = getInputFilename();
    ifstream inFileStream(inFilename);
    const Input input = readInput(inFileStream);
    cout << "Input is read from file " << inFilename << endl;

    const Answer answer = solve(input, constants);
    cout << "Solve finished" << endl;

    stringstream ansStringStream;
    writeAnswer(answer, ansStringStream);
    const string ansString = ansStringStream.str();
    cout << "Answer is written to string, sz(ansString) == " << sz(ansString) << endl;

    ifstream checkerInStream(inFilename);
    istringstream checkerAnsStream(ansString);
    const ll score = evaluate(checkerInStream, checkerAnsStream);
    cout << "Evaluated score: " << score << endl;

    auto getOutputFilename = [&]() {
        stringstream ss;
        ss << "answers/" << fullName << "_" << score << ".out";
        const string filename = ss.str();
        return filename;
    };
    const string outFilename = getOutputFilename();
    ofstream outFileStream(outFilename);
    writeAnswer(answer, outFileStream);
    cout << "Answer is written to final file " << outFilename << endl;
}
