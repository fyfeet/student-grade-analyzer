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

