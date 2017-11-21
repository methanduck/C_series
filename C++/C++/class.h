#pragma once
#include <string>
#include <iostream>
using namespace std;

class student
{
private:
 string name;
	int hakbun;

	student();
	float eng, kor, math;
	float getTotal();
	float getAvg();
	void printData();
	void setData(string name,);

};