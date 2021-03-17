/*
 * Description -
 *
 * @authors Suhail.m (suhailmalik19.5@gmail.com)
 * @date    2021-03-17 14:59:10
 *
 */

#pragma once

#include <iostream>
#include <string>
#include <vector>

using namespace std;

/* Specification */
enum class Color { red, green, blue };
enum class Size { small, medium, large };

struct Product {
  string _name;
  Color _color;
  Size _size;
};

class ProductFilter {
 public:
  vector<Product*> byColor(vector<Product*> items, Color color) {
    vector<Product*> result;
    for (auto& i : items) {
      if (i->_color == color) result.push_back(i);
    }
    return result;
  }

  /* Problem with this filter method is it is not open for extension, So if let say now we want to filder by Size we need to add one more member here */

  /* This is wrong way of design */
  vector<Product*> bySize(vector<Product*> items, Size size) {
    vector<Product*> result;
    for (auto& i : items) {
      if (i->_size == size) result.push_back(i);
    }
    return result;
  }

  /* Now if we want a combinational filter which can filter using both color, size */
  /* One problem/Overhead As the specification of product increases, we will have lot of combination, which is not that scalable  */
  vector<Product*> byColorAndSize(vector<Product*> items, Color color, Size size) {
    vector<Product*> result;
    for (auto& i : items) {
      if (i->_size == size && i->_color == color) result.push_back(i);
    }
    return result;
  }
};

/* Now using Concept of Open-Closed Principle, lets design a Better Filter  */

/* we need to first define interfaces in terms of abstract classes*/

template <class T>
class Specification {
 public:
  /* will check if a item satisfy particular specification */
  virtual bool isSatisfied(T* item) = 0;
};

/* generic filter */
template <class T>
class Filter {
 public:
  /* filter method takes the list(vector) of T items and filter it with corresponding specs, return the list of filtered items */
  virtual vector<T*> filter(vector<T*> items, Specification<T>& specs) = 0;
};

/* Now we will inherit these Abstacted classes and implement the overrided virtual methods */

/* Here we are defining that we want to Filter on Products */
class BetterFilter : Filter<Product> {
 public:
  vector<Product*> filter(const vector<Product*> items, Specification<Product>& specs) override {
    vector<Product*> result;
    for (auto& i : items) {
      if (specs.isSatisfied(i)) result.push_back(i);
    }
    return result;
  }
};

class ColorSpecification : public Specification<Product> {
  Color _color;

 public:
  ColorSpecification() = delete;
  explicit ColorSpecification(const Color& color) : _color(color) {}
  bool isSatisfied(Product* item) override { return item->_color == _color; };
};

class SizeSpecification : public Specification<Product> {
  Size _size;

 public:
  SizeSpecification() = delete;
  explicit SizeSpecification(const Size& size) : _size(size) {}
  bool isSatisfied(Product* item) override { return item->_size == _size; };
};
