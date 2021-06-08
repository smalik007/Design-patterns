/*
 * Description -
 *
 * @authors Suhail.m (suhailmalik19.5@gmail.com)
 * @date    2021-06-08 10:44:04
 *
 */

#pragma once

#include <unordered_map>

#include "HotDrink.hpp"
#include "HotDrinkFactory.hpp"

using namespace std;

class DrinkFactory {
 private:
  unordered_map<string, unique_ptr<HotDrinkFactory>> drinks_map;

 public:
  DrinkFactory() {
    drinks_map["coffee"] = make_unique<CoffeeFactory>();
    drinks_map["Coffee"] = make_unique<CoffeeFactory>();
    drinks_map["tea"] = make_unique<TeaFactory>();
    drinks_map["Tea"] = make_unique<TeaFactory>();
  }

  unique_ptr<HotDrink> make_drink(const string& drink_name, int vol) {
    auto d = drinks_map[drink_name]->make();
    d->prepare(vol);
    return d;
  }
};