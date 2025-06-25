#include <stdio.h>
#include <stdbool.h>

int main() {
  char *message = "hangman"; // 8 bytes
  char input;
  int startgame;
  
  printf("Please start the game by tipping 1: \n");
  scanf("%d", &startgame);

  if (startgame == 1) {
    for (int i = 0; i < sizeof(message); i++) {
      scanf("%c", &input);
      if (input = message[i]); {
        printf("Letter found: ");
        printf("%c", message[i]);
      }
    }
  } else {
    printf("Sorry keybind not recognized");
    return -1;
  }

  return 0;
}

