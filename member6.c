#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 100
#define MAX_SUBS 10

struct Student{
    int id[10];
    char name[30];
    float marks[MAX_SUBS];
    float total;
    float average;
    char grade;
    char userName;
    
};


// global variables
int n;
int num_sub;



struct Student students[MAX_STUDENTS];
void saveToFile(struct Student students[], int count)
{
    FILE *fp = fopen("students.txt", "wb"); // "wb" = overwrite each save
    if (fp == NULL)
    {
        printf("Error opening file.\n");
        return;
    }
    fwrite(students, sizeof(students), count, fp);
    fclose(fp);
    printf("Saved %d student(s) to file.\n", count);
}

int loadFromFile(struct Student students[], int maxSize)
{
    FILE *fp = fopen("students.txt", "rb"); // "rb" = read binary
    if (fp == NULL)
    {
        printf("No saved file found.\n");
        return 0;
    }
    int count = fread(students, sizeof(students), maxSize, fp);
    fclose(fp);
    printf("Loaded %d student(s) from file.\n", count);
    return count;
}


//function prototype
void add_student(struct Student students[]);
char getgrade(float average);
void Individual();

int main()
{
    struct Student list[MAX_STUDENTS];
    int count = 0;
    int choice;

    do
    {
        printf("\n--- Student Management System ---\n");
        printf("1. Add Student Data\n");
        printf("2. Grade Calculation\n");
        printf("3. Individual Result\n");
        printf("4. Show Student score (highest, lowest, average)\n");
        printf("6. Save to File\n");
        printf("7. Load from File\n");
        printf("0. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
            add_student(students);
            break;
            case 2:
            for (int i = 0; i < MAX_STUDENTS; i++) {
            printf("%-5d %-20s %-10.2f %c\n",
            students[i].id,
            students[i].name,
            students[i].average,
            getgrade(students[i].average));
            }
            break;
        //     int target;
        //     int index = -1;
        //     printf("Please enter student id to check the grade: ");
        //     scanf("%d", &target);

        //     for(int i =0; i < MAX_STUDENTS; i++ ){
        //     if(target == students[i].id){
        //         index = i;
        //         break;
        //     }
        //     }
        //     if (index == -1) {
        // printf("Student not found.\n");
        //  } else {
        // printf("Grade: %c\n", getgrade(students[index].average));
        // }
            break;
        case 3:
        
            Individual();
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
