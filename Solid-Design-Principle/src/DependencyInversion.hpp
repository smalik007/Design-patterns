/*
 * Description -
 *
 * @authors Suhail.m (suhail.m@greyorange.com)
 * @date    2021-03-17 23:35:18
 *
 */

#include <iostream>
#include <string>
#include <tuple>
#include <vector>
using namespace std;

/* Dependencies Inversion States that
    A. High-level modules should not depend on low-level modules. Both should depend on abstractions.
    B. Abstractions should not depend on details. Instead details should depend on abstractions.

*/

enum class Relationship { parent, child, sibling };

struct Person {
  string name;
};

struct RelationshipBrowser {
  virtual vector<Person> find_all_children_of(const string& name) = 0;
};

struct Relationships : RelationshipBrowser  // low-level
{
  vector<tuple<Person, Relationship, Person>> relations;

  void add_parent_and_child(const Person& parent, const Person& child) {
    relations.push_back({parent, Relationship::parent, child});
    relations.push_back({child, Relationship::child, parent});
  }

  vector<Person> find_all_children_of(const string& name) override {
    vector<Person> result;
    for (auto& [first, rel, second] : relations) {
      if (first.name == name && rel == Relationship::parent) {
        result.push_back(second);
      }
    }
    return result;
  }
};

struct Research  // high-level
{
  Research(RelationshipBrowser& browser) {
    for (auto& child : browser.find_all_children_of("John")) {
      cout << "John has a child called " << child.name << endl;
    }
  }

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
};
