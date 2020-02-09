#include <algorithm>
#include <iostream>
#include <stack>
#include <string>

using namespace std;

void printStack(stack<int> s) {
    while (!s.empty()) {
        cout << " " << s.top();
        s.pop();
    }
    cout << '\n';
}

bool isOperator(char ch) {
    if (isalpha(ch) || isdigit(ch)) {
        return false;
    }
}

bool isOperand(char ch) {
    if (isalpha(ch)) {
        return true;
    }
}

//higher number, higher priority
int getPriority(char ch) {
    if (ch == '-' || ch == '+')
        return 1;
    else if (ch == '*' || ch == '/')
        return 2;
    else if (ch == '^')
        return 3;
    return 0;
}

string in2Post(string str) {
    stack<char> s;
    str = '(' + str + ')';
    string result;

    for (int i = 0; i < str.size(); i++) {
        if (isalpha(str[i]) || isdigit(str[i]))
            result += str[i];
        else if (str[i] == '(')
            s.push('(');
        else if (str[i] == ')') {
            while (s.top() != '(') {
                result += s.top();
                s.pop();
            }
            s.pop();
        } else {
            if (isOperator(s.top())) {
                while (getPriority(str[i]) <= getPriority(s.top())) {
                    result += s.top();
                    s.pop();
                }
                s.push(str[i]);
            }
        }
    }
    return result;
}

string in2prefix(string str) {
    reverse(str.begin(), str.end());

    for (int i = 0; i < str.size(); i++) {
        if (str[i] == '(') {
            str[i] = ')';
            i++;
        } else if (str[i] == ')') {
            str[i] = '(';
            i++;
        }
    }

    string result = in2Post(str);
    reverse(result.begin(), result.end());
    return result;
}

string pre2infix(string str) {
    stack<string> s;

    for (int i = str.size() - 1; i >= 0; i--) {
        if (isOperator(str[i])) {
            string operand1 = s.top();
            s.pop();
            string operand2 = s.top();
            s.pop();

            string temp = "(" + operand1 + str[i] + operand2 + ")";

            s.push(temp);
        } else {
            s.push(string(1, str[i]));
        }
    }
    return s.top();
}

string post2infix(string str) {
    stack<string> s;

    for (int i = 0; i <= str.size() - 1; i++) {
        if (isOperand(str[i])) {
            string tmp(1, str[i]);
            s.push(tmp);
        } else {
            string operand1 = s.top();
            s.pop();
            string operand2 = s.top();
            s.pop();
            s.push("(" + operand2 + str[i] +
                   operand1 + ")");
        }
    }

    return s.top();
}

int main() {
    cerr << boolalpha;

    cerr << in2prefix("((A+B)*t)") << endl;
    cerr << pre2infix("*+ABt") << endl;
    cerr << post2infix("AB+t*");

    return 0;
}