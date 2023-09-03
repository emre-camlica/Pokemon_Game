/* @Author
 * Student Name:  Emre Çamlıca
 * Student ID : 150210071
 */
#include "electricPokemon.h"
/*A constructor for electric pokemon, in the member initializer list the corresponding constructor of pokemon
is called. Additionally, it takes the confusion status information as a parameter and initializes it*/
ElectricPokemon::ElectricPokemon(int hp, const int damage, const int recharge, const float powerupchance, std::string name, Confusion c):Pokemon(hp, damage, recharge, powerupchance, name), confusion{c}
{

}
