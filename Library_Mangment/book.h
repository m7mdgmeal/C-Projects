#ifndef BOOK_H
#define BOOK_H

#define MAX_SIZE_NAME 50
#define ERROR -1

#define COVER_HEX 0x1
#define INDEX_HEX 0x2
#define MISS_HEX 0x4
#define BAR_CODE_HEX 0x8
#define SPINE_HEX 0x10
#define STAINED_HEX 0x20

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

typedef enum
{
    VARY = 0,
    KIDS,
    HIGHSCHOOL,
    ADULT,
    DOCUMENTARY,
    COMICS
} Zone;

typedef enum
{
    FALSE = 0,
    TRUE
} bool;

typedef enum
{
    DRAMA = 0,
    THRILLER,
    COMEDY,
    NON_FICTION
} Genre_Type;

typedef union Genre {
    struct Drama
    {
        int text_quality;
        int plot_quality;
    } Drama;

    struct Thriller
    {
        float thrilling_factor;

    } Thriller;

    struct Comedy
    {
        int humor_quality;
        char humor_type;
    } Comedy;

    struct Non_Fiction
    {
        char field_book[4];
    } Non_Fiction;

} Genre;

typedef struct Book
{
    int internal_number;
    char name[MAX_SIZE_NAME];
    int promotion;
    Zone zone;
    Genre_Type genre_type;
    Genre genre;
} Book;

typedef struct BookCopy
{
    int internal_number;
    long serial_number;
    bool is_borrowed;
    int borrowing_times;
    char condetions;
} BookCopy;

char *get_zone_name(Zone zone);

void print_book(Book *book);
void print_genre(Book *book);


void print_copy(BookCopy *copy);

int borrow_copy(BookCopy *copy, bool is_borrowing);

void init_copy(BookCopy *copy, int internal_number, char cond);

bool is_librarian_required(BookCopy *copy);

bool is_bookbinder_required(BookCopy *copy);

bool is_repairable(BookCopy *copy);

bool is_ok(BookCopy *copy);

bool is_useless(BookCopy *copy);

bool are_in_same_condition(BookCopy *copy1, BookCopy *copy2);

BookCopy *create_copy(int internal, char cond);
void FREE(BookCopy ***bcopy, unsigned long size);






#endif /* BOOK_H*/