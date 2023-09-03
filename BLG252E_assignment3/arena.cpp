/* @Author
 * Student Name:  Emre Çamlıca
 * Student ID : 150210071
 */
#include "arena.h"
#include <time.h> 
Arena::Arena()  // The default constructor for arena, sets the electric and psychic pokemon pointers to null
{
    e=NULL;
    p=NULL;
}

void Arena::addPokemon(char type, std::string name, int hp, int damage) // Adds pokemon to arena
{
    if (type=='e') // If the type is electric
    {   
        const float powerupchance = 0.2; // The power up chance is %20 for electric pokemon
        const int recharge = 3;          // The recharge time is 3 rounds for electric pokemon
        /* Allocates space for and initializes the e object which is a pointer to an electric pokemon
        The confusion information is initially set as clear (not confused)*/
        e=new ElectricPokemon(hp, damage, recharge, powerupchance, name, Confusion::Clear);
        // Prints the necessary information
        cout << "Electric Pokemon " << e->get_name() << " has entered the arena." << endl;
        cout << "Class: Electric" << endl;
        cout << "       Name: " << e->get_name() << endl;
        cout << "       HP: " << e->get_HP() << endl;
        cout << "       Damage: " << e->get_damage() << endl <<endl <<endl;
    }

    else if (type=='p') // If the type is psychic
    {
        const float powerupchance = 0.3; // The power up chance is %30 for psychic pokemon
        const int recharge = 5;          // The recharge time is 3 rounds for psychic pokemon
        //Allocates space for and initializes the e object which is a pointer to an electric pokemon
        p=new PsychicPokemon(hp, damage, recharge, powerupchance, name); 
         // Prints the necessary information
        cout << "Psychic Pokemon " << p->get_name() << " has entered the arena." << endl;
        cout << "Class: Psychic" << endl;
        cout << "       Name: " << p->get_name() << endl;
        cout << "       HP: " << p->get_HP() << endl;
        cout << "       Damage: " << p->get_damage() << endl <<endl <<endl;
    }
}

void Arena::spawnTerrain(){ 
    int i=rand()%5;
    if(i==0){
        set_Terrain("electric");
        e->set_ownTerrain(ownTerrain::yes);
        p->set_ownTerrain(ownTerrain::no);
    }

    else if(i==1){
        set_Terrain("psychic");
        e->set_ownTerrain(ownTerrain::no);
        p->set_ownTerrain(ownTerrain::yes);
    }
    else{
        set_Terrain("none");
        e->set_ownTerrain(ownTerrain::no);
        p->set_ownTerrain(ownTerrain::no);
    }
}

void Arena::restartTerrain(){
        int i=rand()%5;
    if(i==0){
        set_Terrain("electric");
        e->set_ownTerrain(ownTerrain::yes);
        p->set_ownTerrain(ownTerrain::no);
    }

    else if(i==1){
        set_Terrain("psychic");
        e->set_ownTerrain(ownTerrain::no);
        p->set_ownTerrain(ownTerrain::yes);
    }

    else{
        set_Terrain("none");
        e->set_ownTerrain(ownTerrain::no);
        p->set_ownTerrain(ownTerrain::no);
    }
}

void Arena::printRoundStats(int round, int heads){
    cout << "Round: "<< round<< endl;
    cout << "Current Terrain: " << Terrain << endl;
    if(heads==0){ // Heads will either be 0 or 1, 0 meaning electric pokemon starts
    cout << e->get_name() << " goes first." <<endl;
        if(e->get_powerup()==PowerUp::Powered)  // First checks if electric pokemon initiated a power up
        cout << e->get_name() << " has initiated a power up." <<endl;  // and prints if so

        if(p->get_powerup()==PowerUp::Powered)  // Then checks if psychic pokemon initiated a power up
        cout << p->get_name() << " has initiated a power up." <<endl;  // and prints if so
    }

    else{
    cout << p->get_name() << " goes first." <<endl;
        if(p->get_powerup()==PowerUp::Powered)  // First checks if psychic pokemon initiated a power up
        cout << p->get_name() << " has initiated a power up." <<endl;  // and prints if so

        if(e->get_powerup()==PowerUp::Powered)  // Then checks if electric pokemon initiated a power up
        cout << e->get_name() << " has initiated a power up." <<endl;  // and prints if so
    }

    cout << e->get_name() << " HP: " << e->get_HP() <<endl;
    cout << p->get_name() << " HP: " << p->get_HP() <<endl;

    if(e->get_HP()>p->get_HP())
        cout << e->get_name() << " is in the lead!" <<endl;
    
    else if(p->get_HP()>e->get_HP())
        cout << p->get_name() << " is in the lead!" <<endl;

    else
        cout << "No one is in the lead!" <<endl;

    cout << endl << endl;

}
void Arena::printMatchResults(){
    cout << "Match Results:" <<endl;
    if(e->get_Health()==Health::alive)
        cout << e->get_name() << " has won the match!" <<endl;
    else
        cout << p->get_name() << " has won the match!" <<endl;

    cout << endl << endl;
    
}


void Arena::simulateBattle(){
    int random;                 // An integer value used for random value calculations
    int e_counter=0;            // The powerup time counter for the electric pokemon
    int p_counter=0;            // The powerup time counter for the psychic pokemon
    int round_counter=1;        // Round counter
    int terrain_counter=0;      // Used to reset the terrain when it is required
    int confusion_counter=0;    // Counts for how many rounds the electric pokemon was in a confused state
    int heads;         // Used to determine which pokemon to attack first

    while(1){
    if(e_counter==e->get_Recharge()) // When the counter value reaches waiting time for the powerup
        e_counter=0;                 // the counter resets to 0. 
    if(e_counter==1){
        if(e->get_powerup()==PowerUp::Powered)
        e->set_PowerUp(PowerUp::notPowered); // If got the powerup last turn, counter keeps counting.
        else if(e->get_powerup()==PowerUp::notPowered)
        e_counter=0; // If did not get the powerup last turn, counter resets.
    }

    if(p_counter==p->get_Recharge())// When the counter value reaches waiting time for the poweru
        p_counter=0;                // the counter resets to 0. 
    if(p_counter==1){
        if(p->get_powerup()==PowerUp::Powered)
        p->set_PowerUp(PowerUp::notPowered); //If got the powerup last turn, counter keeps counting.
        else if(p->get_powerup()==PowerUp::notPowered)
        p_counter=0; //If did not get the powerup last turn, counter resets.
    }

    if(e_counter==0){ // Randomly determines the powerup state when the counter is zero
        random=rand()%100+1; // Generates a random number between 1 and 100
        if(random<=(e->get_PowerUp_Chance())*100) // There is 20% chance that random<=20,
         e->set_PowerUp(PowerUp::Powered);        // Which is the power up chance
    }

    if(p_counter==0){ // Randomly determines the powerup state when the counter is zero
        random=rand()%100+1; // Generates a random number between 1 and 100
        if(random<=(e->get_PowerUp_Chance())*100) // There is 30% chance that random<=32
         p->set_PowerUp(PowerUp::Powered);        // Which is the power up chance
    }


    if(terrain_counter==5){ // Used to reset the terrain
        terrain_counter=0;
        spawnTerrain();
    }

    if(terrain_counter==0 || (terrain_counter==1 && get_Terrain()=="none")){
        terrain_counter=0;  // Restarts the terrain if there was no active terrain last raund or 
        restartTerrain();   // at the beginning of each battle simulation.
    }
    /* Resets the confusion counter for the electric pokemon when it was not confused the previous round
       or when it was confused for 3 rounds. If counter>1 it must have be in the confused state so that
       the counter did not reset at 1.
    */
    if(confusion_counter==3 || (confusion_counter==1 && e->get_Confusion()==Confusion::Clear)){
        confusion_counter=0;
        e->set_Confusion(Confusion::Clear);
    }

    heads=rand()%2; // Determines who to go first

    if(heads==0){   // The electric pokemon starts
        if(e->get_Confusion()==Confusion::Clear){  // If confused, electric pokemon cannot deal damage
            if(e->get_powerup()==PowerUp::Powered){  // Checks if electric pokemon is powered up
                p->set_HP(p->get_HP()-e->get_damage()*3);// Deals 300% damage if powered up
                if(p->get_HP()<=0)
                p->set_Health(Health::fainted); // Sets psychic pokemon as fainted if its hp<=0
            }

            else{
                p->set_HP(p->get_HP()-e->get_damage()); // Deals normal damage if not powered up
                if(p->get_HP()<=0)
                p->set_Health(Health::fainted); // Sets psychic pokemon as fainted if its hp<=0
            }
        }
        // Else: the electric pokemon is confused, it cannot deal any damage

        if(p->get_Health()==Health::fainted)   // If psychic pokemon is fainted    
        break;                                 // breaks the while loop to end battle
/*-------------------------------------------------------------------------------------------------------------*/
        /*The electric pokemon can get confused only if it is not on its own terrain and the the psychic 
        pokemon is powered up. Checks this condition, if so the electric pokemon gets confused.*/
        if(p->get_powerup()==PowerUp::Powered && e->get_ownTerrain()==ownTerrain::no){
            if(p->get_ownTerrain()==ownTerrain::yes){ // If in its own terrain, attacks twice
                e->set_HP(e->get_HP()-p->get_damage()); // first attack
                e->set_Confusion(Confusion::Confused);  // Confusion attack
                confusion_counter=-1; // Set to -1 so that at the end it will be incremented to 0 to work correctly.
                if(e->get_HP()<=0)
                e->set_Health(Health::fainted); // Sets electric pokemon as fainted if its hp<=0

                if(e->get_Health()==Health::alive){ // Makes the second attack if the electric pokemon
                e->set_HP(e->get_HP()-p->get_damage()); // still alive
                if(e->get_HP()<=0)
                e->set_Health(Health::fainted); // Sets electric pokemon as fainted if its hp<=0
                }
            }

            else{  // If the psychic pokemon is not on its own terrain
                e->set_HP(e->get_HP()-p->get_damage()); // Deals damage only once
                e->set_Confusion(Confusion::Confused);  // Confusion attack
                confusion_counter=-1; // Set to -1 so that at the end it will be incremented to 0 to work correctly.
                if(e->get_HP()<=0)
                e->set_Health(Health::fainted); // Sets electric pokemon as fainted if its hp<=0
            }
        }

        else{  // If the psychic pokemon cannot induce confusion attack on the electric pokemon
            if(p->get_ownTerrain()==ownTerrain::yes){ // If in its own terrain, attacks twice
                e->set_HP(e->get_HP()-p->get_damage()); // first attack
                if(e->get_HP()<=0)
                e->set_Health(Health::fainted); // Sets electric pokemon as fainted if its hp<=0

                if(e->get_Health()==Health::alive){ // Makes the second attack if the electric pokemon
                e->set_HP(e->get_HP()-p->get_damage()); // still alive
                if(e->get_HP()<=0)
                e->set_Health(Health::fainted); // Sets electric pokemon as fainted if its hp<=0
                }
            }

            else{  // If the psychic pokemon is not on its own terrain
                e->set_HP(e->get_HP()-p->get_damage()); // Deals damage only once
                if(e->get_HP()<=0)
                e->set_Health(Health::fainted); // Sets electric pokemon as fainted if its hp<=0
            }

        }


        if(e->get_Health()==Health::fainted)   // If electric pokemon is fainted 
        break;                                 // breaks the while loop to end battle
    }
/*-------------------------------------------------------------------------------------------------------------*/
    else{
        /*The electric pokemon can get confused only if it is not on its own terrain and the the psychic 
        pokemon is powered up. Checks this condition, if so the electric pokemon gets confused.*/
        if(p->get_powerup()==PowerUp::Powered && e->get_ownTerrain()==ownTerrain::no){
            if(p->get_ownTerrain()==ownTerrain::yes){ // If in its own terrain, attacks twice
                e->set_HP(e->get_HP()-p->get_damage()); // first attack
                e->set_Confusion(Confusion::Confused);  // Confusion attack
                confusion_counter=0; // Resets the confusion counter.
                if(e->get_HP()<=0)
                e->set_Health(Health::fainted); // Sets electric pokemon as fainted if its hp<=0

                if(e->get_Health()==Health::alive){ // Makes the second attack if the electric pokemon
                e->set_HP(e->get_HP()-p->get_damage()); // still alive
                if(e->get_HP()<=0)
                e->set_Health(Health::fainted); // Sets electric pokemon as fainted if its hp<=0
                }
            }

            else{  // If the psychic pokemon is not on its own terrain
                e->set_HP(e->get_HP()-p->get_damage()); // Deals damage only once
                e->set_Confusion(Confusion::Confused);  // Confusion attack
                confusion_counter=0; // Resets the confusion counter.
                if(e->get_HP()<=0)
                e->set_Health(Health::fainted); // Sets electric pokemon as fainted if its hp<=0
            }
        }

        else{  // If the psychic pokemon cannot induce confusion attack on the electric pokemon
            if(p->get_ownTerrain()==ownTerrain::yes){ // If in its own terrain, attacks twice
                e->set_HP(e->get_HP()-p->get_damage()); // first attack
                if(e->get_HP()<=0)
                e->set_Health(Health::fainted); // Sets electric pokemon as fainted if its hp<=0

                if(e->get_Health()==Health::alive){ // Makes the second attack if the electric pokemon
                e->set_HP(e->get_HP()-p->get_damage()); // still alive
                if(e->get_HP()<=0)
                e->set_Health(Health::fainted); // Sets electric pokemon as fainted if its hp<=0
                }
            }

            else{  // If the psychic pokemon is not on its own terrain
                e->set_HP(e->get_HP()-p->get_damage()); // Deals damage only once
                if(e->get_HP()<=0)
                e->set_Health(Health::fainted); // Sets electric pokemon as fainted if its hp<=0
            }

        }


        if(e->get_Health()==Health::fainted)   // If electric pokemon is fainted 
        break;                                 // breaks the while loop to end battle
/*-------------------------------------------------------------------------------------------------------------*/
        if(e->get_Confusion()==Confusion::Clear){  // If confused, electric pokemon cannot deal damage
            if(e->get_powerup()==PowerUp::Powered){  // Checks if electric pokemon is powered up
                p->set_HP(p->get_HP()-e->get_damage()*3);// Deals 300% damage if powered up
                if(p->get_HP()<=0)
                p->set_Health(Health::fainted); // Sets psychic pokemon as fainted if its hp<=0
            }

            else{
                p->set_HP(p->get_HP()-e->get_damage()); // Deals normal damage if not powered up
                if(p->get_HP()<=0)
                p->set_Health(Health::fainted); // Sets psychic pokemon as fainted if its hp<=0
            }
        }
        // Else: the electric pokemon is confused, it cannot deal any damage
        if(p->get_Health()==Health::fainted) // If psychic pokemon is fainted 
        break;                               // breaks the while loop to end battle
    }       

    printRoundStats(round_counter, heads); // Prints the round stats
    // All counters are incremented
    round_counter++;
    e_counter++;
    p_counter++;
    terrain_counter++;
    confusion_counter++;
    }

    printRoundStats(round_counter, heads); // Since I used break statements in the while loop, prints the last round stats
    printMatchResults(); // Prints the match results
}