/*
 * Description -
 *
 * @authors Suhail.m (suhailmalik19.5@gmail.com)
 * @date    2021-06-10 23:36:55
 *
 */

#include <gtest/gtest.h>

#include <iostream>

#include "SingletonDIInterface.hpp"
#include "SingletonDatabase.hpp"
#include "boost_di.hpp"

using namespace std;

void testSingletonDatabase() { cout << "Delhi pop : " << SingletonDatabase::getInstance().getPopulation("Delhi") << endl; }

/* The Disadvantage of using Singleton patter:
  Here there's we only wanted to test SingletonRecordFinder::totalPop, but due to the strong coupling of singleton class we are bound use the data from the data.txt file, which makes it an
  intergration test rather than an unit test. Furthermore relying on the production data for a unit test is horrible.   */
TEST(RecordFinderTest, SingletonTotalPopTest) {
  SingletonRecordFinder rf;
  vector<string> names = {"Delhi", "Mumbai"};
  int res = rf.totalPop(names);
  int exp = 12345 + 14235;
  ASSERT_EQ(exp, res) << " Expected : " << exp << "got : " << res;
}

/* This will be now testing the record finder as a unit test */
TEST(ConfRecordFinderTest, ConfTotalPopTest) {
  DummyDataBase db;
  ConfigurableRecordFinder rf(db);
  vector<string> names = {"alpha", "beta", "gamma"};
  int res = rf.totalPop(names);
  int exp = 1 + 2 + 3;
  ASSERT_EQ(exp, res) << " Expected : " << exp << "got : " << res;
}

/* We can also use this ConfigurableRecord finder for our singletom class, But as a test it will be integration test. */
TEST(ConfRecordFinderTest2, ConfTotalPopTest2) {
  ConfigurableRecordFinder rf(SingletonDatabase::getInstance());
  vector<string> names = {"Delhi", "Mumbai"};
  int res = rf.totalPop(names);
  int exp = 12345 + 14235;
  ASSERT_EQ(exp, res) << " Expected : " << exp << "got : " << res;
}

/* We will use boost's Dependency injection feature to create singleton instance of the class Foo. */
void testBoostDIForSingleton() {
  //  The Singleton instance of the class will have a lifetime same as of injector
  auto injector = boost::di::make_injector(boost::di::bind<IFoo>().to<Foo>().in(boost::di::singleton));

  /* Although we are creating two instance of Bar, but both of them will return the same ptr of Foo */
  auto bar1 = injector.create<std::shared_ptr<Bar>>();
  auto bar2 = injector.create<std::shared_ptr<Bar>>();

  /* Hence output of both the prints will be same */
  cout << bar1->foo->names() << endl;
  cout << bar2->foo->names() << endl;

  /* Infact both pointer are pointing the same instance (singleInstance) */
  cout << boolalpha << (bar1->foo.get() == bar2->foo.get()) << endl;
}

int main(int agc, char* agv[]) {
  /* Main */

  testing::InitGoogleTest(&agc, agv);

  testSingletonDatabase();

  testBoostDIForSingleton();

  return RUN_ALL_TESTS();
}