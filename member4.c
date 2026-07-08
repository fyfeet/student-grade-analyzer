#include <stdio.h>
#include <string.h>
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
    char grade;
};
struct Student students[MAX_STUDENT];

void Allresults(){
    if (n==0){
        printf ("\nNo student yet\n");
        return;
    }

    printf ("\n================GRADING RESULTS================\n");
    printf ("ID\tName\t\tGrades\t\tAverage\tGrade\n");
    for (int i=0; i<n; i++){
        float total = 0;
        char grades_str[100]= "";
        char temp[10];
        
        for (int j=0; j<num_sub; j++){
            total += students[i].grades[j];
            sprintf(temp, "%.2f", students[i].grades[j]);
            strcat(grades_str,temp);
            if(j< num_sub - 1){
                strcat(grades_str,",");
            }
        }

        students[i].average = total/num_sub;

        if (students[i].average >= 90) students[i].grade = 'A';
        else if (students[i].average >=80) students[i].grade = 'B';
        else if (students[i].average >=70) students[i].grade = 'C';
        else if (students[i].average >=60) students[i].grade = 'D';
        else students[i].grade = 'F';

        printf ("%d\t%s\t%s\t%.2f\t%c\n", 
        students[i].id,
        students[i].name,
        grades_str,
        students[i].average,
        students[i].grade);
    }
}

void main() {
    // array
    struct Student students[MAX_STUDENT];
    Allresults();
}