#include <iostream>

using namespace std;

template <class T>
class stack
{
public:
	stack()
	{
		size = 0;
	};
	void add(T input)
	{
		if (this->size == 10)
			return;
		this->stk[size] = input;
		size++;
	}
	T pop()
	{
		if (this->size == 0)
			return NULL;
		size--;
		return this->stk[size];
	}
private:
	int size;
	T stk[10];
};

int main()
{
	stack <int> my;

	my.add(10);
	cout << my.pop();
}
