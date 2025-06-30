#include <stdio.h>
#include <string.h>

#define MAX_FILES 10

struct File {
    char name[20];
};

struct File directory[MAX_FILES];
int fileCount = 0;

void createFile() {
    if (fileCount >= MAX_FILES) {
        printf("Directory is full!\n");
        return;
    }
    printf("Enter file name: ");
    scanf("%s", directory[fileCount].name);
    fileCount++;
    printf("File created successfully.\n");
}

void listFiles() {
    printf("\nFiles in Single Level Directory:\n");
    for (int i = 0; i < fileCount; i++) {
        printf("%s\n", directory[i].name);
    }
}

int main() {
    int choice;
    while (1) {
        printf("\n--- Single Level Directory ---\n");
        printf("1. Create File\n2. List Files\n3. Exit\nEnter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: createFile(); break;
            case 2: listFiles(); break;
            case 3: return 0;
            default: printf("Invalid choice!\n");
        }
    }
    return 0;
}
