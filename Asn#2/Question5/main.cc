#include <iostream>
#include "Balanced.h"
#include <string>

void displayHelp();

int main()
{
    std::string s;
    std::string expression;

    std::cout<<"Welcome to balance expression program" <<std::endl;

  do{
    std::cout<<"Enter any key to continue or type 'Help' to display a help menu ";
    std::cout<<"You may also type 'Exit' to exit the program: ";

    std::cin>>s;

    if(s=="Help")
    {
      displayHelp();
      continue;
    }

    else if(s=="Exit")
    {
      break;
    }

    else{
    std::cout<<"Enter an expression: ";
    std::cin>>expression;
    }
    Balanced d(expression);


    if(d.isBalanced()!=true){
      std::cout<<"The expression is not balanced";
      std::cout<<std::endl;
    }

    else{
      std::cout<<"The expression is balanced";
      std::cout<<std::endl;
    }

    }while(s!="Exit");

    return 0;

}

void displayHelp()
{
  std::cout<<std::endl;
  std::cout<<"The purpose of this program is to check ";
  std::cout<<"if an expression is balanced ";
  std::cout<<"You will enter an expression and it will check to see if there is closing ";
  std::cout<<"brackets. If the expression is balanced, then it will return true if not ";
  std::cout<<"then the program will return false ";
  std::cout<<"You can enter as many expression as you like. If you like to exit the program, ";
  std::cout<<"type 'Exit'"<<std::endl;
  std::cout<<std::endl;
}
