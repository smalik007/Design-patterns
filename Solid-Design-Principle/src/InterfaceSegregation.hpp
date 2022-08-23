/*
 * Description -
 *
 * @authors Suhail.m (suhail.m@greyorange.com)
 * @date    2021-03-17 20:13:26
 *
 */

#pragma once

#include <vector>
struct Document;

/* When writing a Abstract class, you might be tempted to write all methods related to a perticular type (Document here in this case) in a single Class
    Problem with this approach is when writing the Derived classes using this BaseType, you have to implement all the API's in Derived class aswell,
    even though it might not be using it.

    For example here we can Print, Scan, Fax a document, Defining a IMachine which can do all these stuff make sense
    1. But about if we want to implement a Printer Machine (which can only Scan or print)
    2. Or a Scanner Machine which can only Scan

    In these cases we have to unnecessarily implement other API also, either with Not::Implemented exceptions or keeping it blank
    Below is the example of such machine
*/

// struct IMachine
//{
//  virtual void print(Document& doc) = 0;
//  virtual void fax(Document& doc) = 0;
//  virtual void scan(Document& doc) = 0;
//};

// struct Printer: IMachine {
//   void print(Document& doc) override {
//     //   Do print operation
//   }
//   void fax(Document& doc) override {
//      //   Have to leave blank or throw Not::Implemented exception
//   }
//   void scan(Document& doc) override {
//     //   Do scan operation
//   }
// };

// struct Scanner: IMachine {
//   void print(Document& doc) override {
//     //   Have to leave blank or throw Not::Implemented exception
//   }
//   void fax(Document& doc) override {
//      //   Have to leave blank or throw Not::Implemented exception
//   }
//   void scan(Document& doc) override {
//     //   Do scan operation
//   }
// };

// 1. Recompile (time)
// 2. Client does not need this
// 3. Forcing implementors to implement too much

/* Interface Segregation Principle States, we can individully define these methods as individual machine,
    and a machine which can perform multiple operation can use of multiple inheritance to use those functionality */

struct IPrinter
{
  virtual void print(Document &doc) = 0;
};

struct IScanner
{
  virtual void scan(Document &doc) = 0;
};

struct IFax
{
  virtual void fax(Document &doc) = 0;
};

struct Printer : IPrinter, IScanner
{
  void print(Document &doc) override;
  void scan(Document &doc) override;
};

struct Scanner : IScanner
{
  void scan(Document &doc) override;
};

struct Fax : IFax
{
  void fax(Document &doc) override;
};

/* You can even just define a IMachine with it's inheritance type and leave it blank here making it abstact  */
struct IMachine : IPrinter, IScanner, IFax
{
};

struct Machine : IMachine
{
  IPrinter &printer;
  IScanner &scanner;
  IFax &faxd;

  Machine(IPrinter &printer, IScanner &scanner, IFax &fax) : printer(printer), scanner(scanner), faxd(fax)
  {
  }

  void print(Document &doc) override { printer.print(doc); }
  void scan(Document &doc) override;
  void fax(Document &doc) override;
};

// IPrinter --> Printer
// everything --> Machine
