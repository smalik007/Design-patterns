#include <iostream>
#include <string>
#include "SingleResponsePrinciple.h"

using namespace std;

/* =================== 1. Single Responsibility Principle ======================= */

void testSingleRespPrin() {
  Journal journal("My Diary");
  journal.addEntries("It's March 17 - 2021, Wednesday");
  journal.addEntries("It's nice weather today");
  journal.addEntries("I had Pancakes in breakfast today");

  PersisteceManager<string> pm;
  pm.save("diary.txt", journal.getEntries());
}

/* ============================================================================================ */

int main() {

  /* 1. Single Responsibility Principle */
  testSingleRespPrin();
}