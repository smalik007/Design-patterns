/*
 * Description -
 *
 * @authors Suhail.m (suhailmalik19.5@gmail.com)
 * @date    2021-06-08 09:26:28
 *
 */
#pragma once

#include <cmath>
#include <iostream>

using namespace std;

enum class PointType
{
  Cartesian,
  Polar
};

class Point1
{
public:
  /* Let say we have a class where we want to construct for a point, point could be in cartesian format or Polar, So in that situation you might want to have two constructor */
  Point1(float x, float y) : _x(x), _y(y) {}

  /* Problem here is that you can't have two difft constructor with same type and same no of argument (here both float), which programatically incorrect */
  /* Point(float rho, float theta) {
        _x = rho * cos(theta);
        _y = rho * sin(theta);
      }
  */

  /* One way arround then is as follows, Here you need to put ugly if/else clause and more importantly a,b argument does not make any sense here, where they are points in unit or angle in degree
  Ofcourse  you can put arround some documentation, but still it is an ugly way of designing it. And this where the Factory Object comes into Picture.*/
  Point1(float a, float b, PointType type = PointType::Cartesian)
  {
    if (PointType::Cartesian == type)
    {
      _x = a;
      _y = b;
    }
    else
    {
      _x = a * cos(b);
      _y = a * sin(b);
    }
  }

private:
  float _x, _y;
};

/* Now Using Factory pattern */
class Point
{
private:
  float _x, _y;

  /* The Constructor is need to be made private */
  Point(float x, float y) : _x(x), _y(y) {}

public:
  // static Point newCartesian(float x, float y) {
  //   /* Same as -> return Point(x, y) : Here the static memeber call the actucal constructor and returns the object created */
  //   return {x, y};
  // }

  // static Point newPolar(float r, float theta) {
  //   /* Same as -> return Point (r* cos(theta), r*sin(theta)) */
  //   return {(r * cos(theta)), (r * sin(theta))};
  // }

  friend ostream &operator<<(ostream &os, const Point &point)
  {
    os << "x: " << point._x << " y: " << point._y;
    return os;
  }

  /* Adding Separate of Concern with Factory class */
  // Inner class can access the private member (e.g here Private Point constructor)
  // you can also make this private and give a singleton object exposed as public member to outside world
  // private:
  class PointFactory
  {
  public:
    static Point newCartesian(float x, float y)
    {
      /* Same as -> return Point(x, y) : Here the static memeber call the actucal constructor and returns the object created */
      return {x, y}; // This translate to return Point(x,y) : modern c++ infered the type of return from the return type of function
    }

    static Point newPolar(float r, float theta)
    {
      /* Same as -> return Point (r* cos(theta), r*sin(theta)) */
      return {(r * cos(theta)), (r * sin(theta))};
    }
  };

  // public: 
  //   static PointFactory factory; // singleton object of class PointFactory when you make it private to access it
};
