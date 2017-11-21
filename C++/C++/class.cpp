#include <iostream>
#include <string>
using namespace std;
 class student
 {
 private:
	 string name;
	 int hakbun;
	 float eng, kor, math;
	
 public:
	 student()
	 {
		 name = "NULL";
		 hakbun = 0;
		 eng = 0;
		 kor = 0;
		 math = 0;
	 }
	 void setData(string name, int hakbun, float eng, float kor, float math)
	 {
		 this->name = name;
		 this->hakbun = hakbun;
		 this->kor = kor;
		 this->math = math;
		 this->eng = eng;
	 }
	 float getTotal()
	 {
		 return this->kor + this->eng + this->math;
	 }
	 float getAvg()
	 {
		 return getTotal() / 3;
	 }
	 void printData()
	 {
		 cout << this->name << "\t" << this->hakbun << "\t" << this->kor << "\t" << this->eng << "\t" << this->math;
		 cout << fixed;
		 cout.precision(2);
		 cout << this->getAvg << "\t" << this->getTotal;
	 }
 };

int main()
{

}