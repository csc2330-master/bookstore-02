//
// Created by arias on 11/25/2019.
//

#include "library.h"


Library::Library(unsigned int maxBooks): _bookCount(0), _maxBooks(maxBooks){
    // Create the array of _maxBooks pointers to Book
    _books = new Book*[_maxBooks];
    // Initialize each element to nullptr
    for (int i = 0; i < _maxBooks; ++i) {
        _books[i] = nullptr;
    }
}
Library::~Library(){
    // Release the memory for each book on the array
    for (int i = 0; i < _bookCount; ++i) {
        if (_books[i] != nullptr)
            delete _books[i];
    }
    // Release the array itself
    delete[] _books;
}
unsigned int Library::GetCount()const{
    return _bookCount;
}
bool Library::AddBook(const Book& book){
    if (_bookCount == _maxBooks)
        return false;
    _books[_bookCount] = new Book(book);
    _bookCount++;
    return true;
}
bool Library::AddBook(const string& name, double price){
    if (_bookCount == _maxBooks)
        return false;
    _books[_bookCount] = new Book(name, price);
    _bookCount++;
    return true;
}
int Library::FindBook(const string& name)const{
    Book toFind(name, 0);
    for (int i = 0; i < _bookCount; ++i) {
//        if (toFind.Equals(*_books[i]))
        if (_books[i]->Equals(toFind))
            return i;
    }
    return -1;
}
Book* Library::Get(unsigned int index)const{
    if (index >= _bookCount)
        return nullptr;
    else
        return _books[index];
}
