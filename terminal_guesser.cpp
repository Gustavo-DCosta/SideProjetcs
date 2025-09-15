#include <iostream>
#include <ctime>
#include <cstdlib>

int main() {
    const std::string roles[6]= {"witch", "chaser", "welvewolve", "villager", "the bandit", "I can't remeber everything"};
    std::cout << "Welcome to my terminal simulator game\n";
    srand(time(NULL));
    std::string guesser = roles[rand() % 6];
    std::cout << "Guesser: " << guesser << "\n";
return 0;
}
