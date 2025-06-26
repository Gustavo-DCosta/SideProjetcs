#include <stdio.h>

int Mod(int *x);
int Factorial(int *y);
void CreatFile();
void ReadFile();
void AppendToFile();

int main() {
    char *MyStr = "Hello World";
    int num = 10;
    int var = 5;
    int result = Mod(&num);
    int fact = Factorial(&var);
    printf("%s\n", MyStr);
    printf("%d\n", result);
    printf("%d\n", fact);

    CreatFile();
    AppendToFile();
    ReadFile();

    return 0;
}

int Mod(int *x) {
    *x = 45;
    return *x;
}

int Factorial(int *y) {
    if (*y > 0) {
        int i = *y - 1;
        return *y * Factorial(&i);
    } else {
        return 1;
    }
}

void CreatFile() {
    FILE *file = fopen("FileTest.json", "w");
    if (file == NULL) {
        printf("Error creating the file");
        return;
    }
    fclose(file);
}

void ReadFile() {
    FILE *file = fopen("FileTest.json", "r");
    if (file == NULL) {
        printf("Error reading the file");
        return;
    }
    char FileInput[100];
    char *output;

    output = fgets(FileInput, 100, file);
    printf("%s\n", output);
    fclose(file);
}

void AppendToFile() {
    FILE *file = fopen("FileTest.json", "a");
    if (file == NULL) {
        printf("Error apending to the file");
        return;
    }
    fprintf(file, "Hello EVERYONE\n");
    fclose(file);
}
