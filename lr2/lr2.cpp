//Разработка программного модуля, описывающего работу книжного магазина с использованием структур языка C.

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include<malloc.h>
#define LENGHT 100
#define standart "no_name"

//структура, поля которой передаются в главную
typedef struct
{
    char title[LENGHT];
    int year;
    double price;
}books;

//главная структура
typedef struct
{
    double profit;
    double loss;
    double packaging;
    books book;
}bookshop;

//ф-ция инициализации
bookshop init(double p, double l, int y, double pr)
{
    bookshop check;
    check.profit = p;
    check.loss = l;
    check.packaging = 10;
    strcpy_s(check.book.title, standart);
    check.book.year = y;
    check.book.price = pr;
    return check;
}

//ф-ция ввода
bookshop input()
{
    bookshop ver;
    ver = init(0,0,0,0);
    rewind(stdin);
    printf("\nInput title: \t\t\t");
    gets_s(ver.book.title);
    printf("Input year of publication: \t");
    scanf("%d", &ver.book.year);
    printf("Input price of book: \t\t");
    scanf("%lf", &ver.book.price);
    return ver;
}

//ф-ция вывода
void output(bookshop check)
{
    printf("Store profit: \t\t\t%lf\n", check.profit);
    printf("Store losses: \t\t\t%lf\n", check.loss);
    printf("Package price: \t\t\t%lf\n", check.packaging);
    printf("Book's title: \t\t\t%s\n", check.book.title);
    printf("Book's years of publication: \t%d\n", check.book.year);
    printf("Book's price: \t\t\t%lf\n", check.book.price);
}

//ф-ция сложения
void add_price(bookshop book1, bookshop book2)
{
    double sum;
    sum = book1.book.price + book2.book.price;
    printf("\nTotal price of books: \t\t%lf", sum);
    printf("\nTotal loss: \t\t\t20");
}

//ф-ция, опис. процесс упаковки
bookshop packaging(bookshop check)
{
    check.loss = check.loss + check.packaging;
    printf("The book is packed\n");
    return check;
}

//ф-ция, опис. процесс продажи
bookshop sale(bookshop check)
{
    check.profit += check.book.price;
    check.loss -= check.packaging;
    strcpy_s(check.book.title, standart);
    check.book.year = 0;
    check.book.price = 0;
    return check;
}


int main()
{
    bookshop book1, book2;
   
    book1 = init( 0, 0, 0, 0);
    book2 = init( 0, 0, 0, 0);
    
    printf("Initialization: \n");
    output(book1);
    printf("\n");

    printf("Input information about 1 book");
    book1 = input();

    printf("\nBook packaging: \n");
    output(book1);

    book1 = packaging(book1);

    printf("\nBook sales: \n");
    output(book1);

    printf("\n");
    printf("Input information about 2 book");
    book2 = input();

    printf("\nBook packaging: \n");
    output(book2);

    book2 = packaging(book2);

    printf("\nBook sales: \n");
    output(book2);

    add_price(book1, book2);

    book1 = sale(book1);

    printf("\n\nAfter sale 1 book: \n");
    output(book1);

    book2 = sale(book2);

    printf("\nAfter sale 2 book: \n");
    output(book2);

    //работа с дин. переменными
    bookshop* Book1, *Book2;
    printf("\n\nWorking with dinamic variables\n");
    Book1 = (bookshop*)malloc(LENGHT * sizeof(bookshop));
    Book1 = &(init(0, 0, 0, 0));
    Book2 = (bookshop*)malloc(LENGHT * sizeof(bookshop));
    Book2 = &(init(0, 0, 0, 0));

    printf("\nInitialization: \n");
    output(*Book2);
    printf("\n");

    printf("Input information about 1 book");
    Book1 = &(input());

    printf("\nBook packaging: \n");
    output(*Book1);

    Book1 = &(packaging(*Book1));

    printf("\nBook sales: \n");
    output(*Book1);

    printf("\n");
    printf("Input information about 2 book");
    Book2 = &(input());

    printf("\nBook packaging: \n");
    output(*Book2);

    Book2 = &(packaging(*Book2));

    printf("\nBook sales: \n");
    output(*Book2);

    add_price(*Book1, *Book2);

    Book1 = &(sale(*Book1));

    printf("\n\nAfter sale 1 book: \n");
    output(*Book1);

    Book2 = &(sale(*Book2));

    printf("\nAfter sale 2 book: \n");
    output(*Book2);

    printf("\n\nDynanmic variable addresses:\t");
    printf("%p   %p", Book1, Book2);

    return 0;
}