/*
 * Description -
 *
 * @authors Suhail.m (suhailmalik19.5@gmail.com)
 * @date    2021-04-11 19:57:34
 *
 */

#pragma once
#include "Person.hpp"

class PersonAddressBuilder;
class PersonJobBuilder;

class PersonBuilderBase {
 protected:
  Person& person;
  explicit PersonBuilderBase(Person& person) : person{person} {}

 public:
  operator Person() const { return std::move(person); }

  // builder facets

  PersonAddressBuilder lives() const;
  PersonJobBuilder works() const;
};

class PersonBuilder : public PersonBuilderBase {
  Person p;

 public:
  PersonBuilder() : PersonBuilderBase{p} {}
};