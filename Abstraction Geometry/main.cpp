#include<iostream>
#include<Windows.h>

			//enum  (Enumeration - ������������) ��� ����� ������������ ������������� ��������
enum Color
{
	red		=	0x000000FF,
	green	=	0x0000FF00,
	blue	=	0x00FF0000,
	yellow	=	0x0000FFFF,
	purple	=	0x00FF00FF,
	white	=	0x00FFFFFF
};
#define SHAPE_TAKE_PARAMETERS Color color, int start_x, int start_y, int line_width
#define SHAPE_GIVE_PARAMETERS  color,  start_x, start_y,  line_width
class Shape 
{
	static const int MIN_START_X = 10;
	static const int MAX_START_X = 800;

	static const int MIN_START_Y = 10;
	static const int MAX_START_Y = 500;

	static const int MIN_LINE_WIDTH = 1;
	static const int MAX_LINE_WIDTH = 30;
protected:
	Color color;
	int start_x;
	int start_y;
	int line_width;

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
	int get_line_widt()const 
	{
		return line_width;
	}
	void set_color(Color color) 
	{
		this->color = color;
	}
	void set_start_x(int start_x) 
	{
		if (start_x < MIN_START_X)start_x = MIN_START_X;
		if (start_x > MAX_START_X)start_x = MAX_START_X;
		this->start_x = start_x;
	}
	void set_start_y(int start_y)
	{
		if (start_y < MIN_START_X)start_y = MIN_START_Y;
		if (start_y > MAX_START_X)start_y = MAX_START_Y;
		this->start_y = start_y;
	}
	void set_line_width(int line_width) 
	{
		if (line_width < MIN_LINE_WIDTH)line_width = MIN_LINE_WIDTH;
		if (line_width > MAX_LINE_WIDTH)line_width = MAX_LINE_WIDTH;
		this->line_width = line_width;
	}
	virtual double get_area() const = 0;
	virtual double get_perimeter()const = 0;
	virtual void draw()const = 0;
			//Constuctors
	Shape(SHAPE_TAKE_PARAMETERS) :color(color) 
	{
		set_start_x(start_x);
		set_start_y(start_y);
		set_line_width(line_width);
	}
	~Shape(){}
			//Methods

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
		//Constructors

	Square(double side, SHAPE_TAKE_PARAMETERS):Shape(SHAPE_GIVE_PARAMETERS)
	{
		set_side(side);
	}
	~Square(){}

				//Methods
	void info()const
	{
		std::cout << "������� ��������: " << side << std::endl;
		std::cout << "�������� ��������: " << get_perimeter() << std::endl;
		std::cout << "������� ��������: " << get_area() << std::endl;
		std::cout << std::endl;

	}

		//Clear Virtual Methods			

	double get_area()const override 
	{
		return side * side;
	}
	double get_perimeter()const override 
	{
		return side * 4;
	}
	void draw()const override 
	{
		/*for (int i = 0; i < side; i++)
		{
			for (int j = 0; j < side; j++) 
			{
				std::cout << "* ";
			}
			std::cout << std::endl;
		}*/
		HWND hwnd = GetConsoleWindow(); // 1) �������� ���� ������� 
		HDC hdc = GetDC(hwnd);			// 2) �������� �������� ���������� ��� ���� �������

		HPEN hPen = CreatePen(PS_SOLID, line_width, color);   //3) ������� ��������, ������� ������ ������ ������
		HBRUSH hBrush = CreateSolidBrush(color);	  //4) ������� �����, ������� ������ ������� ������
		//5) ��������, ��� � �� ��� ��������. ������ ������ �� ��������� ���������� ��� ��������� ���������� �������� � ����� 
		SelectObject(hdc, hPen);
		SelectObject(hdc, hBrush);

		//6) ������ �������������. ��� ��� ��������� ����� ������� ��� ���������� ��������-������ ���� � �������-������� ����
		Rectangle(hdc, start_x, start_y, start_x+side, start_y+side);

		 //7) ������� ��� ��������� �����������: 
		DeleteObject(hBrush);
		DeleteObject(hPen);

		//8) ������������ �������� ���������� 
		ReleaseDC(hwnd, hdc);

		// ��������� ���������� � ��� ����������� �������� �������, � ������� ����� �����������.
	}
	
};

#define RECTANGLE_TAKE_PARAMETERS double side_a, double side_b
#define RECTANGLE_GIVE_PARAMETERS  side_a,  side_b
class Rectangle :public Shape 
{
	double side_a;
	double side_b;
public:
	double get_side_a()const 
	{
		return side_a;
	}
	double get_side_b()const
	{
		return side_b;
	}
	void set_side_a(double side_a) 
	{
		this->side_a = side_a;
	}
	void set_side_b(double side_b)
	{
		this->side_b = side_b;
	}
	double get_area()const override 
	{
		return side_a * side_b;
	}
	double get_perimeter()const override 
	{
		return (side_a + side_b) * 2;
	}

	void draw()const override
	{
		HWND hwnd = GetConsoleWindow();
		HDC hdc = GetDC(hwnd);

		HPEN hPen = CreatePen(PS_SOLID, line_width, color);
		HBRUSH hBrush = CreateSolidBrush(color);


		SelectObject(hdc, hPen);
		SelectObject(hdc, hBrush);

		::Rectangle(hdc, start_x, start_y, start_x + side_a, start_y + side_b);

		DeleteObject(hPen);
		DeleteObject(hBrush);

		ReleaseDC(hwnd, hdc);
	}
	

	Rectangle(RECTANGLE_TAKE_PARAMETERS, SHAPE_TAKE_PARAMETERS): Shape (SHAPE_GIVE_PARAMETERS)
	{
		set_color(color);
		set_start_x(start_x);
		set_start_y(start_y);
		set_side_a(side_a);
		set_side_b(side_b);
	} 
	~Rectangle(){}

						//Methods

	void info()const
	{
		std::cout << "������� �������������� a: " << get_side_a() << std::endl;
		std::cout << "������� �������������� b: " << get_side_b() << std::endl;
		std::cout << "�������� ��������������: " << get_perimeter() << std::endl;
		std::cout << "������� ��������������: " << get_area() << std::endl;
		std::cout << std::endl;

	}

	
};

class Circle :public Shape 
{
	
	double radius;

public:
	
	double get_radius()const
	{
		return radius;
	}
	void set_radius(double radius)
	{
		this->radius = radius;
	}

	//Constructors
	
	Circle(double radius, SHAPE_TAKE_PARAMETERS) :Shape(SHAPE_GIVE_PARAMETERS) 
	{
		set_color(color);
		set_start_x(start_x);
		set_start_y(start_y);
		set_radius(radius);
	}

	//Destructor
	~Circle(){}

	//Methods

	void info()const
	{
		std::cout << "�������� ���������� : " << radius*2 << std::endl;
		std::cout << "������ ����������: " << get_radius() << std::endl;
		std::cout << "����� ����������: " << get_perimeter() << std::endl;
		std::cout << "������� ����������: " << get_area() << std::endl;
		std::cout << std::endl;

	}
	double diameter(double radius) 
	{
		return radius * 2;
	}

			//Clear Virtual Methods
		//Clear Virtual Methods			

	double get_area()const override
	{
		return 3.14 * (radius * radius);
	}
	double get_perimeter()const override
	{
		return sqrt((get_area() * 4) * 3.14);
	}
	void draw()const override
	{
		HWND hwnd = GetConsoleWindow();
		HDC hdc = GetDC(hwnd);

		HPEN hPen = CreatePen(PS_SOLID, line_width, color);
		HBRUSH hBrush = CreateSolidBrush(color);


		SelectObject(hdc, hPen);
		SelectObject(hdc, hBrush);

		Ellipse(hdc, start_x, start_y, start_x + radius, start_y + radius);

		DeleteObject(hPen);
		DeleteObject(hBrush);

		ReleaseDC(hwnd, hdc);
	}


};

void main() 
{
	setlocale(LC_ALL, "");

	Square square(250,Color::red,100,300,5);
	//std::cout << "������ �������: " << square.get_side() << std::endl;
	//std::cout << "��������: " << square.get_perimeter() << std::endl;
	//std::cout << "�������: " << square.get_area() << std::endl;
	//std::cout << std::endl;
	square.info();
	square.draw();
	
	class Rectangle rect(250, 350, Color::blue, 500, 300, 5);  //x  , y ������, ����, ������������ �� ������
	//std::cout << "������� a : " << rect.get_side_a() << std::endl;
	//std::cout << "������� b: " << rect.get_side_b() << std::endl;
	//std::cout << "��������: " << rect.get_perimeter() << std::endl;
	//std::cout << "�������: " << rect.get_area() << std::endl;
	rect.info();
	rect.draw();

	Circle circle(250, Color::white, 800, 300, 5);
	circle.info();
	circle.draw();

}