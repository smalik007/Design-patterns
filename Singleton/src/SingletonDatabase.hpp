/*
 * Description -
 *
 * @authors Suhail.m (suhailmalik19.5@gmail.com)
 * @date    2021-06-10 23:37:46
 *
 */

#pragma once

#include <fstream>
#include <iostream>
#include <unordered_map>

using namespace std;
class SingletonDatabase {
  unordered_map<string, int> map_db_;
  /* Keep the constructor private, and expose an API which will return singleton instance */
  SingletonDatabase() {
    ifstream ifs("../Data.txt");
    string s, s2;
    while (getline(ifs, s)) {
      getline(ifs, s2);
      cout << s << " " << s2 << endl;
      int pop = 0;
      pop = atoi(s2.c_str());
      map_db_[s] = pop;
    }
  }

 public:
  /* delete Copy and assignment constructor */
  SingletonDatabase(const SingletonDatabase&) = delete;
  SingletonDatabase operator=(const SingletonDatabase&) = delete;

  static SingletonDatabase& getInstance() {
    static SingletonDatabase db;
    return db;
  }

  int getPopulation(const string& city) { return map_db_[city]; }
};