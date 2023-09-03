/* @Author
 * Student Name:  Emre Çamlıca
 * Student ID : 150210071
 */
#include <iostream>
#include <string>
using std::cout;
using std::endl;
#pragma once

/*These three enumerations represent the state information of the pokemon*/
enum class ownTerrain {yes, no};    // Whether a pokemon is on its own terrain, none as default for normal pokemons
enum class Health {alive, fainted}; // Whether a pokemon is alive or fainted
enum class PowerUp {Powered, notPowered}; // Whether a pokemon is powered up or not

class Pokemon{
    public:
    Pokemon()=default;  // Default constructor for pokemon
    Pokemon(int, const int, const int, const float, std::string); // A constructor for pokemon
    ~Pokemon()=default; // Default destructor for pokemon

    const int get_damage() const {return Damage;} //Getter for damage 
    const float get_PowerUp_Chance() const {return PowerUp_Chance;} //Getter for power up chance
    const int get_Recharge() const {return Recharge;} // Getter for recharge duration
    ownTerrain get_ownTerrain() const {return terrain;} // Whether a pokemon is on its own terrain or not
    Health get_Health() const {return health;}          // Whether a pokemon is alive or fainted
    PowerUp get_powerup() const {return powerup;}       // Whether a pokemon is powered up or not
    const std::string get_name() const {return Name;}   // Getter for name
    int get_HP() const {return HP;}                     // Getter for HP

    void set_ownTerrain(ownTerrain t){terrain = t;}    // Sets the own terrain information
    void set_Health(Health h) {health = h;}            // Sets the pokemon as alive/fainted
    void set_PowerUp(PowerUp p) {powerup = p;}         // Sets the power up state
    void set_HP(int hp) {HP=hp;}                       // Sets the HP

    private:
    ownTerrain terrain;
    Health health;
    PowerUp powerup;
    int HP;
    const int Damage;
    const int Recharge;
    const float PowerUp_Chance;
    const std::string Name;
};