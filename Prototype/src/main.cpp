/* Prototype : A partially or fully initialized object that you copy(clone) and make use of it*/

/* When it is easier to copy an existing object to fully initialize  a new one */
/* We make a copy (clone) the prototype and customize it */

#include <iostream>

#include "RecordKeeping.hpp"

using namespace std;

void testRecordKeeping() {
  cout << endl;
  /* Suppose John and Tanya Lives in same builinding but have difft appartments
  One way to create the object is to copy the whole line of code  */
  Contact John{"John", Address{"123 Model town", "Delhi", 1102}};
  //   Contact Tanya{"Tanya", Address{"123 Model town", "Delhi", 1104}};
  //   cout << John << endl << Tanya << endl;

  /* Other way is to just copy the object of John, and change only the required feild */
  Contact Tanya = John;
  Tanya.name = "Tanya";
  Tanya.add.appartment_no = 1104;
  cout << John << endl << Tanya << endl;

  /* Above approach is fine till the time there's no pointer type member in the fields, Let say If I define  Address as Pointer in Contact structure, the problem arises
  As now copying the object would copy the original pointer address to the new object created, and any modification done by New object will also reflect on the original
  object. This is where prototype Design patterns comes into picture.*/
}

void testPrototypePattern() {
  cout << endl;
  /* Here Amir will act as a prototype */
  Employee Amir{"Amir", new Address{"543 Hauz khas", "Delhi", 1205}};

  Employee Aisha{Amir}; /* This will call the copy-constructor of Employee and create a deep copy, where Address will also be allocated in memory seprately for Aisha */
  Aisha.name_ = "Aisha";
  Aisha.add_->appartment_no = 1208;

  Employee Rohan = Amir; /* This again calls copy constructor. */
  Rohan.name_ = "Rohan"; 
  Rohan.add_->appartment_no = 1210;
  
  /* Remeber the assignment operator is called when already constructed objects are equatest to each other. */ 
  Employee Faisal;
  Faisal = Amir; // This time the assingment operator will be called
  Faisal.name_ = "Faisal";
  Faisal.add_->appartment_no = 1215;

  cout << Amir << endl << Aisha << endl << Rohan  << endl << Faisal << endl;
}

void testPrototypeFactory() {
  cout << endl;
  /* Here it uses Factory API, which keeps the implementation clean and easy to use */
  auto John = EmployeeFactory::createEmployee("John", 1406);
  auto Priya = EmployeeFactory::createEmployee("Priya", 1605);
  cout << *John << endl;
  cout << *Priya << endl;
}

int main() {
  /* Main */

  /* Motivation example */
  testRecordKeeping();

  /* Prototype Example */
  testPrototypePattern();

  /* Prototype using Factory */
  testPrototypeFactory();

  return 0;
}