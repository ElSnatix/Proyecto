#include <iostream>
#include <algorithm>
#include <iterator>
#include <locale.h>
#include <string.h>
#include <string>

using std::cout; using std::endl;
using std::cin;
using std::string; using std::reverse;

string &ReverseString();

int main() {

    cout << ReverseString() << endl;

    return EXIT_SUCCESS;
}

string &ReverseString() {
	string s;
	cin>>s;
    reverse(s.begin(), s.end());
    return s;
}
