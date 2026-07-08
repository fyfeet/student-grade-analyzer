#include <stdio.h>

// constants
#define MAX_STUDENT 100
#define MAX_SUBS 10
#define FILENAME "students.txt"

// global variables
int n;
int num_sub;

// struct 
struct Student
{
    int id;
    char name[30];
    float grades[MAX_SUBS];
    float average;
};

void main() {
    // array
    struct Student students[MAX_STUDENT];
}