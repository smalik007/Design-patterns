/*
 * Description -
 *
 * @authors Suhail.m (suhailmalik19.5@gmail.com)
 * @date    2021-04-11 19:58:56
 *
 */

#pragma once
#include "PersonBuilder.hpp"

class PersonJobBuilder : public PersonBuilderBase {
  typedef PersonJobBuilder Self;

 public:
  explicit PersonJobBuilder(Person& person) : PersonBuilderBase{person} {}

  Self& at(std::string company_name) {
    person.company_ = company_name;
    return *this;
  }

  Self& as_a(std::string position) {
    person.position_ = position;
    return *this;
  }

  Self& earning(int annual_income) {
    person.income_ = annual_income;
    return *this;
  }
};