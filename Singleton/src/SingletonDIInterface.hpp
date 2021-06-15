/*
 * Description -
 *
 * @authors Suhail.m (suhailmalik19.5@gmail.com)
 * @date    2021-06-15 23:41:06
 *
 */

#pragma once
#include <memory>
#include <string>

using namespace std;
using std::make_shared;
using std::make_unique;

class IFoo {
 public:
  virtual string names() = 0;
};

class Foo : public IFoo {
 public:
  static int id;
  Foo() { id++; }
  string names() override { return "foo" + to_string(id); }
};

int Foo::id = 0;

struct Bar {
  shared_ptr<Foo> foo;
};