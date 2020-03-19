// Programmer: Elnathan Yoon
#include <stdio.h>
#include <stdlib.h>
// Part 1: Find any mistakes in code and correct them
void count(void) { // should have void in brackets
    printf("Enter lines of text here: ...\n"); // should be \n
    int c, nc = 0, nt = 0, nl = 0, nbackslash = 0; // missing nl = 0 and nc and nt should = 0
    while ((c = fgetc(stderr)) != EOF) { // can also be (c = getchar(c))
        if (c == '\n') { // should have single brackets '\n'
            ++nl;
        }
        else if (c == '\t') {
            ++nt;
        }
        else if (c == '\\') {
            nbackslash += 1; // this can also be ++nbackslash
        }
        else if (isspace(c)) { ++nc; }
        printf("lines: %d\n", nl); // this should just be printf
        printf("tabs: %d\n", nt);  // this should also be printf and %d
        printf("backslashes: %d\n", nbackslash); // this should be %d
        printf("alphanumeric: %d\n", nc); // this should also be %d
    }
} // was missing a closing bracket

int main(int argc, const char* argv[]) {
    count();
    return 0;
}

// Part 2: The C Standard Library: Identify the standard library functions that do the following…
// (3 pts) (2) Find the first character c in a const char* s:  ____const char* strchr(const char* s, char c);____
// (3 pts) (3) Find the length of the prefix of const char* s that has characters in const char* t: ____size_t strcspn(const char* s, const char* t);____
// (3 pts) (4) Terminate a program immediately: ____void exit(int status)____
// (3 pts) (5) Open the file “midterm.txt” in read mode: ____FILE* fopen("midterm.txt", "r");____

// Using pointers, implement each of the following C standard library functions
size_t strcpy(char* s, const char* t) // (4 pts) (6)
{
    char* p = s;
    while((*s++ = *t++) != '\0') { }
    return p;
}
char* strncat(char* s, const char* t, size_t n) // (4 pts) (7)
{
    char* p = s;
    while (*s != '\0') { ++s; }
    while (n-- > 0 && *t != '\0') { *s++ = *t++; }
    *s = '\0';
    return p;
}
int strcmp(const char* s, const char* t) // (4 pts) (8)
{
    while (*s != '\0' && *t != '\0' && *s == *t) { ++s; ++t; }
    return *s - *t;
}


// PART III: SHORT PROGRAM
// (20 pts) (9) Fill in the program code below for the square ADT(abstract data type)
//------ POINT ----------------------------------------------------------------
typedef struct point point;
struct point { double x, y; };
//------ SQUARE -----------------------------------------------------------------
typedef struct square square;
struct square { point ul; size_t side; };
square* square_init(double ulx, double uly, double side); // TODO
void square_delete(square * sq); // TODO
void square_move(square * sq, double x, double y); // TODO
void square_expandby(square * sq, double expandby); // TODO
double square_area(square * sq); // TODO
double square_perimeter(square* r); // TODO
// print location, side, area and perimeter
void square_print(const char* msg, square* sq); // TODO
void test_square(double ulx, double uly, double side) {
    square* sq = square_init(ulx, uly, side);
    square_print("sq is : ", sq);
    square_move(sq, 2, 2);
    square_print("sq is now : ", sq);
    square_expandby(sq, 10);
    square_print("sq has expanded to : ", sq);
    square_delete(sq);
    printf("\n\n");
}
void tests_square() {
    test_square(0, 0, 10);
    test_square(1, 1, 5);
    // add other tests if you wish // TODO (optional)
}

square* square_init(double ulx, double uly, double side) 
{
    square* box = (square*)malloc(sizeof(square));
    box->side = side;
    box->ul.x = ulx;
    box->ul.y = uly;
    return box;
}
void square_delete(square* sq) 
{
    free(sq);
}
void square_move(square* sq, double x, double y) 
{
    sq->ul.x = x;
    sq->ul.y = y;
}
void square_expandby(square* sq, double expandby) 
{
    sq->side *= expandby;
}
double square_area(square* sq) 
{
    double area;
    area = (sq->side) * (sq->side);
    return area;
}
double square_perimeter(square* r) 
{
    double perimeter;
    perimeter = 4 * (r->side);
}
// print location, side, area and perimeter
void square_print(const char* msg, square* sq) 
{
    printf("\nThe upper left x value is: %.2f", sq->ul.x);
    printf("\nThe upper left y value is: %.2f", sq->ul.y);
    printf("\nThe value of the side is: %.2f", sq->side);
    printf("\nThe value of the area is: %.2f", square_area(sq));
    printf("\nThe value of the perimeter is: %.2f", square_perimeter(sq));
}

int main(int argc, const char* argv[]) {
    tests_square();
    return 0;
}
