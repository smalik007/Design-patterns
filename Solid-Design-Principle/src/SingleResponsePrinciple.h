/*
 * Description -
 *
 * @authors Suhail.m (suhail.m@gmail.com)
 * @date    2021-03-17 14:53:05
 *
 */

#pragma once
#include <boost/lexical_cast.hpp>
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

/* =================== 1. Single Responsibility Principle ======================= */

class Journal {
  string _title;
  vector<string> _entries;

 public:
  Journal() = delete;
  explicit Journal(const string& titile) : _title(titile) {}

  void addEntries(const string& text) {
    static int entryCount = 1;
    _entries.push_back(boost::lexical_cast<string>(entryCount++) + ": " + text);
  }

  const vector<string>& getEntries() { return _entries; }

  /* If we want to save the journal in a text file, adding this functionality in Journal class is not good (it breaks the sigle responsiblity principle)
    Further more it make's code less flexible. Saving is a persistence operation and it can be defined in a seprate class, that class can itself have different type of
    saving mechanism, like saving to file, database or cloud */

  // void save(const string& filename) {} // Not a good way to implement here
};

template <class T>
class PersisteceManager {
 public:
  PersisteceManager() = default;
  static void save(const string& filename, const vector<T>& entries) {
    ofstream ofs;
    ofs.open(filename);
    for (auto& e : entries) {
      ofs << e << endl;
    }
    ofs.close();
  }
};
