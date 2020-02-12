#include "Balanced.h"
#include <string>
#include<iostream>
#include <stack>

Balanced::Balanced(std::string s) : expression(s)
{
}

bool Balanced::isBalanced()
{
   
   std::stack<char> b;

  for(unsigned int i=0; i < expression.size(); i++)
  {
    if(expression[i]=='{'|| expression[i] == '[' || expression[i] == '(')
      {
        b.push(expression[i]);
        continue;
      }

    else if(expression[i] == '}' || expression[i] == ']' || expression[i] == ')')
    {
      if(b.empty() || !isMatch(b.top(), expression[i]))
         {
           return false;
         }

      else{ b.pop();}
    }
  }
  return b.empty();
}

bool Balanced::isMatch(char c, char d)
{
  if(c == '{' && d == '}')
    {
      return true;
    }
  else if(c == '[' && d == ']')
  {
      return true;
  }

  else if(c == '(' && d == ')')
  {
      return true;
  }

  else
  {
    return false;
  }
}
