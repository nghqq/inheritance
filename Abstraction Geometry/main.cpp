#include<iostream>
#include<Windows.h>

class Shape 
{
public:
	virtual double get_area() const = 0;
	virtual double get_perimeter()const = 0;
	virtual void drow()const = 0;

};

class Square : public Shape 
{
	double side;
public:
	double get_side()const 
	{
		return side;
	}
 void set_side(double side)
	{
		this->side = side;
	}
 explicit Square(double side)
{
	set_side(side);
}
~Square() {}

double get_area()const override
{
	return side * side;
}
double get_perimeter()const override 
{
	return side * 4;
}

void drow()const override
{
	
	/*for (int i = 0; i < side; i++)
	{
		for (int i = 0; i < side; i++) 
		{
			std::cout << "* ";
		}
		std::cout << std::endl;
	}*/
	HWND hwnd = GetConsoleWindow();
	HDC hdc = GetDC(hwnd);

	HPEN hPen = CreatePen(PS_SOLID, 5, RGB(255, 255, 255));
	HBRUSH hBrush = CreateSolidBrush(RGB(255, 255, 255));

	SelectObject(hdc, hPen);
	SelectObject(hdc, hBrush);

	Rectangle(hdc, 100, 100, 200, 200);

	DeleteObject(hBrush);
	DeleteObject(hPen);

	ReleaseDC(hwnd, hdc);
}

};






void main() 
{
	setlocale(LC_ALL, "");

	Square square(5);
	std::cout << "Длина стороны " << square.get_side() << std::endl;
	std::cout << "Ширина стороны " << square.get_side() << std::endl;
	std::cout << "Площадь " << square.get_area() << std::endl;
	std::cout << "Периметр " << square.get_perimeter() << std::endl;
	square.drow();
	

}