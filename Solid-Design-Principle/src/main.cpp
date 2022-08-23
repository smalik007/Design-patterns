
#include <iostream>
#include <string>

// #include "DependencyInversion.hpp"
#include "InterfaceSegregation.hpp"
#include "LiskovSubstitutionPrinciple.hpp"
#include "OpenClosedPrinciple.hpp"
#include "SingleResponsePrinciple.hpp"
#include "DependencyInversion.hpp"

using namespace std;

/* =================== 1. Single Responsibility Principle ==================================== */

void testSingleRespPrint()
{
  cout << endl;
  cout << "*************************\n";
  cout << "1. Single Responsibility Principle\n";
  cout << "*************************\n";

  Journal journal("My Diary");
  journal.addEntries("It's March 17 - 2021, Wednesday");
  journal.addEntries("It's nice weather today");
  journal.addEntries("I had Pancakes in breakfast today");

  PersisteceManager<string> pm;
  pm.save("diary.txt", journal.getEntries());
}

/* ============================================================================================ */

/* =================== 2. Open Closed Principle ==================================== */
void testOpenClosePrint()
{
  cout << endl;
  cout << "*************************\n";
  cout << "2. Open Close Principle\n";
  cout << "*************************\n";

  Product apple{"Apple", Color::green, Size::small};
  Product tree{"Tree", Color::green, Size::large};
  Product house{"House", Color::blue, Size::large};

  ProductFilter pf;
  vector<Product *> items{&apple, &tree, &house};

  auto grP = pf.byColor(items, Color::green);
  for (auto &i : grP)
  {
    cout << i->_name << " is green\n";
  }

  auto largeP = pf.bySize(items, Size::large);
  for (auto &i : largeP)
  {
    cout << i->_name << " is large\n";
  }

  auto gAndSmall = pf.byColorAndSize(items, Color::green, Size::small);
  for (auto &i : gAndSmall)
  {
    cout << i->_name << " is green and Samll\n";
  }

  cout << "\n\nNow using Better filter\n";

  BetterFilter bf;
  ColorSpecification green(Color::green);
  for (auto &i : bf.filter(items, green))
  {
    cout << i->_name << " is green \n";
  }

  SizeSpecification largeItems(Size::large);
  for (auto &i : bf.filter(items, largeItems))
  {
    cout << i->_name << " is large \n";
  }

  CombinationalSpecification<Product> greenAndLarge(green, largeItems);
  for (auto &i : bf.filter(items, greenAndLarge))
  {
    cout << i->_name << " is green and large \n";
  }

  // Alternatively by operator overloading of &&
  auto comb = ColorSpecification(Color::blue) && SizeSpecification(Size::medium);
  for (auto &i : bf.filter(items, comb))
  {
    cout << i->_name << " is blue and medium \n";
  }
}

/* ============================================================================================ */

/* =================== 3. Liscov Substitution Principle ==================================== */
template <class T>
void process(Rectangle<T> &r)
{

  T w = r.getWidth();
  r.setHeight(10);

  cout << "Expected Area : " << w * 10 << "\t Got : " << r.area() << endl;
}

void testLiscovPrinciple()
{
  cout << endl;
  cout << "*************************\n";
  cout << "3. Liskov Substitution Principle\n";
  cout << "*************************\n";

  Rectangle<int> rect(10, 20);
  process(rect);

  Square<int> sqr(5);
  /* This is where it breaks the law, as the process API will fail (give unexpected output)
    Liscov Principle States that, for any operation e.g calling an API which take Basetype, substituting a derived type should not change/break the behaviour of the API
    To fix this situation is not to inherit square from Rectangle as they both have different properties altough square is infact a rectangle methamatically, Or use Factories
    class to create the Individual type of rectangle.*/
  process(sqr);
}

void testDependencyInversionPrinciple()
{
  cout << endl;
  cout << "*************************\n";
  cout << "4. Dependency Inversion Principle\n";
  cout << "*************************\n";

  /* This here is a bad idea */
  //  Research(const Relationships& relationships)
  //  {
  //    auto& relations = relationships.relations;
  //    for (auto&& [first, rel, second] : relations)
  //    {
  //      if (first.name == "John" && rel == Relationship::parent)
  //      {
  //        cout << "John has a child called " << second.name << endl;
  //      }
  //    }
  //  }

  // Instead do something this
  Relationships family;
  family.add_parent_and_child(Person("John"), Person("Mark"));
  family.add_parent_and_child(Person("John"), Person("Claire"));
  auto res = family.find_all_children_of("John");
  for (auto &i : res)
  {
    cout << i.name << " ";
  }
  cout << endl;
}

/* ============================================================================================ */

int main()
{
  /* 1. Single Responsibility Principle */
  testSingleRespPrint();
  testOpenClosePrint();
  testLiscovPrinciple();
  testDependencyInversionPrinciple();
}