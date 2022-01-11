#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"


int main(void)
{
    std::cout << "NARRATOR: Let's create a Frag named Dave" << std::endl;
    FragTrap Dave("Dave");
    std::cout << "-----------------------------------" << std::endl <<std::endl;
    std::cout << "NARRATOR: Frag Dave attacks mystery person" << std::endl;
    Dave.attack("mystery person");
    std::cout << "NARRATOR: Frag Dave asks for high five" << std::endl;
    Dave.highFivesGuys();
    std::cout << "-----------------------------------" << std::endl <<std::endl;

    std::cout << "NARRATOR: Let's create a Frag of type Clap named Bob" << std::endl;
    ClapTrap *Bob = new FragTrap("Bob");
    delete Bob;
    std::cout << "-----------------------------------" << std::endl <<std::endl;
    return 0;
}
