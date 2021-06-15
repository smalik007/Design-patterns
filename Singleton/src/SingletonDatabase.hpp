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
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

/* To solve the problem of testing RecordFinder::total_population we will use dependency injection */
/* For that we define a Base class */

class DataBase {
 public:
  virtual int getPopulation(const string& name) = 0;
};

/* Now we will Inherit this here */
class SingletonDatabase : public DataBase {
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

  int getPopulation(const string& city) override { return map_db_[city]; }
};

struct SingletonRecordFinder {
  int totalPop(vector<string> caps) {
    int res{0};
    for (auto& c : caps) {
      res += SingletonDatabase::getInstance().getPopulation(c);
    }
    return res;
  }
};

/* we will also define a DummyData Base */
class DummyDataBase : public DataBase {
  unordered_map<string, int> map_db_;

 public:
  /* This will have a dummy data */
  DummyDataBase() {
    map_db_["alpha"] = 1;
    map_db_["beta"] = 2;
    map_db_["gamma"] = 3;
  }
  int getPopulation(const string& name) override { return map_db_[name]; }
};

/* This time we will have a Configurable Recordfinder that we can test as a unit test, without having to rely on a production data. We can test the API using the dummy data base and the same time can
 * also use it for singleton class as well */
struct ConfigurableRecordFinder {
  DataBase& db;
  ConfigurableRecordFinder(DataBase& db) : db(db) {}

  int totalPop(vector<string> caps) {
    int res{0};
    for (auto& c : caps) {
      res += db.getPopulation(c);
    }
    return res;
  }
};