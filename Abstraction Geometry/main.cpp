#include<iostream>
#include<Windows.h>

enum Color
{
	red = 0x000000FF,
	green = 0x0000FF00,
	blue = 0x00FF0000,
	yellow = 0x0000FFFF,
	purple = 0x00FF00FF,
	white = 0x00FFFFFF
public:
	Color get_color()const 
	{
		return color;
	}
	int get_start_x()const 
	{
		return start_x;
	}
	int get_start_y()const 
	{
		return start_y;
	}
	int get_line_width()const
	{
		return line_width;
	}
	void set_color(Color color) 
	{
		this->color = color;
	}
	void set_start_x(double start_x)
	{

	}
};


class Shape 
{
	static const int MIN_START_X = 10;
	static const int MAX_START_X = 800;
	static const int MIN_LINE_WIDTH = 1;
	static const int MAX_LINE_WIDTH = 30;

	Color color;
	int start_x;
	int start_y;
	int line_width;

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
  Square(double side)
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
	// 1) �������� ���� �������
	HWND hwnd = GetConsoleWindow();				// 1) �������� ���� �������
	HDC hdc = GetDC(hwnd);						// 2) �������� �������� ���������� ���  ���� ������� 

	HPEN hPen = CreatePen(PS_SOLID, 5, RGB(255, 255, 255));		// 3) ������� ��������, ������� ������ ������ ������ 
	HBRUSH hBrush = CreateSolidBrush(RGB(255, 255, 255));		// 4) ������ �����, ������� ������ ������� ������

	//5) �������� ��� � �� ��� ��������. ������ ������ �� ��������� ����������, ��� ��������� ���������� �������� � �����
	SelectObject(hdc, hPen);
	SelectObject(hdc, hBrush);
	// 6) ������ �������������. ��� ��� ��������� ����� ������� ���������� ��������-������ � �������-������� ����
	Rectangle(hdc, 100, 100, 200, 200);
	// 7) ������� ��� ��������� �����������: 
	DeleteObject(hBrush);
	DeleteObject(hPen);

	// 8) ����������� ����������� ���������� 
	ReleaseDC(hwnd, hdc);
}

};






void main() 
{
	setlocale(LC_ALL, "");

	Square square(5);
	std::cout << "����� ������� " << square.get_side() << std::endl;
	std::cout << "������ ������� " << square.get_side() << std::endl;
	std::cout << "������� " << square.get_area() << std::endl;
	std::cout << "�������� " << square.get_perimeter() << std::endl;
	square.drow();
	

}