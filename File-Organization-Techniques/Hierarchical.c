#include <stdio.h>
#include <string.h>

#define MAX_DIRS 5
#define MAX_FILES 5

struct File {
    char name[20];
};

struct Directory {
    char name[20];
    struct File files[MAX_FILES];
    int fileCount;
};

struct Directory directories[MAX_DIRS];
int dirCount = 0;

void createDirectory() {
    if (dirCount >= MAX_DIRS) {
        printf("Directory limit reached!\n");
        return;
    }
    printf("Enter directory name: ");
    scanf("%s", directories[dirCount].name);
    directories[dirCount].fileCount = 0;
    dirCount++;
    printf("Directory created successfully.\n");
}

void createFile() {
    char dirName[20];
    printf("Enter directory name: ");
    scanf("%s", dirName);

    for (int i = 0; i < dirCount; i++) {
        if (strcmp(directories[i].name, dirName) == 0) {
            if (directories[i].fileCount >= MAX_FILES) {
                printf("Directory is full!\n");
                return;
            }
            printf("Enter file name: ");
            scanf("%s", directories[i].files[directories[i].fileCount].name);
            directories[i].fileCount++;
            printf("File created successfully.\n");
            return;
        }
    }
    printf("Directory not found!\n");
}

void listFiles() {
    char dirName[20];
    printf("Enter directory name: ");
    scanf("%s", dirName);

    for (int i = 0; i < dirCount; i++) {
        if (strcmp(directories[i].name, dirName) == 0) {
            printf("Files in directory %s:\n", dirName);
            for (int j = 0; j < directories[i].fileCount; j++) {
                printf("%s\n", directories[i].files[j].name);
            }
            return;
        }
    }
    printf("Directory not found!\n");
}

int main() {
    int choice;
    while (1) {
        printf("\n--- Hierarchical Directory ---\n");
        printf("1. Create Directory\n2. Create File\n3. List Files\n4. Exit\nEnter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: createDirectory(); break;
            case 2: createFile(); break;
            case 3: listFiles(); break;
            case 4: return 0;
            default: printf("Invalid choice!\n");
        }
    }
    return 0;
}
