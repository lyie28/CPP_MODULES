#include "ClapTrap.hpp"

int main(void)
{
    ClapTrap Maverick("Maverick");
    ClapTrap Bob("Bob");

    Maverick.attack(Bob.get_name());
    std::cout << "NAME: " << Bob.get_name() << " ENERGY: " << Bob.get_ep() << " ATTACK_DAM: " << Bob.get_ad() << " HITPOINTS: " << Bob.get_hp() << std::endl;
    std::cout << "NARRATOR: attack not every effective..." << std::endl;
    Bob.takeDamage(0);
    std::cout << "NARRATOR: Bob will heal himself anyway..." << std::endl;
    Bob.beRepaired(5);
    std::cout << "INCREASED HP: " << Bob.get_hp() << std::endl;
    Maverick = Bob;
    std::cout << "NARRATOR: In a strange turn of events, Bob (formerly Maverick) attacks the original Bob..." << std::endl;
    Maverick.attack(Bob.get_name());
    return 0;
}