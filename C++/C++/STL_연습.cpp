#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
	//vector <string> test;
	//test.push_back("1,500¿ø");

	 string calc(string input,int input2);
	string temp = calc("1,500¿ø",1500);
	cout << temp << endl;

}

string calc(string input,int input2)
{	
	
	int count = 0;
	string output;

	input.pop_back();
	string::iterator it = input.begin();

	while (it != input.end())
	{
		if (*it == ',')
			input.erase(it);
		it++;
	}

	int result = stoi(input);
	result += input2;
	output = to_string(result);

	it = output.end();
	while (it != output.begin())
	{
		if (count == 0)
			count++;
		else if (count % 3 == 0)
		{
			output.insert(it, ',');
			count++;
		}
		else
			count++;
		it--;
	}
	return output.append("¿ø");
}