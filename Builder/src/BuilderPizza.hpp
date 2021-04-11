/*
 * Description -
 *
 * @authors Suhail.m (suhailmalik19.5@gmail.com)
 * @date    2021-04-11 16:07:33
 *
 */
#pragma once

#include <iostream>
#include <memory>
#include <vector>

using namespace std;

/* It’s especially useful when you need to create an object with lots of possible configuration options. */
/* Identification: The Builder pattern can be recognized in a class, which has a single creation method and several methods to configure the resulting object. Builder methods often support chaining
 * (for example, someBuilder->setValueA(1)->setValueB(2)->create()). */

/* Let's understand Builder pattern with example for Pizza (blog https://medium.com/@andreaspoyias/design-patterns-a-quick-guide-to-builder-pattern-a834d7cacead)
 *. A Pizza can have different dough, sauces, toppings, cheeze layer
 *. How User would know to configure all these things while getting a single object of pizza
 *. One way could be multiple overloaded constructor (bad design), with different sets of arguments */

/* Let’s oversimplify Builder pattern by bluntly saying:
   The Builder pattern’s main intent is to have the minimum number of overloading constructors to support the constuction of several representations of an object. */

namespace pizza {
class Pizza {
  string dough_;
  vector<string> sauce_;
  vector<string> toppings_;
  double price_;

  /* Price can have specific logic based on the type of sauce and toppings, Here were are assuming same price for each choice */
  const double doughPrice_ = 50;
  const double saucePrice_ = 30;
  const double topPrice_ = 100;

 public:
  Pizza() : price_(0.0) {}
  void taste() {
    cout << "Pizza with " << dough_ << " dough ,";
    for (auto& s : sauce_) {
      cout << s << " ";
    }
    cout << "sauce and ";
    for (auto& t : toppings_) {
      cout << t << " ";
    }
    cout << "toppings " << endl;
  }
  double getPrice() { return price_; }
  void setDough(const string& dough) {
    dough_ = dough;
    price_ += doughPrice_;
  }
  void setSauce(const vector<string>& sauce) {
    sauce_ = sauce;
    price_ += sauce_.size() * saucePrice_;
  }
  void setToppings(const vector<string>& toppings) {
    toppings_ = toppings;
    price_ += toppings_.size() * topPrice_;
  }
};

/* Abstract Pizza Builder class */
class PizzaBuilder {
 public:
  virtual ~PizzaBuilder(){};
  Pizza* getPizza() { return pizza_.get(); }

  void createNewPizzaProduct() { pizza_ = make_unique<Pizza>(); }
  virtual void buildDough() = 0;
  virtual void buildSauce() = 0;
  virtual void buildTop() = 0;

  virtual void addDough(const string& dough){};
  virtual void addSauce(const vector<string>& sauces){};
  virtual void addTop(const vector<string>& sauces){};

 protected:
  unique_ptr<Pizza> pizza_;
  string dough_;
  vector<string> sauces_;
  vector<string> toppings_;
};

/* Concrete Builder, Some predefined Pizzas */
class MargheritaConcreteBuilder : public PizzaBuilder {
 public:
  void buildDough() override { pizza_->setDough({"cross"}); }
  void buildSauce() override { pizza_->setSauce({"tomato"}); }
  void buildTop() override { pizza_->setToppings({"mozzarela", "basil"}); }
};

class SpicyConcreteBuilder : public PizzaBuilder {
 public:
  void buildDough() override { pizza_->setDough({"pan-baked"}); }
  void buildSauce() override { pizza_->setSauce({"tomato", "chilli"}); }
  void buildTop() override { pizza_->setToppings({"pepperoni", "salami"}); }
};

/*  Here you make your own pizza */
class MakeYourOwnPizza : public PizzaBuilder {
 public:
  void buildDough() override { pizza_->setDough(dough_); }
  void buildSauce() override { pizza_->setSauce(sauces_); }
  void buildTop() override { pizza_->setToppings(toppings_); }

  void addDough(const string& dough) override { dough_ = dough; }
  void addSauce(const vector<string>& sauces) override { sauces_ = sauces; }
  void addTop(const vector<string>& toppings) override { toppings_ = toppings; }
};

/* This class uses the actual builder and build a pizza for you */
class CookDirector {
 public:
  void tastePizza() { pizzaBuilder_->getPizza()->taste(); }
  double billPizza() { return pizzaBuilder_->getPizza()->getPrice(); }

  void makePizza(PizzaBuilder* pb) {
    pizzaBuilder_ = pb;
    pizzaBuilder_->createNewPizzaProduct();
    pizzaBuilder_->buildDough();
    pizzaBuilder_->buildSauce();
    pizzaBuilder_->buildTop();
  }

 private:
  PizzaBuilder* pizzaBuilder_;
};
}