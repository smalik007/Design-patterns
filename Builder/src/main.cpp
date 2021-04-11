
#include <iostream>

#include "BuilderHTML.hpp"
#include "BuilderPizza.hpp"

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

int main() {
  //   testBuilder();
  testBuilderHTML();
}
