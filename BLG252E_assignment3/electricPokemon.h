/* @Author
 * Student Name:  Emre Çamlıca
 * Student ID : 150210071
 */
#include "pokemon.h"

enum class Confusion {Confused, Clear}; // An enumeration to determine the confusion state of the electric pokemon
class ElectricPokemon : public Pokemon
{
    public:
    ElectricPokemon()=default;
    ElectricPokemon(int, const int, const int, float, std::string, Confusion); //A constructor, sets the confusion information for electric pokemon
    ~ElectricPokemon()=default;
    Confusion get_Confusion() const {return confusion;}
    void set_Confusion(Confusion c) {confusion = c;} 
    private:
    Confusion confusion;
};