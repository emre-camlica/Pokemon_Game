/* @Author
 * Student Name:  Emre Çamlıca
 * Student ID : 150210071
 */
#include "psychicPokemon.h"
/*A constructor for psychic pokemon, in the member initializer list the corresponding constructor of pokemon
is called*/
PsychicPokemon::PsychicPokemon(int hp, const int damage, const int recharge, const float powerupchance, std::string name):Pokemon(hp, damage, recharge, powerupchance, name)
{

}