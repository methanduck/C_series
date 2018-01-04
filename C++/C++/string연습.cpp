#include <iostream>
#include <vector>
#include <string>
#include <typeinfo>
using namespace std;


int main()
{
	vector <string> price;
	string input; 
	for (int i = 0; i < 3; i++)
	{
		getline(cin, input, '\n');
		price.push_back(input);
	};
	
}

int calc(string input)
{
	input.pop_back();
	string::iterator it = input.begin();
	while (it.operator++ != )
	{

	}
	if (*it == ',')
	{
		input.replace(it, it - 1, "");
	}
}