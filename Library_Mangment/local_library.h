#ifndef LOCAL_LIBRARY_H
#define LOCAL_LIBRARY_H


#include "book.h"
#include <stdio.h>
Book * const get_first_book();
int get_books_size();
int binarySearch(int l, int r, int x) ;
char * get_book_name_by_internal_num(int internal);


#endif /* LOCAL_LIBRARY_H*/