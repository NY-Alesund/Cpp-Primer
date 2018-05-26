/*************************************************************************
	> File Name: 15-22.h
	> Author: amoscykl
	> Mail: amoscykl@163.com 
	> Created Time: 2018年04月21日 星期六 17时21分19秒
 ************************************************************************/

using namespace std;
class Figure {
	public:
		Figure(double,double);
	protected:
		double xSize,ySize;					//图元的尺寸
};

class Figure_2D : public Figure {
	public:
		Figure_2D(double,double);
		virtual double area() = 0;			//求面积操作:纯虚函数
		virtual double pcrimeter() = 0;		//求周长操作:纯虚函数
};

class Figure_3D : public Figure {
	public:
		Figure_3D(double,double,double);
		virtual double cubage() = 0;
	protected:
		double zSize;
};

class Rectangle : public Figure_2D {
	public:
		Rectangle(double,double);
		virtual double area();
		virtual double perimeter();
};

class Circle : public Figure_2D {
	public:
		Circle (double,double);
		virtual double area();
		virtual double perimeter();
};

class Sphere :public Figure_3D {
	public:
		Sphere(double,double,double);
		virtual double cubage();
};

class Cone : public Figure_3D {
	public:
		Cone(double,double,double);
		virtual double cubage();
}
