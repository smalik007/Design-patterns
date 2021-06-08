/*
 * Description -
 *
 * @authors Suhail.m (suhailmalik19.5@gmail.com)
 * @date    2021-06-08 10:34:23
 *
 */

#pragma once

#include <iostream>
#include <memory>

using namespace std;

struct HotDrink {
  virtual ~HotDrink() = default;
  virtual void prepare(int vol) = 0;
};

struct Tea : HotDrink {
  void prepare(int vol) override { cout << "Add Tea bag, Boil Water, pour " << vol << " ml, add Lemon, Enjoy your Tea\n"; }
};

struct Cofee : HotDrink {
  void prepare(int vol) override { cout << "Grind beans, Boil Water pour " << vol << " ml, add Some Cream, Enjoy your Coffee\n"; }
};
