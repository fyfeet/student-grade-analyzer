#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 100

typedef struct
{
    int id;
    char name[50];
    float score;
} student;

void saveToFile(student s[], int count)
{
    FILE *fp = fopen("students.txt", "wb"); // "wb" = overwrite each save
    if (fp == NULL)
    {
        printf("Error opening file.\n");
        return;
    }
    fwrite(s, sizeof(student), count, fp);
    fclose(fp);
    printf("Saved %d student(s) to file.\n", count);
}

int loadFromFile(student s[], int maxSize)
{
    FILE *fp = fopen("students.txt", "rb"); // "rb" = read binary
    if (fp == NULL)
    {
        printf("No saved file found.\n");
        return 0;
    }
    int count = fread(s, sizeof(student), maxSize, fp);
    fclose(fp);
    printf("Loaded %d student(s) from file.\n", count);
    return count;
}

int main()
{
    student list[MAX_STUDENTS];
    int count = 0;
    int choice;

    do
    {
        printf("\n--- Student Management System ---\n");
        printf("1. Add Student Data\n");
        printf("2. Grade Calculation\n");
        printf("3. Search Student ID\n");
        printf("4. Show Student score (highest, lowest, average)\n");
        printf("6. Save to File\n");
        printf("7. Load from File\n");
        printf("0. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            // TODO: hook up to teammate's "add student" function
            break;
        case 2:
            // TODO: hook up to teammate's "grade calculation" function
            break;
        case 3:
            // TODO: hook up to teammate's "search by ID" function
            break;
        case 4:
            // TODO: hook up to teammate's "show stats" function
            break;
        case 6:
            saveToFile(list, count);
            break;
        case 7:
            count = loadFromFile(list, MAX_STUDENTS);
            break;
        case 0:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice.\n");
        }
    } while (choice != 0);

    return 0;
}
