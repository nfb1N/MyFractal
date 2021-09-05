

#include<SFML/Graphics.hpp>
#include<iostream>
#include<complex>

using namespace sf;

class Complex //класс комплексных чисел, необходимый для расчетов
{
private:
	double r, i;
public:
	Complex(double r, double i)
	{
		this->r = r; this->i = i;
	}
	Complex operator+(const Complex& c)
	{
		return Complex(r + c.r, i + c.i);
	}
	Complex operator*(const Complex& c)
	{
		return Complex(r * c.r - i * c.i, 2 * r * c.i);
	}
	double abs() { return r * r + i * i; }
};

int main()
{

	const int LENTH = 1200;
	const int WIDTH = 800;
	RenderWindow window(VideoMode(LENTH, WIDTH), "FRACTAL NIKITOSA!");
	double koefOfZoom = 100;//KOEFICIENT OF ZOOM


	Vertex point;
	double x, y;
	while (window.isOpen())
	{


		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}

		window.clear();
		for (int y = 0; y < WIDTH; y++) {
			for (int x = 0; x < LENTH; x++)
			{
				int iterator = 0;
				Complex z(0, 0);
				while (iterator < 500 && z.abs() < 16) {
					z = z * z + Complex((x - (LENTH / 2 + koefOfZoom * 1.25)) / (180.0 + koefOfZoom), (y - WIDTH / 2) / (180.0 + koefOfZoom));
					iterator++;
				}
				double r = (iterator) % 225;
				double g = (iterator * 5) % 225;
				double b = (iterator * 2) % 225;
				point = Vertex(Vector2f(x, y));
				point.color = Color(r, g, b, 225);
				window.draw(&point, 1, Points);
			}

		}
		window.display();
		std::cout << "koef: " << koefOfZoom << "\n";
		//koef_X += 100.0; CHANGING THE ZOOM------------
	}
}

