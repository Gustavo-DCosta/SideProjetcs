#include <iostream>
#include <ctime>
#include <cstdlib>
#include <map>

#define MAX_PLAYERS 9
#define MAX_ROLES 6

int main() {
    std::map<int, std::string> players;
    const std::string roles[MAX_ROLES] = {"witch", "chaser", "werewolf", "villager", "the bandit", "seer"};

    std::cout << "Welcome to my terminal simulator game\n";
    std::srand(time(NULL));

    for (int i = 1; i <= MAX_PLAYERS; i++) {
        std::string random_role = roles[rand() % MAX_ROLES];
        players[i] = random_role;
        std::cout << "Player n° " << i << " got the role: " << players[i] << "\n";
    }

    return 0;
}
