#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class person
{
public:
	person(){};

	void setName(string name)
	{
		this->name = name;
	}
	string getName()
	{
		return this->name;
	}
	void del(char c)
	{
		for (int i = 0; i < this->name.length(); i++)
		{
			if (name[i] == c)
				name[i] = ' ';
		}
	}
	void del()
	{
		for (int a = 0; a < this->name.length(); a++)
		{
			if (name[a] == ' ')
				this->name.erase(a, 1);
		}
		
	}

	person operator % (person input);
	person operator * (int input);
	~person(){};

private:
	string name;
	bool	check;
};
person person::operator* (int input)
{
	person temp;
	temp.setName(this->name);
	for (int i = 0; i < input; i++)
	{
		temp.name.push_back('|');
		temp.name.append(this->name);
	}
	return temp;
}

person person::operator% (person input)
{
	person temp;
	string inputstring;
	const char*a;
	const char*b;
	int count = 0;
	inputstring = input.getName();
	if (inputstring.length() < name.length())
	{
		temp.setName(name);
		for (int i = 0; i < (signed)inputstring.length(); i++)
		{
			b = new char[inputstring.at(i)];
			for (int j = 0; j < (signed)name.length(); j++)
			{
				a = new char[name.at(j)];
				
				if (strncmp(a, b, 0) == 0)
				{
					temp.del(inputstring.at(i));
				}
			}
		}
		temp.del();
	}
	else
	{
		temp.setName(inputstring);
		for (int i = 0; i < (signed)name.length(); i++)
		{
			b = new char[name.at(i)];
			for (int j = 0; j < (signed)inputstring.length(); j++)
			{
				a = new char[inputstring.at(j)];
				
				if (strncmp(a, b, 0) == 0)
				{
					temp.del(name.at(i));
				}
			}
		}
		temp.del();

	}

	return temp;

};



int main()

{
	person p1, p2, p3;
	p1.setName("Hyoungho");
	p2.setName("Hyoho");
	cout << p1.getName() << endl;
	cout << p2.getName() << endl;

	p3 = p1%p2;
	
	cout << p3.getName();
	cout << endl;
	p3=p1*3;
	cout<<p3.getName();

	return 0;
}