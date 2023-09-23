#define _USE_MATH_DEFINES
#include<iostream>
#include<Windows.h>

#define delimiter "\n_____________________\n"

			//enum  (Enumeration - Перечисление) это набор нумерованных целочисленных констант
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
protected:

	static const int MIN_START_X = 10;
	static const int MAX_START_X = 800;

	static const int MIN_START_Y = 10;
	static const int MAX_START_Y = 500;

	static const int MIN_LINE_WIDTH = 1;
	static const int MAX_LINE_WIDTH = 30;

	static const int MIN_DEMENSION = 25;
	static const int MAX_DEMENSION = 500;

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
	void draw()const 
	{

	}
			//Constuctors
	Shape(SHAPE_TAKE_PARAMETERS) :color(color) 
	{
		set_start_x(start_x);
		set_start_y(start_y);
		set_line_width(line_width);
	}
	~Shape(){}
			//Methods

	void info()const
	{
		
		std::cout << "Периметр фигуры: " << get_perimeter() << std::endl;
		std::cout << "Площадь фигуры: " << get_area() << std::endl;
		draw();

	}

};
//#define Square_DONE
#ifdef Square_DONE
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

	Square(double side, SHAPE_TAKE_PARAMETERS) :Shape(SHAPE_GIVE_PARAMETERS)
	{
		set_side(side);
	}
	~Square() {}

	//Methods
	void info()const
	{
		std::cout << "Длина стороны:" << get_side() << std::endl;
		Shape::info();
		std::cout << typeid(*this).name() << std::endl;
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
		HWND hwnd = GetConsoleWindow(); // 1) Получаем окно консоли 
		HDC hdc = GetDC(hwnd);			// 2) Получаем контекст устройства для окна консоли

		HPEN hPen = CreatePen(PS_SOLID, line_width, color);   //3) Создаем карандаш, который рисует контур фигуры
		HBRUSH hBrush = CreateSolidBrush(color);	  //4) Создаем кисть, которая рисует заливку фигуры
		//5) Выбираем, чем и на чём рисовать. Рисуют всегда на контексте устройства для рисования используем карандаш и кисть 
		SelectObject(hdc, hPen);
		SelectObject(hdc, hBrush);

		//6) Рисуем прямоугольник. Для его рисования нужно указать его координаты верхнего-левого угла и правого-нижнего угла
		Rectangle(hdc, start_x, start_y, start_x+side, start_y+side);

		 //7) Удаляем все созданные инструменты: 
		DeleteObject(hBrush);
		DeleteObject(hPen);

		//8) Осовобождаем контекст устройства 
		ReleaseDC(hwnd, hdc);

		// Констекст устройства и все инструменты занимают ресурсы, а ресурсы нужно освобождать.
	}
	
	

};
#endif // Square_DONE

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
		if (side_a < MIN_DEMENSION)side_a = MIN_DEMENSION;
		if (side_a > MAX_DEMENSION)side_a = MAX_DEMENSION;
		this->side_a = side_a;
	}
	void set_side_b(double side_b)
	{
		if (side_b < MIN_DEMENSION)side_b = MIN_DEMENSION;
		if (side_b > MAX_DEMENSION)side_b = MAX_DEMENSION;
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
	double get_diagonal() const 
	{
		return sqrt(side_a * side_a + side_b * side_b);
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
		std::cout << "Сторона a: " << get_side_a() << std::endl;
		std::cout << "Сторона b: " << get_side_b() << std::endl;
		std::cout << "Диагональ: " << get_diagonal() << std::endl;
		Shape::info();
		std::cout << typeid(*this).name() << std::endl;
		
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
		if (radius < MIN_DEMENSION) radius = MIN_DEMENSION;
		if (radius > MAX_DEMENSION) radius = MAX_DEMENSION;
		this->radius = radius;
	}
	

	//Constructors
	
	Circle(double radius, SHAPE_TAKE_PARAMETERS) :Shape(SHAPE_GIVE_PARAMETERS) 
	{
		//set_color(color);
		//set_start_x(start_x);
		//set_start_y(start_y);
		set_radius(radius);
	}

	//Destructor
	~Circle(){}

	//Methods

	void info()const
	{
		std::cout << "Диаметер окружности : " << get_diameter() << std::endl;
		std::cout << "Радиус окружности: " << get_radius() << std::endl;
		Shape::info();
		std::cout << typeid(*this).name() << std::endl;
		

	}
	double get_diameter()const
	{
		return radius * 2;
	}

			//Clear Virtual Methods		

	double get_area()const override
	{
		return M_PI * pow(radius,2);
	}
	double get_perimeter()const override
	{
		return sqrt((get_area() * 4) * M_PI);
	}
	void draw()const override
	{
		HWND hwnd = GetConsoleWindow();
		HDC hdc = GetDC(hwnd);

		HPEN hPen = CreatePen(PS_SOLID, line_width, color);
		HBRUSH hBrush = CreateSolidBrush(color);


		SelectObject(hdc, hPen);
		SelectObject(hdc, hBrush);

		Ellipse(hdc, start_x, start_y, start_x + get_diameter(), start_y + get_diameter());

		DeleteObject(hPen);
		DeleteObject(hBrush);

		ReleaseDC(hwnd, hdc);
	}


};
class Square:public Rectangle 
{
public:
	Square(double side, SHAPE_TAKE_PARAMETERS): Rectangle(side,side,SHAPE_GIVE_PARAMETERS){}
	~Square(){}
};

class Triangle :public Shape
{
public:
	virtual double get_height() const = 0;
	Triangle(SHAPE_TAKE_PARAMETERS):Shape(SHAPE_GIVE_PARAMETERS){}
	~Triangle(){}
	
	void info()const 
	{
		std::cout << "Высота треугольника: " << get_height() << std::endl;
		Shape::info();
	}
};
class EquilateralTriangle: public Triangle 
{
	double side;

public:
	double get_side()const 
	{
		return side;
	}
	void set_side(double side) 
	{
		if (side < MIN_DEMENSION)side = MIN_DEMENSION;
		if (side > MAX_DEMENSION)side = MAX_DEMENSION;
		this->side = side;
	}
	double get_height() const override
	{
		return sqrt(pow(side, 2) - pow(side / 2, 2));
	}
	double get_area()const override 
	{
		return pow(get_height(), 2) * sqrt(3);
	}
	double get_perimeter()const override 
	{
		return side * 3;
	}
	void draw() const override 
	{
		HWND hwnd = GetConsoleWindow();
		HDC hdc = GetDC(hwnd);

		HPEN hPen = CreatePen(PS_SOLID, line_width, color);
		HBRUSH hBrush = CreateSolidBrush(color);


		SelectObject(hdc, hPen);
		SelectObject(hdc, hBrush);

		POINT vertex[] =
		{
			{start_x,start_y + side},
			{start_x + side,start_y + side},
			{start_x + side / 2,start_y+side-get_height()}
		};
		::Polygon(hdc, vertex, 3);

		DeleteObject(hPen);
		DeleteObject(hBrush);

		ReleaseDC(hwnd, hdc);
	}
	EquilateralTriangle(double side, SHAPE_TAKE_PARAMETERS) :Triangle(SHAPE_GIVE_PARAMETERS)
	{
		set_side(side);
	}
	~EquilateralTriangle(){}

	void info()const 
	{
		std::cout << typeid(*this).name() << std::endl;
		std::cout << "Длина стороны: " << side << std::endl;
		Triangle::info();
	}
};

class RightTriangle : public Triangle
{
	double cat_1;
	double cat_2;

public:
	double get_cat_1()const 
	{
		return cat_1;
	}
	void set_cat_1(double cat_1)
	{
		if (cat_1 < MIN_DEMENSION)cat_1 = MIN_DEMENSION;
		if (cat_1 > MAX_DEMENSION)cat_1 = MAX_DEMENSION;
		this->cat_1 = cat_1;
	}
	double get_cat_2()const
	{
		return cat_2;
	}
	void set_cat_2(double cat_2) 
	{
		if (cat_2 < MIN_DEMENSION)cat_2 = MIN_DEMENSION;
		if (cat_2 > MAX_DEMENSION)cat_2 = MAX_DEMENSION;
		this->cat_2 = cat_2;
	}
	double get_hypotenuse()const 
	{
		return sqrt(pow(cat_1, 2) + pow(cat_2, 2));
	}
	double get_height()const override 
	{
		return (cat_1 * cat_2) / get_hypotenuse();
	}
	double get_area()const override
	{
		return (cat_1 * cat_2) / 2;
	}
	double get_perimeter()const override
	{
		return cat_1 + cat_2 + get_hypotenuse();
	}
	void draw() const override
	{
		HWND hwnd = GetConsoleWindow();
		HDC hdc = GetDC(hwnd);

		HPEN hPen = CreatePen(PS_SOLID, line_width, color);
		HBRUSH hBrush = CreateSolidBrush(color);


		SelectObject(hdc, hPen);
		SelectObject(hdc, hBrush);

		POINT vertex[] =
		{
			{start_x,start_y + cat_1},
			{start_x + cat_2,start_y + cat_2},
			{start_x + cat_1 / 2,start_y + cat_1 - get_height()}
			
		
		};
		::Polygon(hdc, vertex, 3);

		DeleteObject(hPen);
		DeleteObject(hBrush);

		ReleaseDC(hwnd, hdc);
	}

		//Constructor

	RightTriangle(double cat_1, double cat_2, SHAPE_TAKE_PARAMETERS) : Triangle(SHAPE_GIVE_PARAMETERS)
		{
		set_cat_1(cat_1);
		set_cat_2(cat_2);
		}
	~RightTriangle(){}

	void info()const
	{
		std::cout << typeid(*this).name() << std::endl;
		std::cout << "Длина катета 1 : " << cat_1 << std::endl;
		std::cout << "Длина катета 2 : " << cat_2 << std::endl;
		std::cout << "Гипотинуза : " << get_hypotenuse() << std::endl;
		Triangle::info();
	}


};

void main() 
{
	setlocale(LC_ALL, "");
 
	Square square(150,Color::red,300,10,5);
	//std::cout << "Длинна стороны: " << square.get_side() << std::endl;
	//std::cout << "Периметр: " << square.get_perimeter() << std::endl;
	//std::cout << "Площадь: " << square.get_area() << std::endl;
	//std::cout << std::endl;
	square.info();
	std::cout << delimiter << std::endl;
	
	
	
	class Rectangle rect(150, 200, Color::blue, 700, 10, 5);  //x  , y Размер, цвет, расположение на экране
	//std::cout << "Сторона a : " << rect.get_side_a() << std::endl;
	//std::cout << "Сторона b: " << rect.get_side_b() << std::endl;
	//std::cout << "Периметр: " << rect.get_perimeter() << std::endl;
	//std::cout << "Площадь: " << rect.get_area() << std::endl;
	rect.info();
	std::cout << delimiter << std::endl;
	
	

	Circle circle(75, Color::white, 300, 170, 5);
	circle.info();
	std::cout << delimiter << std::endl;
	
	EquilateralTriangle et(150, Color::green, 500, 170, 15);
	et.info();
	std::cout << delimiter << std::endl;
	
	RightTriangle rt(100, 75, Color::red, 800, 170, 5);
	rt.info();
	std::cout << delimiter << std::endl;

}