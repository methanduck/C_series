#include <iostream>
#include <string>
#define MAX 10
using namespace std;

class Book
{
public:
	Book()
	{
		strTitle = 'NULL';
		strAuthor = 'NULL';
		iQuantity = 0;
	};
	void set(string title, string author, int qunatity)
	{
		strTitle = title;
		this->strAuthor = author;
		this->iQuantity = qunatity;
	}
	string getTitle()
	{
		return this->strTitle;
	}
	string getAuthor()
	{
		return this->strAuthor;
	}
	int getquantity()
	{
		return this->iQuantity;
	}
	~Book() 
	{	};

private:
	string strTitle;
	string strAuthor;
	int iQuantity;
};

class BookSet
{
private:
	Book * bookset=nullptr;
	int index, last, max;
public:
	BookSet()
	{
		bookset = new Book[5];
		max = 5;
		last = 0;
	};
	BookSet(int input)
	{
		bookset = new Book[input];
		max = input;
		last = 0;
	};

	void append(Book * input)
	{
		if (last < max)
			bookset[last].set(input->getTitle(), input->getAuthor(), input->getquantity());
		last++;
	};
	Book * getNextBook()
	{
		Book * temp = new Book();
		temp = &bookset[index];
		index++;
		return temp;
	};
	void setIndex(int input)
	{
		this->index = input;
	}
	bool isNext()
	{
		if (index < last)
			return true;
		else
			return false;
	}

	~BookSet() {};


};

int main()
{
	BookSet * bs = new BookSet();
	Book * b = new Book();
	bool Flag = true;
	string title, author;
	int quantity;

	while (Flag)
	{
		int menu = 0;
		cout << "1. 책 입력" << endl;
		cout << "2. 책 검색" << endl;
		cout << "3. 종료" << endl;
		cout << " 입력 :";
		cin >> menu;

		switch (menu)
		{
					default:
						Flag = false;
						break;


					case 1:
					{
						cout << ">>";
						cin >> title;
						cout << ">>";
						cin >> author;
						cout << ">>";
						cin >> quantity;

						b->set(title, author, quantity);
						bs->append(b);
						break;
					}

					case 2:
					{
						cout << ">>";
						cin >> title;
						bs->setIndex(0);
						while (bs->isNext())
						{

							
							b = bs->getNextBook();
							if (title.compare(b->getTitle())==0)
							{
								cout << b->getAuthor()<<endl;
								cout << b->getTitle()<<endl;
								cout << b->getquantity()<<endl;
							}

						}
					}
					case 3:
						Flag = false;
		}
	}
}