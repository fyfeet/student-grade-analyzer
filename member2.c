#include <stdio.h>

// constants
#define MAX_STUDENT 100
#define MAX_SUBS 10
#define FILENAME "students.txt"

// global variables
int n;
int num_sub;

// struct
struct Student {
    int id;
    char name[30];
    float grades[MAX_SUBS];
    float average;
};

void add_student(struct Student students[]) {
    int i, j;
    float total;

    // Input number of students
    printf("Enter number of students (1-%d): ", MAX_STUDENT);
    scanf("%d", &n);

    while (n < 1 || n > MAX_STUDENT) {
        printf("Invalid! Enter again: ");
        scanf("%d", &n);
    }

    // Input number of subjects
    printf("Enter number of subjects (1-%d): ", MAX_SUBS);
    scanf("%d", &num_sub);

    while (num_sub < 1 || num_sub > MAX_SUBS) {
        printf("Invalid! Enter again: ");
        scanf("%d", &num_sub);
    }

    // Loop for students
    for (i = 0; i < n; i++) {
        total = 0;

        printf("\n--- Student %d ---\n", i + 1);

        printf("Enter ID: ");
        scanf("%d", &students[i].id);

        printf("Enter Name: ");
        scanf(" %[^\n]", students[i].name);

        // Input grades
        for (j = 0; j < num_sub; j++) {
            printf("Enter mark for Subject %d: ", j + 1);
            scanf("%f", &students[i].grades[j]);

            // Validation
            while (students[i].grades[j] < 0 ||
                   students[i].grades[j] > 100) {
                printf("Invalid! Enter mark (0-100): ");
                scanf("%f", &students[i].grades[j]);
            }

            total += students[i].grades[j];
        }

        // Calculate average
        students[i].average = total / num_sub;

        printf("Average = %.2f\n", students[i].average);
    }
}

void main() {
    struct Student students[MAX_STUDENT];

    add_student(students);
}











































































































































































































































