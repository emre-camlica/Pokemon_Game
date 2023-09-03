/* @Author
 * Student Name:  Emre Çamlıca
 * Student ID : 150210071
 */
#include "pokemon.h"

class PsychicPokemon : public Pokemon
{
    public:
    PsychicPokemon()=default; // Default constructor
    PsychicPokemon(int, const int, const int, const float, std::string); // A constructor
    ~PsychicPokemon()=default;  // Default destructor
    private:
};