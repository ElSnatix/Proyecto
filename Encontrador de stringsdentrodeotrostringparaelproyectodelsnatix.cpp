/*
PROYECTO FINAL
Programa: Calculadora Romana
Autores: Santiago Guarguati y David Santiago lópez
*/
#include <iostream>
#include <locale.h>
#include <string.h>
#include <string>
#include <algorithm>
#include <iterator>
#include <cmath>
#define MAX 10

using std::cout; using std::endl;
using std::cin;
using std::string; using std::reverse;

int main ()
{
  string str ="XXXXXIXXXXXXXXXXXXXXXXXXXXXXX";
  string str2 ="XXXXXXXX";

  // different member versions of find in the same order as above:
  cout << str.find(str2);

  return 0;
}
