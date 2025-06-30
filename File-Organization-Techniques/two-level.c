#include <stdio.h>
#include <string.h>

#define MAX_USERS 5
#define MAX_FILES 5

struct File {
    char name[20];
};

struct User {
    char name[20];
    struct File files[MAX_FILES];
    int fileCount;
};

struct User users[MAX_USERS];
int userCount = 0;

void createUser() {
    if (userCount >= MAX_USERS) {
        printf("User limit reached!\n");
        return;
    }
    printf("Enter username: ");
    scanf("%s", users[userCount].name);
    users[userCount].fileCount = 0;
    userCount++;
    printf("User created successfully.\n");
}

void createFile() {
    char username[20];
    printf("Enter username: ");
    scanf("%s", username);

    for (int i = 0; i < userCount; i++) {
        if (strcmp(users[i].name, username) == 0) {
            if (users[i].fileCount >= MAX_FILES) {
                printf("User directory is full!\n");
                return;
            }
            printf("Enter file name: ");
            scanf("%s", users[i].files[users[i].fileCount].name);
            users[i].fileCount++;
            printf("File created successfully.\n");
            return;
        }
    }
    printf("User not found!\n");
}

void listFiles() {
    char username[20];
    printf("Enter username: ");
    scanf("%s", username);

    for (int i = 0; i < userCount; i++) {
        if (strcmp(users[i].name, username) == 0) {
            printf("Files of user %s:\n", username);
            for (int j = 0; j < users[i].fileCount; j++) {
                printf("%s\n", users[i].files[j].name);
            }
            return;
        }
    }
    printf("User not found!\n");
}

int main() {
    int choice;
    while (1) {
        printf("\n--- Two Level Directory ---\n");
        printf("1. Create User\n2. Create File\n3. List Files\n4. Exit\nEnter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: createUser(); break;
            case 2: createFile(); break;
            case 3: listFiles(); break;
            case 4: return 0;
            default: printf("Invalid choice!\n");
        }
    }
    return 0;
}
