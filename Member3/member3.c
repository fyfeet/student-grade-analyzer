#include <stdio.h>
#define MAX_STUDENT 100
#define MAX_SUBS 10
#define FILENAME "students. txt"
#define FILENAME "finalreport.txt"
int num_stu;
int num_sub;
struct Student{
    char id[10];
    char name[30];
    float marks[MAX_SUBS];
    float total;
    float average;
    char grade;
    char userName;
};
struct Student students [MAX_STUDENT];
char getgrade(float average){
    if(average>=90){ return 'A'; }
    else if(average >=80){ return 'B'; }
    else if (average >= 70){return 'C'; }
    else if (average >= 60){return 'D'; }
    else if (average >=50){return 'E'; }
    else {return 'F';}
}
void Individual(){
    char search_Id[10];
    int found =0;
    printf("Enter Student ID : ");
    scanf("%s", search_Id);
    if( num_stu !=1){
        printf("No student yet!");
    }

    for(int i =0;i<num_stu;i++){
        if(strcmp(search_Id, students[i].id)==0){
            printf("==================================\n");
            printf("Student name : %s\n", students[i].name);
            printf("ID : %s\n", students[i].id);
            for(int j =0;j<num_sub;i++){
                printf("mark %d : %f\n", j+1, students[i].marks);

            }
            printf("Total marks : %.2f\n", students[i].total);
            printf("Average : %.2f\n", students[i].average);
            printf("Grade : %c", students[i].grade);

        }
        found =1;
        break;
    }
    if(!found){
        printf("Student with id %s is not found\n", search_Id);
    }
}


int main() {


    return 0;

}