
#include <iostream>
#include <string>

using namespace std;

class Cbeverage

{
private:
	string name, price;
	int volume;
	double sugarRatio;

public:
	Cbeverage()
	{
		string name = "coke";
		string price = "1520��";
		int volume = 350;
		double sugarRatio = 9.9;
	}

	void setName(string name) { this->name = name; }
	void setPrice(string price){this->price = price;}
	void setVoume(int volume) { this->volume = volume; }
	void setsugarRatio(double ratio) { this->sugarRatio = ratio; }
	string getName() { return this->name; }
	string getPrice() { return this->price; }
	int getVolume() { return this->volume; }
	double getsugarRatio() { return this->sugarRatio; }
	double getquantityOfSugar() { return this->volume*(sugarRatio / 100); }
	double getunitPrice()
	{
		double temp;
		int locate;
		
		this->price.pop_back();
		locate = this->price.find(",");
		price.erase(locate, 1);
		temp = std::stoi(this->price, nullptr, 0);
		price.append("��");
		return temp / this->volume;
	}
};

int main()

{
	int count = 0, input;
	cout << "��з��� ���������� �˰� ���� ���Ḧ �Է��Ͻÿ�: ";
	cin >> input;

	Cbeverage* bev=new Cbeverage[input];

	for (int i = 0; i < input; i++)
	{
		string name, price;
		int volume;
		double sugar;


		cout << "�̸� >>";
		cin >> name;

		cout << "�뷮 >>";
		cin >> volume;

		cout << "����Է� >>";
		cin >> sugar;

		cout << "���� >>";
		cin >> price;

		bev[i].setName(name);
		bev[i].setPrice(price);
		bev[i].setsugarRatio(sugar);
		bev[i].setVoume(volume);

		cout << bev[i].getName() << "�� ��з���" << bev[i].getquantityOfSugar() << "�̰� ����������" << bev[i].getunitPrice() << "�Դϴ�" << endl;

		if (i == (input - 1))
			cout << "�����մϴ�";
	}
}