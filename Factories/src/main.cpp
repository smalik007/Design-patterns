/*
 * Description -
 *
 * @authors Suhail.m (suhailmalik19.5@gmail.com)
 * @date    2021-06-08 09:20:08
 *
 */

/* Factories : A component solely for wholesale (not piecewise like in Builder pattern) creation of object. can be outsourced to*/

#include <iostream>

#include "DrinkFactory.hpp"
#include "FactoryPoint.hpp"

using namespace std;

void testFactoryPoint()
{
  //   auto p = Point::newPolar(5, M_PI_4);
  //   cout << p << endl;
  //   auto p2 = Point::newCartesian(2, 3);
  //   cout << p2 << endl;

  auto p = Point::PointFactory::newPolar(5, M_PI_4);
  cout << p << endl;
  auto p2 = Point::PointFactory::newCartesian(2, 3);
  cout << p2 << endl;
}

void testAbstractFactory()
{
  DrinkFactory df;
  auto c = df.make_drink("coffee", 50);
  auto t = df.make_drink("tea", 200);
}

int main()
{
  testFactoryPoint();
  testAbstractFactory();
  return 0;
}