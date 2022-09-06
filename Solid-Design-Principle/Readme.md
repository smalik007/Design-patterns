## When to use what design pattern

### Solid Design Pattern

#### 1. Single Responsibility Principle

* For separation of concerns
* Don't put everything in a single class, make multiple class with different concerns
* e.g Writing a journal and saving it are different concerns.

#### 2. Open close principle

* A class should be open for extension but close for modification.
* The idea is the new features/implementation should be extended to new classes rather than mofifying existing tested piece of code/class.

#### 3. Interface Segregation Principle

* An abstract class should not have many virtual methods, this forces the extended class to write empty/Non implemented api's which are not needed in them.
* Instead it's a good idea to make multiple Abstract classes having segregation on interfaces, and the extended class can inherit from multiple base classes and only implement the api's it needed.
* e.g a Machine (Printer, Scanner, Fax) Each machine is a extended class that can extend from multiple abstract class like IPrint, Iscan, IFax etc. A Printer class in this case would inherit both Iprint and Iscan abstract class, while Fax class only extend IFax class.

#### 4. Liskov substitution

* Liscov Principle States that, for any operation e.g calling an API which take Basetype, substituting a derived type should not change/break the behaviour of the API
* Your class should not break this rule.

#### 5. Dependency Inversion

* High-level modules should not depend on low-level modules. Both should depend on abstractions.
* Abstractions should not depend on details. Instead details should depend on abstractions.
