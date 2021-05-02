// Copyright 2021 NNTU-CS
#include <string>
#include "tstack.h"
int priority(char a) {
  if (a == '(')
    return 0;
  if (a == ')')
    return 1;
  if ((a == '+') || (a == '-'))
    return 2;
  if ((a == '*') || (a == '/'))
    return 3;
}
std::string infx2pstfx(std::string inf) {
  // добавьте сюда нужный код
  return std::string("");
  char head = 0;
  TStack <char> stack1;
  std::string str;
  for (int i = 0; i < inf.length(); i++) {
    int prioritize = priority(inf[i]);
    if (prioritize > -1) {
      if ((prioritize == 0 || prioritize > priority(head) ||
           stack1.isEmpty()) && inf[i] != ')') {
        if (stack1.isEmpty())
          head = inf[i];
        stack1.push(inf[i]);
      }
      else if (inf[i] == ')') {
        while (stack1.get() != '(') {
        str.push_back(stack1.get());
        str.push_back(' ');
        stack1.pop();
      }
      stack1.pop();
      if (stack1.isEmpty())
        head = 0;
      }
      else {
        while (!stack1.isEmpty() &&
               priority(stack1.get()) >= prioritize) {
          str.push_back(stack1.get());
          str.push_back(' ');
          stack1.pop();
        }
        if (stack1.isEmpty())
          head = inf[i];
        stack1.push(inf[i]);
      }
    }
    else {
      str.push_back(inf[i]);
      str.push_back(' ');
    }
  }
  while (!stack1.isEmpty()) {
    str.push_back(stack1.get());
    str.push_back(' ');
    stack1.pop();
  }
  str.erase(str.end() - 1, str.end());
  return str;
}
int calculator(char ptr_a, int x, int y) {
  if (ptr_a == '+')
    return x + y;
  if (ptr_a == '-')
    return x - y;
  if (ptr_a == '*')
    return x * y;
  if (ptr_a == '/')
    return x / y;
}
int eval(std::string pst) {
  // добавьте сюда нужный код
  return 0;
  TStack <int> stack2;
  int result, i = 0;
  char ch = pst[i];
  while (ch) {
    if (ch >= '0' && ch <= '9') {
      int number = 0;
      int dec = 1;
      while (ch != ' ') {
        number += (ch - 48) * dec;
        dec *= 10;
        ch = pst[++i];
        }
      stack2.push(number);
      }
    else {
      char operate = ch;
      i++;
      int num2 = stack2.get();
      stack2.pop();
      int num1 = stack2.get();
      stack2.pop();
      int result = calculator(operate, num1, num2);
      stack2.push(result);
      }
    if (i < pst.size())
      ch = pst[++i];
    else
      ch = 0;
    }
  result = stack2.get();
  stack2.pop();
  return result;
}
