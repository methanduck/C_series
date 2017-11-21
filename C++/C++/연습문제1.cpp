#include <iostream>
#include <array>
#include<cstdlib>

using namespace std;

char& find(char in[], char in2, bool& in3)
{
	int length;
	length = strlen(in);

	/*for (int i = 0; i < length; i++)
	{
		if (in[i] == in2)
			return in[i];
	}*/
}

int main()
{
	
	char s[] = "mike";
	bool b = false;
	char& loc = find(s, 'm', b);
	if (b == false)
	{
		cout << "m ¾øÀ½";
		return 0;
	}
	loc = 'M';
	cout << s << endl;

	int n = 10;
	

}