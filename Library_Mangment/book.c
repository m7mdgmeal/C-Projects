#include "book.h"

static char *array_zone[] = {
    "Vary", "Kids", "Higshcool", "Adult", "Documentary", "Comics"};


static void print_drama(Book * book){
    printf("I am a gerne from Drama type:\n");
    printf("%d is the text quality.\n",book->genre.Drama.text_quality);
    printf("%d is the polt quality.\n",book->genre.Drama.plot_quality);
}

static void print_comedy(Book * book){
    printf("I am a gerne from Comedy type:\n");
    printf("%d is the Quality Of The Humo.\n",book->genre.Comedy.humor_quality);
    printf("%c is the Type Of The Humo.\n",book->genre.Comedy.humor_type);
}

static void print_Non_Fiction(Book * book)
{
    printf("I am a gerne from Non_Ficition type:\n");
    printf("%s is the field book.\n",book->genre.Non_Fiction.field_book);
}

static void print_thrilling(Book *book)
{
    printf("I am a gerne from thrilling type:\n");
    printf("%f is the thrilling factor.\n",book->genre.Thriller.thrilling_factor);    
}
void print_genre(Book *book)
{
    if(book->genre_type==COMEDY)
        print_comedy(book);
    else if(book->genre_type==NON_FICTION)
        print_Non_Fiction(book);
    else if(book->genre_type == THRILLER)
        print_thrilling(book);
    else if(book->genre_type == DRAMA)
        print_drama(book);
}
void print_book(Book *book)
{
    printf("Book name: %s\n", book->name);
    printf("Book internal number: %d\n", book->internal_number);
    printf("Book promotion: %d\n", book->promotion);
    printf("Book Zone type: %s\n", get_zone_name(book->zone));

    print_genre(book);
}

char *get_zone_name(Zone zone)
{
    return array_zone[zone];
}

void print_copy(BookCopy *copy)
{

    printf("Book internal number: %d\n", copy->internal_number);
    printf("Book serial number : %ld\n", copy->serial_number);
    switch (copy->is_borrowed)
    {
    case FALSE:
        printf("The book not borrowed\n");
        break;
    case TRUE:
        printf("The book is borrowed\n");
        break;
    default:
        printf("Unacpected staus!\n");
    }
    printf("Borrowing times: %d\n ", copy->borrowing_times);
    printf("%x is the condetion\n",copy->condetions);
}

int borrow_copy(BookCopy *copy, bool is_borrowing)
{
    bool result = !is_borrowing != !copy->is_borrowed;
    switch (result)
    {
    case TRUE:
        copy->is_borrowed = is_borrowing;
        return TRUE;
    case FALSE:
        return -1;
    default:
        return -1;
    }
}

void init_copy(BookCopy *copy, int internal_number,char cond)
{
    static long serial_numer = 10000;
    copy->internal_number = internal_number;
    copy->is_borrowed = FALSE;
    copy->serial_number = serial_numer;
    serial_numer++;
    copy->condetions = cond;
    copy->borrowing_times=0;
}

BookCopy * create_copy(int internal,char cond){
    BookCopy * bcopy=NULL;
    bcopy = (BookCopy *) malloc (sizeof(BookCopy));

    if(bcopy == NULL)
    {
        printf("There is no enoght memory to allocate!!\n");
        exit(1);
    }
    init_copy(&bcopy[0],internal,cond);

    return &bcopy[0];
}

bool is_bookbinder_required(BookCopy *copy)
{
    if ((copy->condetions & SPINE_HEX) != 0 || (copy->condetions & MISS_HEX) != 0 || (copy->condetions & STAINED_HEX) != 0)
        return TRUE;
    return FALSE;
}

bool is_librarian_required(BookCopy *copy)
{
    if ((copy->condetions & COVER_HEX) != 0 || (copy->condetions & INDEX_HEX) != 0 || (copy->condetions & BAR_CODE_HEX) != 0)
        return TRUE;
    return FALSE;
}

bool is_repairable(BookCopy *copy)
{
    if ((copy->condetions & MISS_HEX) == 0 && (copy->condetions & STAINED_HEX) == 0)
        return TRUE;
    return FALSE;
}

bool is_ok(BookCopy *copy)
{
    if (is_bookbinder_required(copy) == FALSE && is_librarian_required(copy) == FALSE)
        return TRUE;
    return FALSE;
}

bool is_useless(BookCopy *copy)
{
    if ((copy->condetions & 0xF )== 0xF)
        return TRUE;
    else if ((copy->condetions & 0x17) == 0x17)
        return TRUE;
    else if ((copy->condetions & 0x27) == 0x27)
        return TRUE;
    else if ((copy->condetions & 0x1D )== 0x1D)
        return TRUE;
    else if ((copy->condetions & 0x2D) == 0x2D)
        return TRUE;
    else if ((copy->condetions & 0x39) == 0x39)
        return TRUE;
    else if ((copy->condetions & 0x1E) == 0x1E)
        return TRUE;
    else if ((copy->condetions & 0x2E) == 0x2E)
        return TRUE;
    else if ((copy->condetions & 0x3A) == 0x3A)
        return TRUE;
    else if ((copy->condetions & 0x3C )== 0x3C)
        return TRUE;
    return FALSE;
}

bool are_in_same_condition(BookCopy *copy1, BookCopy *copy2)
{
    if ((copy1->condetions & COVER_HEX) != (copy2->condetions & COVER_HEX))
        return FALSE;
    if ((copy1->condetions & INDEX_HEX) != (copy2->condetions & INDEX_HEX))
        return FALSE;

    if ((copy1->condetions & MISS_HEX) != (copy2->condetions & MISS_HEX))
        return FALSE;

    if ((copy1->condetions & BAR_CODE_HEX) != (copy2->condetions & BAR_CODE_HEX))
        return FALSE;

    if ((copy1->condetions & SPINE_HEX) != (copy2->condetions & SPINE_HEX))
        return FALSE;

    if ((copy1->condetions & STAINED_HEX) != (copy2->condetions & STAINED_HEX))
        return FALSE;

    return TRUE;
}
void FREE(BookCopy *** bcopy, unsigned long size)
{
    int i;
    for(i=0;i<size;i++)
        free((*bcopy)[i]);
    free(*bcopy);
    
}
