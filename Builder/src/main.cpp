
#include <iostream>

#include "Builder.hpp"

using namespace std;

void testBuilder() {
  CookDirector cook;
  MargheritaConcreteBuilder margheritaPizza;
  SpicyConcreteBuilder spicyPizza;

  cook.makePizza(&margheritaPizza);
  cook.tastePizza();
  cout << "Bill Amount : " << cook.billPizza() << endl;

  cout << endl;
  cook.makePizza(&spicyPizza);
  cook.tastePizza();
  cout << "Bill Amount : " << cook.billPizza() << endl;

  cout << endl;
  MakeYourOwnPizza myPizza;
  myPizza.addDough("Thin-crust");
  myPizza.addSauce({"Green chilly", "Red souce", "white sauce"});
  myPizza.addTop({"Onion", "Chiken slami", "Paneer"});
  cook.makePizza(&myPizza);
  cook.tastePizza();
  cout << "Bill Amount : " << cook.billPizza() << endl;
}

int main() { testBuilder(); }
