// AutocompleteList.h
// Created By: Huma Tejaswi Akkem
// CS 251, Project 3
// prof.Shanon Reckinger
#pragma once

#include <algorithm>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

struct Term {
  string query;
  long long int weight;
  // need this for autograding
  bool operator==(const Term& term) const {
    return (query == term.query && weight == term.weight);
  }
};

//
// AutocompleteList
//
class AutocompleteList {
 private:
  //
  // Private member variables for the abstraction.
  // This implementation uses a low-level C array, terms, to store a list of
  // Terms.  As a result, you must also keep track of the number of elements
  // stored (size).
  //
  Term* terms;      // pointer to a C-style array
  int size;         // number of elements in the array
  string sortType;  // records how list is sorted
  //
  // Private member function.
  // Returns the index of the first word in terms[] that contains the prefix,
  // or -1 if there are no words containing the prefix. This search should be
  // implemented using a variation of the binary search algorithm.
  // Performance requirement: O(logn), n is size.
  //

	int firstIndexOf(const string &prefix) {
		int startIndex = 0, length = size - 1, temp;
		temp = 0;
		while (startIndex <= length) {
			int middleIndex = startIndex + (length - startIndex) / 2;
			if (terms[middleIndex].query.compare(prefix) >= 0) {
				temp = middleIndex;
				length = middleIndex - 1;
			} else {
				startIndex = middleIndex + 1;
			}
		}
		return temp;
	}
	//
	// Private member function.
	// Returns the index of the last word in terms[] that contains the prefix,
	// or -1 if there are no words containing the prefix. This search should be
	// implemented using a variation of the binary search algorithm.
	// Performance requirement: O(logn), n is size.
	//
	int lastIndexOf(string prefix) {
		int startIndex = 0, length = size - 1, temp;
		temp = 0;
		prefix = prefix + string(1, char(126));
		while (startIndex <= length) {
			int mid = startIndex + (length - startIndex) / 2;
			if (terms[mid].query.compare(prefix) >= 0) {
				temp = mid;
				length = mid - 1;
			} else {
				startIndex = mid + 1;
			}
		}
		return temp;
	}

  //
  // Private member function.
  // This function sorts the terms array by lexicographic order of the query
  // string.
  // Set sortType to "lex".
  // Performance requirement: O(nlogn), n is size.
  //
  void sortByLexOrder() {
    sortType = "lex";
    sort(terms, terms + size, [](Term a, Term b) {
      return a.query < b.query;
    });
  }
  //
  // Private member function.
  // This function sorts the terms array by decreasing weight order.
  // Set the sortType to "weight".
  // Performance requirement: O(nlogn), n is size.
  //
  void sortByWeightOrder() {
    sortType = "weight";
    sort(terms, terms + size, [](Term a, Term b) {
      return a.weight > b.weight;
    });
  }

 public:
  //
  // default constructor:
  //
  // Called automatically by C++ to create a AutocompleteList.
  // When this is called, intialize terms to a nullptr and set size to 0.
  // Set sortType to "none".
  // Performance requirement: O(1)
  //
  AutocompleteList() {
    terms = nullptr;
    size = 0;
    sortType = "none";
  }

  //
  // a second constructor:
  //
  // Parameter passed in determines size of terms.
  // When this is called, allocate memory for n Terms and
  // set size accordingly.
  // Set sortType to "none".
  // Performance requirement: O(1)
  //
  AutocompleteList(int n) {
    terms = new Term[n];
    sortType = "none";
    size = n;
  }

  //
  // a third constructor:
  //
  // Parameter passed in is name of file to read in.
  // This constructor will build Autocomplete list from file.
  // Assume file format is:
  // line 1: "<size>"
  // lines 2 thru size+1: "weight query"
  // The list should be sorted lexicographic order by the query string.
  // Set sortType to "lex".
  // Performance requirement: O(nlogn), n is size.
  //
  AutocompleteList(string filename) {
    fstream file(filename);
    file >> size;
    terms = new Term[size];

    for (int i = 0; i < size; i++) {
      file >> terms[i].weight;
      getline(file, terms[i].query);
      int j = 0;
      while (terms[i].query[j] == '\t' || terms[i].query[j] == ' ')
        j++;
      terms[i].query = terms[i].query.substr(j);
    }

    sortByLexOrder();
    file.close();
  }

  //
  // copy constructor:
  //
  // Called automatically by C++ to create an AutocompleteList that contains
  // a copy of an existing AutocompleteList.  Example: this occurs when
  // passing AutocompleteList as a parameter by value.
  // Performance requirement: O(n), n is size.
  //
  AutocompleteList(const AutocompleteList& other) {
    size = other.size;
    terms = new Term[size];
    for (int i = 0; i < size; i++) {
      terms[i].weight = other.terms[i].weight;
      terms[i].query = other.terms[i].query;
    }
    sortType = other.sortType;
  }

  //
  // copy operator=
  //
  // Called when you assign one AutocompleteList into another,
  // i.e. this = other;
  // Performance requirement: O(n), n is size.
  //
  AutocompleteList& operator=(const AutocompleteList& other) {
    if (this != &other) {
      delete[] this->terms;
      size = other.size;
      terms = new Term[size];
      for (int i = 0; i < size; i++) {
        terms[i].weight = other.terms[i].weight;
        terms[i].query = other.terms[i].query;
      }
      sortType = other.sortType;
    }
    return *this;
  }

  //
  // destructor:
  //
  // Called automatically by C++ to free the memory associated by the Term.
  //
  virtual ~AutocompleteList() {
    delete[] terms;
  }

  //
  // Public member function.
  // Returns the size of the AutocompleteList.
  // Performance requirement: O(1).
  //
  int getSize() {
    return size;
  }

  //
  // Public member function.
  // Returns Term element in AutocompleteList.
  // This gives public access to Terms stored in the AutocompleteList.
  // If i is out of bounds, throw an out_of_range error message:
  // "AutocompleteList: i out of bounds"
  // Note:  This public function does not necessarily fit the design of this
  // abstraction but we are having you write it for testing purposes.
  // Performance requirement: O(1).
  //
  Term& operator[](int i) {
    if (i < 0 || i >= size)
      throw out_of_range("AutocompleteList: i out of bounds");

    return terms[i];
  }
  // Public member function.
  // Returns an AutocompleteList which stores a list of all Terms that
  // start with the prefix.  The AutocompleteList returned should be sorted
  // in descending order by weight.  Set the returned AutocompleteList's
  // sortType to "weight".
  // If prefix is empty string, return an empty AutocompleteList;
  // If there are no words in the list the start with the prefix, return an
  // empty AutocompleteList.
  // If *this* AutocompleteList's sortType does not equal "lex", then return
  // an empty AutocompleteList.  In other words, allMatches should only be
  // called on an AutocompleteList that is sorted in lexicographic order by
  // the query string.
  // Performance requirement: O(mlogm+logn), n is size and
  // where m is the number of matching terms.
  //
  AutocompleteList allMatches(string prefix) {
    int cnt = numberOfMatches(prefix);
    if (cnt == 0) {
      AutocompleteList result;
      return result;
    } else {
      AutocompleteList result(cnt);
      int idx1 = firstIndexOf(prefix);

      for (int i = 0; i < cnt; i++) {
        result.terms[i].query = terms[idx1 + i].query;
        result.terms[i].weight = terms[idx1 + i].weight;
      }

      result.sortByWeightOrder();

      return result;
    }
  }
  // Public member function.
  // Returns the number of Terms that start with the given prefix.
  // If prefix is empty, return 0.
  // If *this* AutocompleteList's sortType does not equal "lex",
  // then return 0.
  // Performance requirement: O(logn), n is size.
  //
  int numberOfMatches(string prefix) {
    if (prefix.size() == 0 || sortType != "lex")
      return 0;
    int idx1 = firstIndexOf(prefix), idx2 = lastIndexOf(prefix);

    if (idx1 == -1 || idx2 == -1)
      return 0;

    return idx2 - idx1;
  }
  // to use this compontent the user has to type the name of 
  // the text file her wants to find the avg searches of
  void maxNumber() {
      long long int lala = 0;
      for (int i = 0; i < size; i++) {
          lala += terms[i].weight;
      }
      double avg = lala*1.0/size*1.0;
      cout << "Avg no of search in this text file is: " << avg << endl;
  }
  //
  // Public member function.
  // Prints the AutocompleteList.
  // Pad the front of the print with 8 spaces for nicely formatted search:
  // print: "        query, weight".
  // NOTE:  This is also useful for debugging purposes.
  // Performance requirement: O(n), n is size
  //
  void print() {
    for (int i = 0; i < size; i++) {
      cout << "        " << terms[i].query << ", " << terms[i].weight << endl;
    }
  }
};
