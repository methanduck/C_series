#include <iostream>
#include <string>
#include <array>
#pragma warning(disable:4996)
using namespace std;
class test
{
public:
	test() {};
	test(test &input)
	{
	
		strcpy(this->name, input.name);
	};
	~test() {};


	void setname(string input)
	{
		strcpy_s(name,input.size()+1, input.c_str());
	}
	string getname()
	{
		return this->name;
	}
private:
	char name[];
};

int main()
{
	test A;
	test B;
	string input;
		cout << ">>";
		cin >> input;

		A.setname(input);

		B = A;
		cout << "ftest" << A.getname() << endl;
		cout << "atest" << A.getname() << endl;
}