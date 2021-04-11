
#include <iostream>

#include "BuilderHTML.hpp"
#include "BuilderPizza.hpp"
#include "CodeBuilder.hpp"
#include "Person.hpp"
#include "PersonAddressBuilder.hpp"
#include "PersonBuilder.hpp"
#include "PersonJobBuilder.hpp"

using namespace std;

void testBuilder() {
  pizza::CookDirector cook;
  pizza::MargheritaConcreteBuilder margheritaPizza;
  pizza::SpicyConcreteBuilder spicyPizza;

  cook.makePizza(&margheritaPizza);
  cook.tastePizza();
  cout << "Bill Amount : " << cook.billPizza() << endl;

  cout << endl;
  cook.makePizza(&spicyPizza);
  cook.tastePizza();
  cout << "Bill Amount : " << cook.billPizza() << endl;

  cout << endl;
  pizza::MakeYourOwnPizza myPizza;
  myPizza.addDough("Thin-crust");
  myPizza.addSauce({"Green chilly", "Red souce", "white sauce"});
  myPizza.addTop({"Onion", "Chiken slami", "Paneer"});
  cook.makePizza(&myPizza);
  cook.tastePizza();
  cout << "Bill Amount : " << cook.billPizza() << endl;
}

void testBuilderHTML() {
  cout << html::P{html::IMG("https://www.pokemon.com/us/pokedex/pikachu")};

  cout << endl;
  cout << html::Table{html::TableRow{html::TableHeader("Name"), html::TableHeader("Age"), html::TableHeader("Gender")},
                      html::TableRow{html::TableData("John"), html::TableData("25"), html::TableData("M")}, html::TableRow{html::TableData("Aysha"), html::TableData("21"), html::TableData("F")}};
}

void testPersonBuilder() {
  Person john = Person::create().lives().at("123 Baker Street").with_postcode("124566").in("London").works().at("ABC").as_a("Software Engineer").earning(10e3);
  cout << john << endl;
}

void testCodeBuilder() {
  auto cb = CodeBuilder{"Rectangle"}.add_field("length", "int").add_field("width", "int");
  cout << cb;
}

int main() {
  //   testBuilder();
  //   testBuilderHTML();
  testPersonBuilder();
  testCodeBuilder();
}
