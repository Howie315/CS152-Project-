#include <string>
#include<stdio.h>
#include<string>
#include<vector>
#include<string.h>

struct CodeNode {
  std::string code;
  std::string name;
};

struct ExpNode {
  std::string code;
  std::string name;
  int side; //0:Left 1:Right
};