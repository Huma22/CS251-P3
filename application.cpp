//
//  application.cpp
//  Created by Huma Tejaswi
//  Cs 251 project 3

#include <fstream>
#include <iostream>

#include "AutocompleteList.h"

using namespace std;

int main() {
  string filename;
  cout << "Enter filename: ";
  cin >> filename;

  fstream file(filename);

  if (file.fail()) {
    cout << "No such file exists.\n";
    return 1;
  }

  AutocompleteList list(filename);
  char ch;
  cout << "Enter s-search or c-creative search: ";
  cin >> ch;
  if (ch == 's' || ch == 'S'){
      cout << "Welcome!\nType your search below, press enter for autocomplete (# to stop).\n";
      string search;
      cin.get();
      while (1) {
        cout << "Search: ";
       getline(cin, search);
     //  cin >> search;
        if (search == "#") {
          break;
        }
    
        AutocompleteList searchMatches = list.allMatches(search);
        searchMatches.print();
      }
  }
  if (ch == 'c' || ch == 'C'){
      AutocompleteList list(filename);
      list.maxNumber();
  }

  return 0;
}
