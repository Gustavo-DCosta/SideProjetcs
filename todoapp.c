/*
*This code sucks, it works 70% of the time, do not use it for anything
*/
#include <stdio.h>
#include <string.h>  

void CreateTask();
void SeeTask();
void CheckDonedTask();

int main() {
    char buffer[256];
    char iBuffer[8];
    char *tasks[] = {
        " This code sucks... Like alot"
    };
    int choice;
    printf("Welcome to the greatest todo app in C that has ever lived\n");
    printf("Press: \n");
    printf("1. To create a task \n");
    printf("2. To see the tasks Created \n");
    printf("3. To see the tasks you've already done \n");
    printf("4. Just do ctrl + c to exit bro or just press q\n");

    printf("Todoapp -> ");
    while (1) {
        if (fgets(buffer, sizeof(buffer), stdin)) {
        if (strcmp(buffer, "q") == 0) break;
        if (1 == sscanf(buffer, "%d", &choice)) {
            switch (choice) {
                case 1:
                    CreateTask(&buffer, &tasks);

                    break;
                case 2:
                    SeeTask(&tasks);
                    break;
                case 3: 
                    CheckDonedTask();
                    break;
                default: 
                    printf("Invalid key");
            }
        }
    }
    }
    
}

void CreateTask(char *buffer, char *todo) {
    printf("Please write the tasks you want: ");
    while (1) {
        if (fgets(buffer, sizeof(buffer), stdin)) { 
            if (1 == sscanf(buffer, "%s", todo)) {
                if (strcmp(buffer, "q") == 0) {
                    return;
                }  
                todo = buffer;
                printf("Task added sucessfully\n");
                printf("Todoapp {writting task mode} -> ");
            } 
        }
    }
}

void SeeTask(char *todo) {
    int lenght = sizeof(todo) / sizeof(todo[0]);
    for (int i = 0; i < lenght; i++) {
        printf("%s\n", todo[i]);
    }
}

void CheckDonedTask() {
    printf("Noway");
}
