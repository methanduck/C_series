#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;



class Mall
{
public:
	Mall() {};
	Mall(string name, string num)
	{
		this->mallName = name;
		this->rolledNum = num;
	}
	void setMallname(string name)
	{
		this->mallName = name;
	};
	void setRolledNum(string num)
	{
		this->rolledNum = num;
	};
	string getMallname()
	{
		return this->mallName;
	};
	string getRollednum()
	{
		return this->rolledNum;
	};

private:
	string mallName;
	string rolledNum;
};

class Book
{
public:
	Book() {};
	Book(string name, int isbn, int price, int release)
	{
		this->Bookname = name;
		this->ISBN = isbn;
		this->price = price;
		this->Release = release;
	};
	

	int getPrice()
	{
		return this->price;
	};
	int getISBN()
	{
		return this->ISBN;
	};

	int getRelease()
	{
		return this->Release;
	};

	string getBookname()
	{
		return this->Bookname;
	};



	void setBookname(string name)
	{
		this->Bookname = name;
	};

	void setISBN(int isbn)
	{
		this->ISBN = isbn;
	};

	void setPrice(int price)
	{
		this->price = price;
	};

	void setRelease(int release)
	{
		this->Release = release;
	};

private:
	string Bookname;
	int ISBN;
	int price;
	int Release;
};

class BookPrice

{

public:
	BookPrice() {};
	BookPrice(Book *book, Mall *mall)
	{
		this->data.setPrice(book->getPrice());
		this->data.setISBN(book->getISBN());
		this->data.setRelease(book->getRelease());
		this->data.setBookname(book->getBookname());
		this->data2.setMallname(mall->getMallname());
		this->data2.setRolledNum(mall->getRollednum());
	}

	bool operator < (BookPrice input)
	{
		return this->data.getPrice() < input.data.getPrice();
	}

	Book data;
	Mall data2;
};

int main()
{
	Book *book;
	Mall *mall;
	vector<BookPrice> Data;
	BookPrice *temp;
	vector<string> input;
	string inputTemp;
	string split[6];
	string::size_type sz;
	//cout << "책의 수량을 입력하세요 >> ";
	//cin >> in;


	while (true)
	{
		while (true)
		{
			cout << "책의 정보를 입력하세요" << endl;
			getline(cin, inputTemp, '\n');
			if (inputTemp == "그만")
			{
				break;
			}
			else
				input.push_back(inputTemp);
		}
		for (int i = 0; i < input.size(); i++)
		{
			istringstream read(input.back());
			input.pop_back();
			for (int i = 0; i < 6; i++)
			{
				getline(read, split[i], ' ');
			}
			book = new Book(split[0], stoi(split[1], &sz), stoi(split[2], &sz), stoi(split[3], &sz));
			mall = new Mall(split[4], split[5]);
		}


		temp = new BookPrice(book, mall);
		Data.push_back(*temp);

	}

	sort(Data.begin(), Data.end());

	for (int i = 0; i < Data.size(); i++)
	{
		cout << Data.at(i).data.getPrice() << endl;
		cout << Data.at(i).data.getRelease() << endl;
	}

}
