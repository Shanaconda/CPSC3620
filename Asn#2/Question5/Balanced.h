#ifndef BALANCED_H
#define BALANCED_H

#include<string>


class Balanced {
  public:
    Balanced(std::string);
    bool isBalanced();
    bool isMatch(char c, char d);

  private:
    std::string expression;
};

#endif // BALANCED_H
