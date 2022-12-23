#ifndef TRAINER_H_INCLUDED
#define TRAINER_H_INCLUDED
#include "pokemon.h"
#define pocket(p) (p)->pocket
struct trainer{
<<<<<<< Updated upstream
    string idTrainer, namaTrainer;
    bool pokedex[150];
=======
    string idTrainer;
    string namaTrainer;
    bool pokedex[152];
>>>>>>> Stashed changes
};

typedef trainer infoTrainer;
typedef struct nodeTrainer *adrTrainer;
typedef struct nodePocket *adrPocket;

struct nodeTrainer{
    infoTrainer info;
    adrTrainer next;
    adrPocket pocket;
};

struct nodePocket{
    adrPocket next;
    adrPokemon pocketPokemon;
};

struct ListTrainer{
    adrTrainer first;
};

void createListTrainer(ListTrainer &L);
adrTrainer createNodeTrainer(string idTrainer, string namaTrainer);
void insertLastTrainer(ListTrainer &L, adrTrainer newTrainer);
adrTrainer selectTrainer(ListTrainer L, string idTrainer);
bool checkPointTrainer(adrTrainer pointTrainer);
bool checkPocket(adrTrainer pointTrainer);
void deleteFirstPocket(ListTrainer &L, adrTrainer pointTrainer);
bool checkDupe(adrTrainer pointTrainer, string idPokemon);
void insertLastPocket(ListTrainer L, adrTrainer pointTrainer);
bool checkPokemonInTrainer(adrTrainer pointTrainer, string idPokemon);
void tradePokemonInPocket(ListTrainer &L, ListPokemon M, string idTrainer, string idPokemon);
void showAllTrainer(ListTrainer L, ListPokemon M);
void showTrainerDetail(ListTrainer L, ListPokemon M, string idTrainer);
<<<<<<< Updated upstream
void showTrainerPokedex(ListTrainer L, string idTrainer, string p[3][150])
=======
void showTrainerPokedex(ListTrainer L, string idTrainer, string p[3][151], int baris, int kolom);
>>>>>>> Stashed changes

#endif // TRAINER_H_INCLUDED
