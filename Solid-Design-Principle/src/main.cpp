
#include <iostream>
#include <string>

#include "OpenClosedPrinciple.h"
#include "SingleResponsePrinciple.h"

using namespace std;

/* =================== 1. Single Responsibility Principle ==================================== */

void testSingleRespPrin() {
  Journal journal("My Diary");
  journal.addEntries("It's March 17 - 2021, Wednesday");
  journal.addEntries("It's nice weather today");
  journal.addEntries("I had Pancakes in breakfast today");

  PersisteceManager<string> pm;
  pm.save("diary.txt", journal.getEntries());
}

/* ============================================================================================ */

/* =================== 2. Open Closed Principle ==================================== */
void testOpenClosePrin() {
  Product apple{"Apple", Color::green, Size::small};
  Product tree{"Tree", Color::green, Size::large};
  Product house{"House", Color::blue, Size::large};

  ProductFilter pf;
  vector<Product*> items{&apple, &tree, &house};

  auto grP = pf.byColor(items, Color::green);
  for (auto& i : grP) {
    cout << i->_name << " is green\n";
  }

  auto largeP = pf.bySize(items, Size::large);
  for (auto& i : largeP) {
    cout << i->_name << " is large\n";
  }

  auto gAndSmall = pf.byColorAndSize(items, Color::green, Size::small);
  for (auto& i : gAndSmall) {
    cout << i->_name << " is green and Samll\n";
  }

  cout << "\n\nNow using Better filter\n";

  BetterFilter bf;
  ColorSpecification green(Color::green);
  for (auto& i : bf.filter(items, green)) {
    cout << i->_name << " is green \n";
  }

  SizeSpecification largeItems(Size::large);
  for (auto& i : bf.filter(items, largeItems)) {
    cout << i->_name << " is large \n";
  }
}

int main() {
  /* 1. Single Responsibility Principle */
  testSingleRespPrin();
  testOpenClosePrin();
}