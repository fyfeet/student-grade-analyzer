#include <stdio.h>
#include <string.h>

#define MAX_STUDENT 100
#define MAX_SUBS 10

struct Student
{
    int id;
    char name[30];
    float marks[MAX_SUBS];
    float total;
    float average;
    char grade;
};

int n;
int num_sub;
int num_stu;

//=======================
//       Alex (Member 6)
//   File Handling & Main Menu
//=======================

void add_student(struct Student students[]);
void Individual(struct Student students[]);
void classstatistics(struct Student students[]);
void Allresults(struct Student students[]);
void saveToFile(struct Student students[], int count);
int loadFromFile(struct Student students[], int maxSize);
void saveFinalReport(struct Student students[]);

struct Student students[MAX_STUDENT];

void saveToFile(struct Student students[], int count)
{
    FILE *fp = fopen("students.txt", "w");
    if (fp == NULL)
    {
        printf("Error opening file.\n");
        return;
    }
    fprintf(fp, "%d\n", num_sub);
    fprintf(fp, "%d\n", count);
    for (int i = 0; i < count; i++)
    {
        fprintf(fp, "%d\n", students[i].id);
        fprintf(fp, "%s\n", students[i].name);
        for (int j = 0; j < num_sub; j++)
        {
            fprintf(fp, "%.2f\n", students[i].marks[j]);
        }
        fprintf(fp, "%.2f\n", students[i].average);
        fprintf(fp, "%c\n", students[i].grade);
    }
    fclose(fp);
    printf("Saved %d students to file.\n", count);
}

int loadFromFile(struct Student students[], int maxSize)
{
    FILE *fp = fopen("students.txt", "r");
    if (fp == NULL)
    {
        printf("No saved file found.\n");
        return 0;
    }
    int count = 0;
    fscanf(fp, "%d\n", &num_sub);
    fscanf(fp, "%d\n", &count);
    if (count > maxSize)
        count = maxSize;
    for (int i = 0; i < count; i++)
    {
        fscanf(fp, "%d\n", &students[i].id);
        fscanf(fp, " %[^\n]", students[i].name);
        for (int j = 0; j < num_sub; j++)
        {
            fscanf(fp, "%f\n", &students[i].marks[j]);
        }
        fscanf(fp, "%f\n", &students[i].average);
        fscanf(fp, " %c\n", &students[i].grade);
    }
    fclose(fp);
    printf("Loaded %d student(s) from file.\n", count);
    return count;
}

void saveFinalReport(struct Student students[])
{
    if (num_stu == 0)
    {
        printf("No students to save.\n");
        return;
    }
    FILE *fp = fopen("report.txt", "w");
    if (fp == NULL)
    {
        printf("Error creating report.\n");
        return;
    }
    fprintf(fp, "================GRADING RESULTS================\n");
    fprintf(fp, "ID\tName\tMarks\t\tAverage\tGrade\n");
    for (int i = 0; i < num_stu; i++)
    {
        char grades_str[100] = "";
        char temp[10];
        for (int j = 0; j < num_sub; j++)
        {
            sprintf(temp, "%.2f", students[i].marks[j]);
            strcat(grades_str, temp);
            if (j < num_sub - 1)
                strcat(grades_str, ",");
        }
        fprintf(fp, "%d\t%s\t%s\t%.2f\t%c\n",
                students[i].id,
                students[i].name,
                grades_str,
                students[i].average,
                students[i].grade);
    }
    fclose(fp);
    printf("Report saved to report.txt\n");
}

int main()
{
    num_stu = loadFromFile(students, MAX_STUDENT);
    int choice;

    do
    {
        printf("\n--- Student Management System ---\n");
        printf("1. Add Student Data\n");
        printf("2. Individual Result\n");
        printf("3. Show Student score (highest, lowest, average)\n");
        printf("4. Show all result\n");
        printf("5. Save to File\n");
        printf("6. Load from File\n");
        printf("7. Save Final Report\n");
        printf("0. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            add_student(students);
            break;
        case 2:
            Individual(students);
            break;
        case 3:
            classstatistics(students);
            break;
        case 4:
            Allresults(students);
            break;
        case 5:
            saveToFile(students, num_stu);
            break;
        case 6:
            num_stu = loadFromFile(students, MAX_STUDENT);
            if (num_stu > 0)
            {
                printf("\n--- Successfully Loaded Students ---\n");
                Allresults(students);
            }
            break;
        case 7:
            saveFinalReport(students);
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