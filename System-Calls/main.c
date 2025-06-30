#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t pid;
    int status;

    printf("\n--- Process Management: fork(), exec(), wait(), sleep() ---\n");

    pid = fork();

    if (pid < 0) {
        perror("fork failed");
        return 1;
    } else if (pid == 0) {
        // Child process
        printf("\n[Child] Process created using fork(). PID: %d\n", getpid());
        printf("[Child] Parent PID: %d\n", getppid());

        printf("[Child] Sleeping for 3 seconds...\n");
        sleep(3);

        printf("[Child] Now executing 'ls -l' using execvp()...\n");

        char *args[] = {"ls", "-l", NULL};
        execvp("ls", args);

        perror("[Child] execvp failed");
        return 1;
    } else {
        // Parent process
        printf("\n[Parent] Waiting for child process (PID: %d) to finish using wait()...\n", pid);
        wait(&status);
        printf("[Parent] Child process finished with exit status: %d\n", WEXITSTATUS(status));
    }

    printf("\n--- File Management: open(), write(), read(), close() ---\n");

    int fd1, fd2;
    char write_buf[100] = "Initial content written by parent process.\n";
    char read_buf[200];

    // Open/Create first file
    fd1 = open("file1.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
    if (fd1 < 0) {
        perror("Error opening file1.txt");
        return 1;
    }

    // Write to first file
    write(fd1, write_buf, strlen(write_buf));

    printf("\n[Parent] Enter additional text to write to file1.txt: ");
    fgets(write_buf, sizeof(write_buf), stdin);
    write(fd1, write_buf, strlen(write_buf));

    // Reset file pointer to beginning
    lseek(fd1, 0, SEEK_SET);

    // Read from first file
    int bytesRead = read(fd1, read_buf, sizeof(read_buf) - 1);
    if (bytesRead < 0) {
        perror("Error reading from file1.txt");
        close(fd1);
        return 1;
    }
    read_buf[bytesRead] = '\0';  // Null terminate

    // Open/Create second file
    fd2 = open("file2.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
    if (fd2 < 0) {
        perror("Error opening file2.txt");
        close(fd1);
        return 1;
    }

    // Write content from file1 to file2
    write(fd2, read_buf, strlen(read_buf));

    // Close both files
    close(fd1);
    close(fd2);

    printf("\n[Parent] Contents copied from file1.txt to file2.txt successfully.\n");

    printf("\n--- Program Finished ---\n");

    return 0;
}
