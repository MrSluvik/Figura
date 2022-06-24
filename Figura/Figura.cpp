//Написать программу на C++, которая демонстрирует класс "Фигура" и определить разные фигуры.
#include <iostream>
#include <Windows.h>
#include <cmath>
using namespace std;

class Figure
{
protected:
    virtual double area()= 0;//чистот віртуальні ф-н площі
    virtual void show() = 0;//чистот віртуальні ф-н для друку назви фігури
    ~Figure() {};
};

class Square : public Figure //квадрат
{
private:
    double Side;
public:
    Square(double Side)//конструктор з параметрами
    {
        this->Side = Side;
    }

    double area()override//площа квадрата
    {
        return Side * Side;
    }
    double diagonal() //метод знаходження діагоналі квадрата 
    {
        return Side * sqrt(2);
    }

    void show()override
    {
        cout << "\t**Квадрат**\n " << endl; 
    }

    ~Square() {}//деструктор
};

class Triangle : public Figure//клас трикутник
{
protected:
    double AB, BC, AC;//сторони трикутника
    double Mediana;//медіана
    double Height;//висота 
    double p, Perimetr, Square;//півпериметр і периметр і площа
public:
    Triangle() {}//конструктор безпараметрів 

    Triangle(double AB, double BC, double AC) {//конструктор
        this->AB = AB;
        this->BC = BC;
        this->AC = AC;
    }

    double Mediana() {
        Mediana = (sqrt(2 * pow(AB, 2) + 2 * pow(BC, 2) - pow(AC, 2))) / 2;//знаходим медіау
        return Mediana;
    }

    double Height() {
        p = (AB + BC + AC) / 2;//знаходим півпериметр для подальших формул
       this-> Height = 2 / AC * (sqrt(p * (p - AB) * (p - BC) * (p - AC)));//заходмо висоту проведену до сторони АС
        return Height;
    }

    double perimetr() {//переопреділяєм перемтр для трикутника
        Perimetr = AB + BC + AC;
        return Perimetr;
    }

    double area() override {//переопреділяєм площу для трикутника
        Square = (AB * Height)/2;
        return  Square;
    }

    void show()override
    {
        cout << "\t**Трикутник**\n " << endl;
    }
    ~Triangle() {};

};

class TriangleEquilateral: public Triangle
{
public:  

    TriangleEquilateral() {}

    bool equilateral() {//метод для перевірки чи трикутник різносторонній
        if ((this->AB == this->BC) and (this->AB == this->AC) and (this->BC == this->AC)) {
           return true;          
        }      
    }

    void printType() 
    {
        cout << "рівносторонній" << endl;
    }

};

class Circle : public Figure //круг
{
private:
    double radius;//радіус круга

public:
    Circle(double radius)
    {
        this->radius = radius;
    }   

    double area() override//площа круга
    {
        return 3.14 * pow(radius, 2);
    }

    double diametr()//diametr круга
    {
        return radius * 2;
    }

    void show() override 
    {
        cout << "\t**Круг**\n" << endl; 
    }

    ~Circle() {}
};
class Rectangl : public Figure  //прямокутник
{
private:
    double Sideone, Sidetwo;//сторони прямокутника

public:
    Rectangl(double Sideone, double Sidetwo)
    {
        this->Sideone = Sideone;
        this->Sidetwo = Sidetwo;
    }   

    double area() override//площа прямокутника
    { 
        return Sideone * Sidetwo;
    }
    double perimetr() //метод знаходження периметра прямокутника
    {
        return Sideone * 2+ Sidetwo *2;
    }

    void show() override
    { 
        cout << "\t**Прямокутник**\n " << endl;
    }

    ~Rectangl() {}
};

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Square a(3);
    a.show();
    cout << "Площа квадрата = " << a.area() << endl;
    cout << "Діагональ квадрата = " << a.diagonal() << endl << endl;

    Triangle first(2, 2, 2);
    TriangleEquilateral i;

    first.show();
    if (i.equilateral() == 1) {
        i.printType();
    }
    else {cout << "Невідомого типу ...." << endl;}
 
  
    cout << "Периметр  трикутника = " << first.perimetr() << endl << endl;
    cout << "Висота  трикутника = " << first.Height() << endl << endl;
    cout << "Медіана  трикутника = " << first.Mediana() << endl << endl;
    cout << "Площа трикутника = " << first.area() << endl<<endl;
    
    Circle b(5);
    b.show();
    cout << "Площа круга = " << b.area() << endl;
    cout << "Діаметр круга  = " << b.diametr() << endl << endl;

    Rectangl d(2.6 , 3.5);
    d.show();
    cout << "Площа прямокутника = " << d.area() << endl;
    cout << "Периметр прямокутника = " << d.perimetr() << endl << endl;
   
   return 0;
}
