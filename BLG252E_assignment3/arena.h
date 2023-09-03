/* @Author
 * Student Name:  Emre Çamlıca
 * Student ID : 150210071
 */
#include "electricPokemon.h"
#include "psychicPokemon.h"

class Arena
{
    public:
    Arena();          // Default constructor
    ~Arena()=default; // Default destructor

    void addPokemon(char type, std::string name, int hp, int damage);
    void simulateBattle();
    void spawnTerrain();
    void restartTerrain();
    void printRoundStats(int round, int heads);
    void printMatchResults();

    std::string get_Terrain() const {return Terrain;} // Getter for arena terrain
    void set_Terrain(std::string t) {Terrain = t;}    // Sets the arena terrain

    private:
    ElectricPokemon *e; // A pointer to an electric pokemon
    PsychicPokemon *p;  // A pointer to an electric pokemon
    std::string Terrain;

};