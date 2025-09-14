#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<string> strings;

int operate(int a, int b, char op) {
    if (op == '+') return a + b;
    if (op == '-') return a - b;
    if (op == '*') return a * b;
    return a;
}

int re(int row, int col, int total, char op) {
    if (col >= strings[row].size()) {
        return total;
    }

    char current = strings[row][col];

    if (isdigit(current)) {
        int value = current - '0';
        total = operate(total, value, op);
        return re(row, col + 1, total, op);
    }
    else if (current == '+' || current == '-' || current == '*') {
        op = current;
        return re(row, col + 1, total, op);
    }
    else if (current == '^') {
        int branchTotal = re(row - 1, col, total, op);
        return re(row, col + 1, branchTotal, op);
    }
    else if (current == 'v') {
        int branchTotal = re(row + 1, col, total, op);
        return re(row, col + 1, branchTotal, op);
    }
    else {
        return re(row, col + 1, total, op);
    }
}

int input() {
    if (strings.empty()) return 0;
    return re(0, 0, 0, '+');
}

void addString(string str) {
    strings.push_back(str);
}