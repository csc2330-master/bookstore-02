//
// Created by arias on 11/25/2019.
//

#ifndef BOOKSTORE_01_LIBRARY_H
#define BOOKSTORE_01_LIBRARY_H

#include "book.h"
#include <string>
using std::string;

// No more Maximum, the size is going to be set
// by the user
// const int MAX_BOOKS = 3;

class Library {
    // _books represent an address to an array of pointers
    Book** _books;
    unsigned int _bookCount;
    // Now we need to remember the maximum number
    // of books we can store
    unsigned int _maxBooks;
public:
    // The constructor now needs to know how
    // many books is going to be able to store
    Library(unsigned int);
    ~Library();
    unsigned int GetCount()const;
    bool AddBook(const Book&);
    bool AddBook(const string&, double);
    int FindBook(const string&)const;
    Book* Get(unsigned int)const;


};


#endif //BOOKSTORE_01_LIBRARY_H
