/*
 * Description -
 *
 * @authors Suhail.m (suhailmalik19.5@gmail.com)
 * @date    2021-06-10 23:36:55
 *
 */

#include <iostream>

#include "SingletonDatabase.hpp"

using namespace std;

void testSingletonDatabase() { cout << "Delhi pop : " << SingletonDatabase::getInstance().getPopulation("Delhi") << endl; }

int main() {
  /* Main */

  testSingletonDatabase();
  return 0;
}