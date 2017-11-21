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
		cout << "1. å �Է�" << endl;
		cout<<"2. å �˻�" << endl;
		cout<<"3. ����" << endl;
		cout << " �Է� :";
			cin >> menu;


			switch (menu)
			{
			default:
				cout << "�ٽ� �Է��ϼ���";
					continue;

			case 1:
				cout << "å ������ �Է��ϼ���";
				cin.getline;
				cout << "å ���ڸ� �Է��ϼ���";
				cin >> *strAuthor;
				cout << "å ������ �Է��ϼ���";
				cin >> quantity;

				br->set(strTitle,strAuthor,quantity);
				brs->appendstudentdinfo(br);
				break;

			case 2:
				cout << "å ������ �Է��ϼ��� :";
					cin >> *strTitle;
					brs->indexset(0);
					while (brs->hasnext())
					{
						BookRecord temp;
						temp = brs->next();
						if (strcmp(strTitle,temp.getstrTitle()))
						{
							cout << "ã�� �ڷᰡ �����ϴ�.";
							continue;
						}
						else
						{
							cout << "���� : " << temp.getstrTitle();
							cout << "���� : " << temp.getstrAuthor();
							cout << "���� : " << temp.getiQuantity();
							break;
						}
						
					}
					break;

			case 3:
				cout << "�����մϴ�." << endl;
				Flag = false;
				break;
			}
	}

}