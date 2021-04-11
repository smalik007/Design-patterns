/*
 * Description -
 *
 * @authors Suhail.m (suhailmalik19.5@gmail.com)
 * @date    2021-04-11 19:40:52
 *
 */

#pragma once

#include <iostream>
#include <string>

using namespace std;

// fwd Declared
class PersonBuilder;

class Person {
  string address_, postcode_, city_;
  string company_, position_;
  double income_ = 0;

  Person() { cout << "Person Created \n"; }

 public:
  ~Person() { std::cout << "Person destroyed\n"; }

  static PersonBuilder create();

  Person(Person&& other)
      : address_{move(other.address_)}, postcode_{move(other.postcode_)}, city_{move(other.city_)}, company_{move(other.company_)}, position_{move(other.position_)}, income_{other.income_} {}

  Person& operator=(Person&& other) {
    if (this == &other) return *this;
    address_ = move(other.address_);
    postcode_ = move(other.postcode_);
    city_ = move(other.city_);
    company_ = move(other.company_);
    position_ = move(other.position_);
    income_ = other.income_;
    return *this;
  }

  friend std::ostream& operator<<(std::ostream& os, const Person& obj) {
    return os << "street_address: " << obj.address_ << " post_code: " << obj.postcode_ << " city: " << obj.city_ << " company_name: " << obj.company_ << " position: " << obj.position_
              << " annual_income: " << obj.income_;
  }

  friend class PersonBuilder;
  friend class PersonAddressBuilder;
  friend class PersonJobBuilder;
};
