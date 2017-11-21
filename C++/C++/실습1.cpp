
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
		string price = "1520원";
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
		price.append("원");
		return temp / this->volume;
	}
};

int main()

{
	int count = 0, input;
	cout << "당분량과 단위가격을 알고 싶은 음료를 입력하시오: ";
	cin >> input;

	Cbeverage* bev=new Cbeverage[input];

	for (int i = 0; i < input; i++)
	{
		string name, price;
		int volume;
		double sugar;


		cout << "이름 >>";
		cin >> name;

		cout << "용량 >>";
		cin >> volume;

		cout << "당분함량 >>";
		cin >> sugar;

		cout << "가격 >>";
		cin >> price;

		bev[i].setName(name);
		bev[i].setPrice(price);
		bev[i].setsugarRatio(sugar);
		bev[i].setVoume(volume);

		cout << bev[i].getName() << "의 당분량은" << bev[i].getquantityOfSugar() << "이고 단위가격은" << bev[i].getunitPrice() << "입니다" << endl;

		if (i == (input - 1))
			cout << "종료합니다";
	}
}