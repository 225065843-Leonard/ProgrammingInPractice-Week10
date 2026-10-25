#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fp;
    int id = 1001;
    char name[50] = "Maria";
    double salary = 18500.50;
    
    // ==========================================
    // PART 1: WRITING TO A FILE (Save)
    // ==========================================
    // Open file in "w" (write) mode. This creates the file or overwrites it.
    fp = fopen("employees.txt", "w");
    
    // ALWAYS check if the file opened successfully
    if (fp == NULL) {
        printf("Error: Could not create file.\n");
        return 1; // Exit program with error code
    }
    
    // Write data to the file using fprintf (just like printf, but goes to the file)
    fprintf(fp, "%d %s %.2f\n", id, name, salary);
    fprintf(fp, "1002 Simon 17200.00\n"); // Writing a second record
    
    // Close the file! (Very important to save it)
    fclose(fp);
    printf("Data successfully saved to employees.txt\n\n");


    // ==========================================
    // PART 2: READING FROM A FILE (Load)
    // ==========================================
    // Open file in "r" (read) mode
    fp = fopen("employees.txt", "r");
    
    if (fp == NULL) {
        printf("Error: Could not open file for reading.\n");
        return 1;
    }
    
    printf("--- Employee Data Loaded from File ---\n");
    
    int readId;
    char readName[50];
    double readSalary;
    
    // fscanf returns the number of items successfully read. 
    // We expect 3 items (id, name, salary). If it reads 3, we continue looping.
    while (fscanf(fp, "%d %49s %lf", &readId, readName, &readSalary) == 3) {
        printf("ID: %d | Name: %s | Salary: N$%.2f\n", readId, readName, readSalary);
    }
    
    // Close the file when done reading
    fclose(fp);

    return 0;
}