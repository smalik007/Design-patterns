#pragma once

#include <iostream>
#include <memory>
#include <string>
using namespace std;

/* Motivation behind Prototype patterns */
/* To take existing design as prototype and either shallow copy it or deep copy it to make new design wih
  additional changes etc.
 */

struct Address {
  string street, city;
  int appartment_no;

  Address(const string& street, const string& city, int appartment_no) : street(street), city(city), appartment_no(appartment_no) {}

  friend ostream& operator<<(ostream& os, const Address& add) {
    os << add.street << " " << add.city << " " << add.appartment_no << " ";
    return os;
  }
};

struct Contact {
  string name;
  Address add;

  Contact(const string& name, const Address& add) : name(name), add(add) {}

  friend ostream& operator<<(ostream& os, const Contact& con) {
    os << con.name << " " << con.add << " ";
    return os;
  }
};

/* This time lets make Address defined as pointer */
class Employee {
 public:
  string name_;
  Address* add_;

  Employee() = default;

  Employee(const string& name, Address* add) : name_(name), add_(add) {}

  /* You need to define a copy constructor, that will create a deep copy */
  //   Employee(const Employee& other) : name_(other.name_), add_(new Address{other.add_->street, other.add_->city, other.add_->appartment_no}) {}

  /* Alternatively */
  Employee(const Employee& other) : name_(other.name_), add_(new Address{*other.add_}) { cout << "Calling Employee copy constructor \n"; }

  /* Similarly you can override the = operator */
  void operator=(const Employee& other) {
    cout << "Calling = operator \n";
    add_ = new Address{*other.add_};

  }

  friend ostream& operator<<(ostream& os, const Employee& emp) {
    os << emp.name_ << " " << *emp.add_ << " ";
    return os;
  }

  /* Free memory */
  ~Employee() {
    if (add_ != nullptr) {
      delete add_;
    }
  }
};

/* Now let say you want to Have a Prototype that user does not have to define, you can create a Factory for the same keeping the prototype in it and only allow the this Factory object to create the
 * object for you, In this way you are actually hiding the constructor from a user and only letting a factory create API exposed to the user */
class EmployeeFactory {
 public:
  static unique_ptr<Employee> createEmployee(const string& name, const int& appartment_no) {
    Employee p{"", new Address{"124 Mall road", "Delhi", 123}};
    auto emp = newEmployee(name, appartment_no, p);
    return emp;
  }

 private:
  static unique_ptr<Employee> newEmployee(const string& name, const int& appartment_no, const Employee& prototype) {
    auto emp = make_unique<Employee>(prototype); /*  Calls copy constructor of Employee*/
    emp->name_ = name;
    emp->add_->appartment_no = appartment_no;
    return emp;
  }
};