
#include <stdio.h>
#include <string.h>

int main() {
    FILE *file;
    char id[30];
    char name[100];
    char section[30];
    int choice = 1;

    // Add student records
    while (choice == 1) {

        printf("Enter Student Number: ");
        fgets(id, sizeof(id), stdin);
        id[strcspn(id, "\n")] = '\0';

        printf("Enter Complete Name: ");
        fgets(name, sizeof(name), stdin);
        name[strcspn(name, "\n")] = '\0';

        printf("Enter Section: ");
        fgets(section, sizeof(section), stdin);
        section[strcspn(section, "\n")] = '\0';

        // Open file in append mode
        file = fopen("student_records.txt", "a");

        if (file == NULL) {
            printf("Error opening file!\n");
            return 1;
        }

        // Save student information
        fprintf(file, "ID Number: %s\n", id);
        fprintf(file, "Complete Name: %s\n", name);
        fprintf(file, "Section: %s\n\n", section);

        fclose(file);

        printf("\nRecord added and saved successfully.\n");

        printf("\nAdd another student? [Enter 1 for Yes, 0 for No]: ");
        scanf("%d", &choice);
        getchar();

        printf("\n");
    }

    // Read and display saved records
    file = fopen("student_records.txt", "r");

    if (file == NULL) {
        printf("Error reading file!\n");
        return 1;
    }

    printf("All student records have been saved.\n");
    printf("\n===== STUDENT RECORDS =====\n\n");

    char line[200];

    while (fgets(line, sizeof(line), file) != NULL) {
        printf("%s", line);
    }

    fclose(file);

    return 0;
}
