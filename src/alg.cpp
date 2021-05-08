// Copyright 2021 NNTU-CS
#include <string>
#include "tstack.h"
int priority(char ch) {
switch (ch) {
case '(': return 0;
case ')': return 1;
case '+': return 2;
case '-': return 2;
case '*': return 3;
case '/': return 3;
default: return -1;
}
}
std::string infx2pstfx(std::string inf) {
    char top = 0;
    TStack <char> stackChar;
    std::string out;
    for (int i = 0; i < inf.length() ; i++) {
        int prior;
        prior = priority(inf[i]);
        if (prior > -1) {
            if ((prior == 0 || prior > priority(top) ||
                 stackChar.isEmpty()) && inf[i] != ')') {
                if (stackChar.isEmpty())
                    top = inf[i];
                stackChar.push(inf[i]);
            } else if (inf[i] == ')') {
                while (stackChar.get() != '(') {
                    out.push_back(stackChar.get());
                    out.push_back(' ');
                    stackChar.pop();
                }
                stackChar.pop();
                if (stackChar.isEmpty())
                    top = 0;
            } else {
                while (!stackChar.isEmpty() &&
                       priority(stackChar.get()) >= prior) {
                    out.push_back(stackChar.get());
                    out.push_back(' ');
                    stackChar.pop();
                }
                if (stackChar.isEmpty())
                    top = inf[i];
                stackChar.push(inf[i]);
            }
        } else {
            out.push_back(inf[i]);
            out.push_back(' ');
        }
    }
    while (!stackChar.isEmpty()) {
        out.push_back(stackChar.get());
        out.push_back(' ');
        stackChar.pop();
    }
    out.erase(out.end() - 1, out.end());
    return out;
}
int calculator(char operate, int x, int y) {
  switch (operate) {
case '+':
return x + y;
break;
case '-':
return x - y;
break;
case '*':
return x * y;
break;
case '/':
return x / y;
break;
}
}
int eval(std::string pst) {
TStack <int> stack;
int i = 0, result = 0;
char ch = pst[i];
while (ch) {
if (ch >= '0' && ch <= '9') {
int chislo = 0;
int dec = 1;
while (ch != ' ') {
    chislo += (ch - 48) * dec;
dec *= 10;
ch = pst[++i];
}
stack.push(chislo);
} else {
char operate = ch;
i++;
int number2 = stack.get();
stack.pop();
int number1 = stack.get();
stack.pop();
int result = calculator(operate, number1, number2);
stack.push(result);
}
if (i < pst.size())
ch = pst[++i];
else
ch = 0;
}
result = stack.get();
stack.pop();
return result;
}
