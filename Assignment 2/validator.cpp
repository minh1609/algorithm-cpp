#include <fstream>
#include <iostream>
#include <stack>
#include <string>

using namespace std;

void printStack(stack<string> s) {
    while (!s.empty()) {
        string tmp = s.top();
        cout << tmp << ",";
        s.pop();
    }
    cout << endl;
}

void readFile(string filename) {
    ifstream fin;
    fin.open(filename);
    char ch;
    string str = "";
    stack<string> s;
    int line = 1;

    while (!fin.eof()) {
        ch = fin.get();

        //html tag
        if (ch == '<') {
            ch = fin.get();

            //close tag

            if (ch == '\n') {
                line++;
            }

            if (ch == '/') {
                while (ch != '>') {
                    if (isalpha(ch)) {
                        str.push_back(ch);
                    }
                    ch = fin.get();
                }
                string openTag = s.top();
                if (str.compare(openTag) == 0) {
                    str = "";
                    s.pop();
                } else {
                    cout << "error at " << str << " line:" << line << endl;
                    return;
                }

            }  //open tag
            else if (isalpha(ch)) {
                while (ch != '>') {
                    if (isalpha(ch)) {
                        str.push_back(ch);
                    }
                    ch = fin.get();
                }
                s.push(str);
                str = "";
            }
        }
    }

    fin.close();
}

int main() {
    readFile("Validhtml.txt");

    return 0;
}