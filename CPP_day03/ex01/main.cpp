#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(void)
{
    std::cout << "NARRATOR: Let's create a Scav named Dave" << std::endl;
    ScavTrap Dave("Dave");
    std::cout << "NARRATOR: Let's create a Scav named Lola" << std::endl;
    ScavTrap Lola("Lola");
    std::cout << "-----------------------------------" << std::endl <<std::endl;
    std::cout << "NARRATOR: Scav Lola attacks Scav Dave 5 times" << std::endl;
    Lola.attack(Dave.get_name());
    Dave.takeDamage(Lola.get_ad());
    Lola.attack(Dave.get_name());
    Dave.takeDamage(Lola.get_ad());
    Lola.attack(Dave.get_name());
    Dave.takeDamage(Lola.get_ad());
    Lola.attack(Dave.get_name());
    Dave.takeDamage(Lola.get_ad());
    Lola.attack(Dave.get_name());
    Dave.takeDamage(Lola.get_ad());
    std::cout << "-----------------------------------" << std::endl <<std::endl;
    Dave.attack(Lola.get_name());
    std::cout << "-----------------------------------" << std::endl <<std::endl;
    std::cout << "NARRATOR: Dave heals and now can attack Lola" << std::endl;
    Dave.beRepaired(10);
    Dave.attack(Lola.get_name());
    Lola.takeDamage(Dave.get_ad());
    std::cout << "-----------------------------------" << std::endl <<std::endl;
    std::cout << "NARRATOR: Lola guards the gate" << std::endl;
    Lola.guardGate();
    std::cout << "-----------------------------------" << std::endl <<std::endl;

    std::cout << "By using virtual, we can also create assign a ClapTrap * to a ScavTrap" << std::endl;
    ClapTrap *Scavvy = new ScavTrap("Ollie");
    Scavvy->attack("Sonny");
    delete Scavvy;

    std::cout << "------------" << std::endl;
    return 0;
}