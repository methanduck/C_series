#include <iostream>
#include <vector>
#include <string>

using namespace std;


class book
{
private:
	string strName;
public:
	book(string input)
	{
		this->strName = input;
	}
	string getName()
	{
		return this->strName;
	}
};

class mall
{
private:
	string strName;

public:
	mall(string input)
	{
		this->strName = input;
	}
	string getName()
	{
		return this->strName;
	}
};

class bookset
{
private:
	book *bo;
	mall *ma;

public:
	bookset(book *b, mall *m)
	{
		this->bo = b;
		this->ma = m;
	}
	book* getBook()
	{
		return this->bo;
	}
	mall* getMall()
	{
		return this->ma;
	}
};

int main()
{
	vector <bookset> sex;
	book *input1;
	mall *input2;
	bookset *temp;
	string bookinfo, temp1;
	int count = 0;

	while (true)
	{
		getline(cin, temp1, '\n');
		if (temp1.compare("±×¸¸"))
			break;
		temp1 + '\n';
		bookinfo.append(temp1);
		count++;
	}
	string split[10];
	string split2[2];
	for (int i = 0; i <count; i++)
		getline(bookinfo, split[i], '\n');

	for (int j = 0; j < count; j++)
	{
		getline(split[j], split2[j], " ");
		input1 = new book(split2[0]);
		input2 = new mall(split2[1]);
		temp = new bookset(input1, input2);
		sex.push_back(*temp);
	}
	for (int k = 0; k < count; k++)
	{
		
	}


	for (int i = 0; i<sex.size(); i++)
	{
		temp = &sex.at(i);
		cout << temp->getBook()->getName() << temp->getMall()->getName() << endl;

	}
}













