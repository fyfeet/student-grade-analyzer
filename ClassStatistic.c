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