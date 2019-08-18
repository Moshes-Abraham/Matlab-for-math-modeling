#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
	string s{"I love you!"};
	string s2{"Black holes"};
	vector<string> v;
	v.push_back(s);
	v.push_back(s2);
	string a;
	a = v[0];
}
