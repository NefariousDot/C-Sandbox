/**
 * This program demonstrates cross-platform signal handling and resource cleanup for temporary files. 
 * It registers a signal handler to intercept SIGINT (triggered by Ctrl+C) and removes dynamically allocated 
 * temporary files from the file system. The implementation uses conditional compilation to handle signal 
 * processing differently for Windows and POSIX systems, ensuring compatibility across both platforms. 
 * Temporary files are stored in a linked list, making it easy to manage and delete them efficiently when 
 * the program exits or is interrupted.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#ifdef _WIN32
#include <io.h> // For unlink on Windows
#else
#include <unistd.h> // For unlink on POSIX
#endif

// Define the temp_file structure
struct temp_file {
    char name[256];
    struct temp_file *next;
};

// Global list of temporary files
struct temp_file *temp_file_list = NULL;

// Signal handler for cleanup
void terminationHandler(int sigNum) {
    struct temp_file *p = temp_file_list;
    while (p) {
        if (unlink(p->name) == -1) {
            perror("Error deleting temporary file");
        }
        struct temp_file *toFree = p;
        p = p->next;
        free(toFree);
    }
    temp_file_list = NULL;
    printf("\nTemporary files cleaned up. Exiting...\n");
    exit(0);
}

void setupSignalHandler() {
#ifdef _WIN32
    // Use signal() on Windows
    if (signal(SIGINT, terminationHandler) == SIG_ERR) {
        fprintf(stderr, "Error setting signal handler on Windows.\n");
        exit(EXIT_FAILURE);
    }
#else
    // Use sigaction() on POSIX systems
    struct sigaction newAction;
    newAction.sa_handler = terminationHandler;
    sigemptyset(&newAction.sa_mask);
    newAction.sa_flags = 0;
    if (sigaction(SIGINT, &newAction, NULL) == -1) {
        perror("Error setting signal handler on POSIX");
        exit(EXIT_FAILURE);
    }
#endif
}

int main() {
    // Set up the appropriate signal handler
    setupSignalHandler();

    // Simulate temporary file creation
    for (int i = 0; i < 5; i++) {
        struct temp_file *newFile = malloc(sizeof(struct temp_file));
        if (!newFile) {
            perror("Error allocating memory");
            exit(EXIT_FAILURE);
        }
        snprintf(newFile->name, sizeof(newFile->name), "temp_file_%d.tmp", i);
        newFile->next = temp_file_list;
        temp_file_list = newFile;
        printf("Created temporary file: %s\n", newFile->name);
    }

    printf("Press Ctrl+C to clean up and exit.\n");
    while (1);  // Simulate a long-running process

    return 0;
}
