#include <iostream>

using	namespace std;

class BookRecord
{
private:
	char *strTitle;
	int iQuantity;
	char * strAuthor;
public:
	BookRecord()
	{
		strTitle=NULL;
		strAuthor=NULL;
		iQuantity=0;
	};
	~BookRecord() {};
	char *getstrTitle()
	{
		return this->strTitle;
	}
	char *getstrAuthor()
	{
		return this->strAuthor;
	}
	int getiQuantity ()
	{
		return this->iQuantity;
	}
	void set(char * input, char*input2, int quantity)
	{
		this->strTitle = input;
		this->strAuthor = input2;
		this->iQuantity = quantity;
	}

};

class BookRecordSet
{
public:
	BookRecordSet()
	{
		si = new BookRecord[10];
		index = 0;
		last = 0;
		count = 0;
	};
	BookRecordSet(int max)
	{
		si = new BookRecord[max];
		index = 0;
		last = 0;
		count = 0;
	}
	void appendstudentdinfo(BookRecord* input)
	{
		si[last].set(input->getstrTitle(),input->getstrAuthor(),input->getiQuantity());
		last++;
	}
	void indexset(int input)
	{
		index = input;
	}
	bool hasnext()
	{
		if (index < last)
			return true;
		else
			return false;
	}
	BookRecord next()
	{
		BookRecord temp;
		temp = si[index];
		return temp;
	}

	~BookRecordSet()
	{
		delete si;
	};

private:
	BookRecord * si;
	int index, last, count;
};

int main()
{
	BookRecord *br = nullptr;
	BookRecordSet *brs = new BookRecordSet();
	char * strTitle=NULL;
	char * strAuthor=nullptr;
	int quantity;
	bool Flag = true;

	while (Flag)
	{
		int menu=0;
		cout << "1. 책 입력" << endl;
		cout<<"2. 책 검색" << endl;
		cout<<"3. 종료" << endl;
		cout << " 입력 :";
			cin >> menu;


			switch (menu)
			{
			default:
				cout << "다시 입력하세요";
					continue;

			case 1:
				cout << "책 제목을 입력하세요";
				cin.getline;
				cout << "책 저자를 입력하세요";
				cin >> *strAuthor;
				cout << "책 수량을 입력하세요";
				cin >> quantity;

				br->set(strTitle,strAuthor,quantity);
				brs->appendstudentdinfo(br);
				break;

			case 2:
				cout << "책 제목을 입력하세요 :";
					cin >> *strTitle;
					brs->indexset(0);
					while (brs->hasnext())
					{
						BookRecord temp;
						temp = brs->next();
						if (strcmp(strTitle,temp.getstrTitle()))
						{
							cout << "찾는 자료가 없습니다.";
							continue;
						}
						else
						{
							cout << "제목 : " << temp.getstrTitle();
							cout << "저자 : " << temp.getstrAuthor();
							cout << "수량 : " << temp.getiQuantity();
							break;
						}
						
					}
					break;

			case 3:
				cout << "종료합니다." << endl;
				Flag = false;
				break;
			}
	}

}