#include <iostream>

using namespace std;

class Shape
{
protected:
	int x,y;
public:
	Shape()
	{
	};
	Shape(int x, int y)
	{
		this->x = x;
		this->y = y;
	};
	virtual double area() =0;
	virtual double surface() = 0;
	virtual void print()
	{
		cout << "(" << this->x << "," << this->y << "),A=" << area() << ",S = "<<surface() <<endl;
	}
	~Shape(){};

private:

};
class Rect: public Shape

{
private:
	double width,height;
public:
	Rect(int width, int height,int x, int y):Shape(x,y)
	{
		this->width=width;
		this->height=height;
	}
	virtual double area()
	{
		return this->height*this->width;
	}
	virtual double surface()
	{
		return (this->height+this->width)*2;
	}
	virtual void print()
	{
		cout << "Rect : width ="<<this->width<<", Height = "<<this->height<<endl;
		Shape::print();
	};
	double getwidth()
	{
		return this->width;
	}
	double getheight()
	{
		return this->height;
	}
	int getx()
	{
		return this->x;
			
	}
	int gety()
	{
		return this->y;
	}

	~Rect(){};

private:

};
class Circle : public Shape
{
private:
		double radius;
public:
	Circle(int radius,int x,int y ):Shape(x,y)
	{
		this->radius = radius;
	};

	virtual double area()
	{
		return 3.14*radius*radius;
	};
	virtual double surface()
	{
		return 2*3.14*radius;
	};
	virtual void print()
	{
		cout << "Circle : R ="<<this->radius<<endl;
		Shape::print();
	};
	
	
	double getradius()
	{
		return this->radius;
	}
	int getx()
	{
		return this->x;
			
	}
	int gety()
	{
		return this->y;
	}
~Circle(){};
};

int main()
{
	Rect *r =new Rect(10,10,20,20);
	Circle *c = new Circle(20,20,10);
	r->print();
	c->print();
}
