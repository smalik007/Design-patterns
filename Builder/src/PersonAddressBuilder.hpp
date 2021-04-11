/*
 * Description -
 *
 * @authors Suhail.m (suhailmalik19.5@gmail.com)
 * @date    2021-04-11 19:56:33
 *
 */

#pragma once
#include <string>

#include "PersonBuilder.hpp"

class PersonAddressBuilder : public PersonBuilderBase {
  typedef PersonAddressBuilder Self;

 public:
  explicit PersonAddressBuilder(Person& person) : PersonBuilderBase{person} {}

  Self& at(std::string street_address) {
    person.address_ = street_address;
    return *this;
  }

  Self& with_postcode(std::string post_code) {
    person.postcode_ = post_code;
    return *this;
  }

  Self& in(std::string city) {
    person.city_ = city;
    return *this;
  }
};