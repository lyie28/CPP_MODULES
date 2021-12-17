#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"


int main(void)
{
    DiamondTrap Danny("Danny");
    std::cout << "-----------------------------------" << std::endl <<std::endl;
    Danny.whoAmI();
    std::cout << "-----------------------------------" << std::endl <<std::endl;
    std::cout << "Attack damage and hitpoints should inherit from FragTrap (30) & (100)" << std::endl;
    std::cout << Danny.get_ad() << " AD" << std::endl;
    std::cout << Danny.get_hp() << " HP" << std::endl;
    std::cout << "-----------------------------------" << std::endl <<std::endl;
    std::cout << "Energy should inherit from ScavTrap (50))" << std::endl;
    std::cout << Danny.get_ep() << " EP" << std::endl;
    std::cout << "-----------------------------------" << std::endl <<std::endl;
    std::cout << "Danny attacks with SCAVTRAP attack" << std::endl;
    Danny.attack("Lucas");
    std::cout << "-----------------------------------" << std::endl <<std::endl;
    std::cout << "Danny inhertis FRAGTRAP and SCAVTRAP powers" <<std::endl;
    Danny.guardGate();
    Danny.highFivesGuys();
    std::cout << "-----------------------------------" << std::endl <<std::endl;


    std::cout << "Now, let's try with a DiamondTrap of type ClapTrap *" << std::endl;
    ClapTrap *lol = new DiamondTrap("Lol");
    delete lol;
    std::cout << "-----------------------------------" << std::endl <<std::endl;

    return 0;
}