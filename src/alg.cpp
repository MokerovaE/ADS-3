// Copyright 2021 NNTU-CS
#include <string>
#include "tstack.h"

std::string infx2pstfx(std::string inf) {
  // добавьте сюда нужный код
  return std::string("");
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
}
int eval(std::string pst) {
  // добавьте сюда нужный код
  return 0;
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
  std::string infx2pstfx(std::string inf) {
    char head = 0;
    TStack <char> stack1;
    std::string str;
    for (int i = 0; i < inf.length(); i++) {
      int prioritize = priority(inf[i]);
      if (prioritize > -1) || prioritize > priority(head) ||
        stack1.isEmpty()) && inf[i] != ')') {
        if (stack1.isEmpty())
          head = inf[i];
        stack1.push(inf[i]);
      }
      else if (inf[i] == ')') {
        str.push_back(stack1.get());
        str.push_back(' ');
        stack1.pop();
      }
      stack1.pop();
      if (stack1.isEmpty())
        head = 0;
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
int eval(std::string pst) {
  TStack <int> stack2;
  int result;
  for (int i = 0; i < pst.size(); i++) {
    char ch = pst[i];
    int prioritize = priority(ch);
    if (prioritize == -1)
      stack2.push(ch - 48);
    else {
      int num1 = stack2.get();
      stack2.pop();
      int num2 = stack2.get();
      stack2.pop();
      result = calculator(ch, num2, num1);
      stack2.push(res);
    }
  }
  return stack2.get();
  
