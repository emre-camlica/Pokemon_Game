/* @Author
 * Student Name:  Emre Çamlıca
 * Student ID : 150210071
 */
#include "pokemon.h"

/*A constructor for pokemon. In a member initializer list, all members are initialized. The members that
give status information are initialized to default values so that a pokemon is alive, not powered up and
is not on its own terrain initially*/
Pokemon :: Pokemon(int hp, const int damage, const int recharge, const float powerupchance, std::string name) :
terrain{ownTerrain::no}, health{Health::alive}, powerup{PowerUp::notPowered}, HP{hp}, Damage{damage}, 
 Recharge{recharge}, PowerUp_Chance{powerupchance}, Name{name}
{
}
