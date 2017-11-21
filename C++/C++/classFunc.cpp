#include "class.h"

float student::getAvg()
{
	return this->getTotal / 3;
}

float student::getTotal()
{
	return this->eng + this->kor + this->math;
}

void student::setData()
