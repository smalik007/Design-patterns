/*
 * Description -
 *
 * @authors Suhail.m (suhailmalik19.5@gmail.com)
 * @date    2021-06-08 10:38:09
 *
 */

#pragma once

#include "HotDrink.hpp"
using namespace std;

class HotDrinkFactory
{
public:
  virtual unique_ptr<HotDrink> make() const = 0;
};

class TeaFactory : public HotDrinkFactory
{
public:
  unique_ptr<HotDrink> make() const override { return make_unique<Tea>(); }
};

class CoffeeFactory : public HotDrinkFactory
{
public:
  unique_ptr<HotDrink> make() const override { return make_unique<Cofee>(); }
};
