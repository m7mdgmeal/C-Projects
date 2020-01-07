
#define ZERO 0
#define EXIT 9
#define MAX_INTERNAL 50000
#define MAX_SERIAL 1000000000
#define MIN_SERIAL 10000

#include "book.h"

extern Book books[];
extern int books_size;
extern char *get_book_name_by_internal_num(int internal);

typedef enum
{
	INTERNAL = 0,
	SERIAL_NUMBER,
	MENU
} CASE;

typedef enum
{
	ONE = 1,
	TOW
} NUMBER;

char get_conditions();
char get_yes_no(char *msg);

int Get_books_size();

void Print_Books();

void get_input_from_user(BookCopy **copy, int i);

long Is_Valid(long, CASE Case);

void initilise(BookCopy **copies, unsigned long size);

void borrowing_stage(BookCopy **copies, unsigned long size);

int Menu();

long get_copybook_by_serial(BookCopy **copy, unsigned long l, unsigned long r, long serial);

int input_serail_number(BookCopy **copies, int choose);

void allocate_array(BookCopy ***copy, unsigned long *size);

int main()
{

	BookCopy **dymanic_bcopy = NULL;
	unsigned long size;
	int i;


	allocate_array(&dymanic_bcopy, &size);

	Print_Books();

	initilise(dymanic_bcopy, size);

	borrowing_stage(dymanic_bcopy, size);

	printf("\n\n\n");

	for (i = 0; i < size; i++)
	{
		printf("-----------------------\n");
		print_copy(dymanic_bcopy[i]);
		printf(" is_librarian_required :%d\n", is_librarian_required(dymanic_bcopy[i]));
		printf("is_bookbinder_required :%d\n", is_bookbinder_required(dymanic_bcopy[i]));
		printf("is_repairable :%d\n", is_repairable(dymanic_bcopy[i]));
		printf("is_ok :%d\n", is_ok(dymanic_bcopy[i]));
		printf("is_useless :%d\n", is_useless(dymanic_bcopy[i]));
	}
	FREE(&dymanic_bcopy, size);

	return 0;
}

void allocate_array(BookCopy ***copy, unsigned long *size)
{
	do
	{
		printf("Enter Valid size for BookCopy array:\n");
		scanf("%lud", size);
	} while (*size <= 0);

	(*copy) = (BookCopy **)malloc(sizeof(BookCopy *) * (*size));

	if ((*copy) == NULL)
	{
		printf("Can't allocate !!\n");
		exit(1);
	}
}

int Menu()
{
	int choose;
	printf("1. Borrow a book-copy.\n");
	printf("2. Return a book-copy.\n");
	printf("9. Exit.\n");

	do
	{
		printf("Choose one of the following operations:\n");
		scanf("%d", &choose);

	} while (Is_Valid(choose, MENU) == ERROR);

	return choose;
}

void borrowing_stage(BookCopy **copies, unsigned long size)
{
	int choose;
	long index;
	long serial;
	choose = Menu();

	if (choose != EXIT)
	{
		do
		{
			printf("Enter a valid serial number of a copy book:\n");
			scanf("%ld", &serial);
			index = get_copybook_by_serial(copies, 0, size, serial);
		} while (Is_Valid(serial, SERIAL_NUMBER) == ERROR || index == ERROR);
		if (choose == ONE)
		{
			if (borrow_copy(copies[index], TRUE) == ERROR)
				printf("Can't Borrowing the book!,you Arleady Borrowing it!\n");
			else
			{
				printf("Borrowed Seccessfuly\n");
				(copies[index]->borrowing_times)++;
			}
		}
		else
		{
			if (borrow_copy(copies[index], FALSE) == ERROR)
				printf("Can't return the book!,you Did noy borrowing it!\n");
			else
				printf("Returned Seccessfuly\n");
		}

		borrowing_stage(copies, size);
	}
	else
		printf("Good bye,Have a nice Day!\n");
}

void initilise(BookCopy **copies, unsigned long size)
{
	int i;
	for (i = 0; i < size; i++)
	{
		printf("Enter BookCopy %d details:\n", i + 1);
		get_input_from_user(copies, i);
		printf("------------------------------\n");
		print_copy(copies[i]);
		printf("**************************\n");
	}
}

void Print_Books()
{
	int i = 0;
	int size = Get_books_size();
	for (i = 0; i < size; i++)
	{
		printf("---------- Book Id: %d ----------\n",i+1);
		print_book(&books[i]);
		printf("\n\n");
	}
}

long Is_Valid(long value, CASE Case)
{
	switch (Case)
	{
	case INTERNAL:

		if (value <= 0 || value > MAX_INTERNAL)
			return ERROR;

		if (get_book_name_by_internal_num((int)value) == NULL)
			return ERROR;
		return value;

	case SERIAL_NUMBER:
		if (value < MIN_SERIAL || value > MAX_SERIAL)
			return ERROR;
		return value;

	case MENU:
		if (value == 1 || value == 2 || value == 9)
			return value;
		return ERROR;
		break;
	default:
		return ERROR;
	}
}

long get_copybook_by_serial(BookCopy **copy, unsigned long l, unsigned long r, long serial)
{
	while (l <= r)
	{
		unsigned long m = l + (r - l) / 2;

		if (copy[m]->serial_number == serial)
			return (long)m;

		if (copy[m]->serial_number < serial)
			l = m + 1;

		else
			r = m - 1;
	}

	return -1;
}

char get_conditions()
{
	char answer, condition = 0x0;

	answer = get_yes_no("Is there any problem in its cover?");
	if (answer == 'y' || answer == 'Y')
		condition = condition | COVER_HEX;

	answer = get_yes_no("Is there any problem in its indexing?");
	if (answer == 'y' || answer == 'Y')
		condition = condition | INDEX_HEX;

	answer = get_yes_no("Are there any missing pages in it?");
	if (answer == 'y' || answer == 'Y')
		condition = condition | MISS_HEX;

	answer = get_yes_no("Are there any problems in its bar-code?");
	if (answer == 'y' || answer == 'Y')
		condition = condition | BAR_CODE_HEX;

	answer = get_yes_no("Is its spine broken?");
	if (answer == 'y' || answer == 'Y')
		condition = condition | SPINE_HEX;

	answer = get_yes_no("Are there any stained pages?");
	if (answer == 'y' || answer == 'Y')
		condition = condition | COVER_HEX;

	return condition;
}
char get_yes_no(char *msg)
{
	char x;
	do
	{
		printf("%s,(answe with Y/y or n/N)! \n", msg);
		getchar();

		scanf(" %c", &x);
	} while (x != 'n' && x != 'N' && x != 'Y' && x != 'y');
	return x;
}

void get_input_from_user(BookCopy **copy, int index)

{
	int internail;
	char cond;
	do
	{
		printf("Enter a valid internal book number:\n");
		scanf("%d", &internail);
	} while (Is_Valid(internail, INTERNAL) == ERROR);

	cond = get_conditions();
	copy[index] = create_copy(internail, cond);
	printf("A copy of a book added susseccfuly\n");
}

int Get_books_size()
{
	return books_size;
}
