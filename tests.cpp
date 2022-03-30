//
//  tests.cpp
//  Created by: Huma Tejaswi 
//  CS 251 

#include <iostream>

#include "AutocompleteList.h"

using namespace std;

// Tests getSize() on first constructor
bool size_test1() {
  AutocompleteList list;  // empty list
  if (list.getSize() == 0) {
    return true;
  }
  return false;
}
// Tests getSize() on second constructor
bool size_test2() {
  int n = 10;
  AutocompleteList list(n);  // empty list
  if (list.getSize() == 10) {
    return true;
  }
  return false;
}

bool size_test3() {
  AutocompleteList list("tiny.txt");
  if (list.getSize() == 6) {
    return true;
  } return false;
}
// test for getSize on wiktionary.txt
bool size_test4(){
      AutocompleteList list("wiktionary.txt");
  if (list.getSize() == 10000) {
    return true;
  } return false;
}
// test for cities.txt
bool size_test5(){
      AutocompleteList list("cities.txt");
  if (list.getSize() == 93827) {
    return true;
  } return false;
}
// test for query for wiktionary
bool query() {
    string filename = "wiktionary.txt";
	AutocompleteList list(filename);
	AutocompleteList res = list.allMatches("sentence");
	Term shouldbe[] = {
		Term("sentence", 5369900), 
		Term("sentences", 1337720),
		Term("sentenced", 492797)
		};
		res.print();
	return true;
}
bool query1() {
    AutocompleteList obj("wiktionary.txt");
     obj.print();
     AutocompleteList copy =  obj.allMatches("bu");
     copy.print();
	return true;
} 
bool class_text6() {
     AutocompleteList list("wiktionary.txt ")
     string prefix =" start";
     AutocompleteList list(filename);
     if(numberOfMatches == 5)
     {
       return true;
     } return false;
} bool function_text7() {
    AutocompleteList list("wiktionary.txt ")
    if(print(" ") == 0)
    {
        return true;
    } return false;
} bool function_text8() {
    AutocompleteList list("cities.txt ")
    if(allMatches==10;
    {
        return true;
    } return false;
} bool function_text9() {
    AutocompleteList list("tiny.txt ");
    if(lex == idx1)
    {
        return true;
    } return false;
bool function_text10() {
    string filename = wiktionary.txt;
    AutocompleteList list(100);
    AutocompleteList test(list);
    if(list[0].weight == 10 && list[0].query == " ")
    {
        return true;
    } return false;
} bool function_text12() {
    string filename = tiny.txt;
    AutocompleteList list(" ")
    if(cnt < = 0)
    {
        return true;
    } return false;
} bool function_text13() {
    string filename = wiktionary.txt;
    AutocompleteList list(100)
    if(firstIndexOf ! = lastIndexOf)
    {
     return true;
    } return false;
} bool function_text14() {
    string filename = tiny.txt;
     AutocompleteList list(100)
    if(lastIndexOf(" ") == 0)
    {
        return true;
    } return false;
}
// checking for term a
} bool function_text15() {
    string filename = wiktionary.txt;
    AutocompleteList list(100000)
    if(Term a == 0)
    {
        return true;
    }
    return false;
}
// checking for term b 
} bool function_text16() {
     string filename = wiktionary.txt;
    AutocompleteList list(100000)
    if(Term b == 0)
    {
        return true;
    } return false;
} bool function_text17() {
    string filename = tiny.txt;
    AutocompleteList list(" ")
    if(size == 0)
    {
        return true;
    } return false;
} bool function_text18() {
    string filename = tiny.txt;
    AutocompleteList list(" ")
    if(weight(" ")== 0)
    {
        return true;
    } return false;
} bool function_text19() {
    string filename = wiktionary.txt;
    AutocompleteList list(" ")
    if(test.getSize() == 1000)
    {
        return true;
    } return false;
    
} bool function_text20() {
    string filename = wiktionary.txt;
    AutocompleteList list(" ")
    if(getSize() == 100)
    {
        return true;
    } return false;
} bool function_text22() {
    string filename = cities.txt;
    AutocompleteList list = list;
    if(sortByWeightOrder == 0)
    {
        return true;
    } return false;
} bool function_text23() {
    string filename = cities.txt;
    AutocompleteList list = list;
    if(resultfunction == 0)
    {
     return true;
    } return false;
} int main() {
  // TODO:  Write lots of tests.  Here are two very simple examples.
  // You need to write a lot more than this.
  int passed = 0;
  int failed = 0;
  // Run tests
  if (size_test1()) {
    passed++;
  } else {
    cout << "size_test1 failed" << endl;
    failed++;
  }
  if (size_test2()) {
    passed++;
  } else {
    cout << "size_test2 failed" << endl;
    failed++;
  }
  if (size_test3()) {
    passed++;
  } else {
    cout << "size_test3 failed" << endl;
    failed++;
  }
  if (size_test4()) {
    passed++;
  } else {
    cout << "size_test4 failed" << endl;
    failed++;
  }
  if (size_test5()) {
    passed++;
  } else {
    cout << "size_test5 failed" << endl;
    failed++;
  }
  if(query())
  {
      cout << "query passing" << endl;
      passed++;
  } else {
      cout << "query test 1 failed" << endl;
    failed++;
  }
    if(query1())
  {
      cout << "query 1 passing" << endl;
      passed++;
  } else {
      cout << "query test 2 failed" << endl;
    failed++;
  }
    if(class_text6())
  {
      cout <<"class_text6 passing"<< endl;
      passed++;
  } else {
      cout << "class_text6 failed" << endl;
    failed++;
  }
  if(function_text7())
  {
      cout << "function_text7 passing"<< endl;
      passed++;
  } else {
      cout << "function_text7 failed" << endl;
    failed++;
  }
  if(function_text8())
  {
      cout << "function_text8 passing" << endl;
      passed++;
  } else {
      cout << "function_text8 failed" << endl;
    failed++;
  }
  if(function_text9())
  {
      cout <<"function_text9 passing" << endl;
      passed++;
  } else {
      cout << "function_text9 failed" << endl;
    failed++;
  }
  if(function_text10())
  {
      cout << "function_text10 passing" << endl;
      passed++;
  } else {
      cout << "function_text10 failed" << endl;
    failed++;
  }
  if(function_text12())
  {
      cout <<"function_text12 passing"<<endl;
      passed++;
  } else {
      cout << "function_text12 failed" << endl;
    failed++;
  }
  if(function_text13())
  {
      cout << "function_text13 passing" << endl;
      passed++;
  } else {
      cout << "function_text13 failed" << endl;
    failed++;
  }
  if(function_text14())
  {
      cout <<"function_text14 passing"<< endl;
      passed++;
  } else {
      cout << "function_text14 failed" << endl;
    failed++;
  }
  if(function_text15())
  {
      cout << "function_text15 passing" << endl;
      passed++;
  } else {
      cout << "function_text14 failed" << endl;
    failed++;
  }
  if(function_text16 ())
  {
      cout << "function_text16 passing" << endl;
      passed++;
  } else {
      cout << "function_text16 failed" << endl;
    failed++;
  }
  if(function_text17())
  {
      cout << "function_text17 passing" << endl;
      passed++;
  } else {
      cout << "function_text17 failed" << endl;
    failed++;
  }
  if(function_text18())
  {
      cout << "function_text18 passing" << endl;
      passed++;
  } else {
      cout << "function_text18 failed" << endl;
    failed++;
  }
  if(function_text19())
  {
      cout << "function_text19 passing" << endl;
      passed++;
  } else {
      cout << "function_text19 failed" << endl;
    failed++;
  }
  if(function_text20())
  {
      cout << "function_text20 passing" << endl;
      passed++;
  } else {
      cout << "function_text20 failed" << endl;
    failed++;
  }
  
  if(function_text22())
  {
      cout << "function_text22 passing" << endl;
      passed++;
  } else {
      cout << "function_text22 failed" << endl;
    failed++;
  }
  if(function_text23())
  {
      cout << "function_text23 passing" <<endl;
      passed++;
  } else {
      cout << "function_text23 failed" << endl;
    failed++;
  }
  cout << "Tests passed: " << passed << endl;
  cout << "Tests failed: " << failed << endl;
  return 0;
}
