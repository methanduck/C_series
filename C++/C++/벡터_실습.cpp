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
		this->data = *book;
		this->data2 = *mall;
	};

    void set(Book *book, Mall *mall)
	{
		this->data = *book;
		this->data2 = *mall;
	};

	bool operator < (BookPrice input)
	{
		return this->data.getPrice() < input.data.getPrice();
	}

	Book data;
	Mall data2;
};

int main()
{
	Book *book = new Book();
	Mall *mall = new Mall();
	vector<BookPrice> Data;
	BookPrice *temp = new BookPrice();
	vector<string> input;
	string inputTemp;
	string split[6];
	string::size_type sz;

		while (true)
		{
			cout << "책의 정보를 입력하세요" << endl;
			getline(cin, inputTemp, '\n');
			if (inputTemp.compare("그만") == 0)
			{
				break;
			}
			else
				input.push_back(inputTemp);
		}
		for (int i = 0; i <= input.size(); i++)
		{
			istringstream read(input.back());
			input.pop_back();
			for (int i = 0; i < 6; i++)
			{
				getline(read, split[i], ' ');
			}
			book->setBookname(split[0]);
			book->setISBN(stoi(split[1], &sz));
			split[2].pop_back();
			int find = -1;
				find =split[2].find(',');
			if(find !=-1)
			split[2].erase(find,find-1);
			split[2].append("원");
			book->setPrice(stoi(split[2], &sz));
			book->setRelease(stoi(split[3], &sz));
			mall->setMallname(split[4]);
			mall->setRolledNum(split[5]);
			temp->set(book,mall);
			Data.push_back(*temp);
		}

	if (Data.size() > 0)
	{
		sort(Data.begin(), Data.end());
		for (int i = 0; i < Data.size(); i++)
		{
			cout << Data.at(i).data.getBookname()<< "\t"<<Data.at(i).data.getISBN() << "\t" << Data.at(i).data.getPrice() << "\t" << Data.at(i).data.getRelease() << "\t" << Data.at(i).data2.getMallname() << endl;
		}
	}


	
}
