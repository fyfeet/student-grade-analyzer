<<<<<<< HEAD
#include <stdio.h>
#include <string.h>
#define MAX_STUDENT 100
#define MAX_SUBS 20
struct Student{
    char name[50];
    char id[10];
    float mark[MAX_SUBS];
    float average;
    
};
struct Student students[MAX_STUDENT];
int num_sub=0;
int n ;
void classstatistics() {
     float max_avg = students[0].average;
     float min_avg = students[0].average;
     float class_sum = 0;
     for(int i = 0; i < n; i++) {
         if(students[i].average > max_avg) {
             max_avg = students[i].average;
         }
         if(students[i].average < min_avg) {
             min_avg = students[i].average;
         }
         class_sum += students[i].average;
     }
     float class_avg = class_sum / n;
     printf("\n========== CLASS STATISTICS ==========\n");
     printf("Highest Average: %.2f\n", max_avg);
     printf("Lowest Average:  %.2f\n", min_avg);
     printf("Class Average:   %.2f\n", class_avg);
     printf("=====================================\n");
}
=======
# Students-grading-analyize
 

void saveToFile(student s, int count){
    FILE *fp= fopen("studentinfo", "ab");
    if (fp == NULL) {
        printf("Error opening file.\n");
        return;
    }
    fwrite(s , sizeof(student), count, fp);
    fclose(fp);
}


int loadFromFile(student *s, int maxSize){
    FILE *fp = fopen("students.txt", "rb");   // "rb" = read binary
    if (fp == NULL) {
        printf("No saved file found.\n");
        return 0;
    }
    int count = fread(s, sizeof(student), maxSize, fp);
    fclose(fp);
    return count;

}

int main() {
    int choice;
    do {
        printf("\n--- Student Management System ---\n");
        printf("1. Add Student Data\n");
        printf("2. Grade Calculation\n");
        printf("3. Search Student ID\n");
        printf("4. Show Student score(highest, lowest, Average)\n");
        printf("6. Save to File\n");
        printf("7. Load from File\n");
        printf("0. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
            break;
            case 2:
            break;
            case 3:
            break;
            case 4:
            break;
            case 5:
            break;
            case 6: saveToFile(s, count); break;
            case 7: loadFromFile(s, maxSize); break;
            case 0: printf("Exiting...\n"); break;
            default: printf("Invalid choice.\n");
        }
    } while (choice != 0);
    return 0;
}

>>>>>>> ella
