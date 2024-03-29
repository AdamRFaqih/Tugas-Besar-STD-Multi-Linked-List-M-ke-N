#ifndef TRAINER_H_INCLUDED
#define TRAINER_H_INCLUDED
#include <sstream>
#include <time.h>
#include <stdbool.h>
#include "pokemon.h"
#define info(p) (p)->info
#define next(p) (p)->next
#define pocket(p) (p)->pocket
#define pocketPokemon(p) (p)->pocketPokemon
#define first(L) ((L).first)

struct trainer{
    string idTrainer;
    string namaTrainer;
    bool pokedex[152];
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

bool checkTrainerID(ListTrainer L, string idTrainer);
void createListTrainer(ListTrainer &L);
adrTrainer createNodeTrainer(string idTrainer, string namaTrainer);
void insertLastTrainer(ListTrainer &L, adrTrainer newTrainer);
adrTrainer selectTrainer(ListTrainer L, string idTrainer);
bool checkPointTrainer(adrTrainer pointTrainer);
bool checkPocket(adrTrainer pointTrainer);
void deleteFirstPocket(ListTrainer &L, adrTrainer pointTrainer);
bool checkDupe(adrTrainer pointTrainer, string idPokemon);
void insertLastPocket(ListTrainer &L, ListPokemon S,adrTrainer pointTrainer,string idPokemon);
adrPokemon cariPokemon(ListPokemon L, string idPokemon);
adrPocket createNodePocket(ListPokemon L, string idPokemon);
bool checkPokemonInTrainer(adrTrainer pointTrainer, string idPokemon);
void tradePokemonInPocket(ListTrainer &L, ListPokemon &M, string idTrainer, string idPokemon);
void showAllTrainer(ListTrainer L, ListPokemon M);
void showTrainerDetail(ListTrainer L, ListPokemon M, string idTrainer);
void showTrainerPokedex(adrTrainer pilihanTrainer);
string RNGpokemon(ListPokemon M);
string selectedTrainer(adrTrainer selectedS);
void deleteFirstTrainer(ListTrainer &L);
void deleteLastTrainer(ListTrainer &L);
void deleteTrainer(ListTrainer &L, string idTrainer);
int stringToInt(string x);

#endif // TRAINER_H_INCLUDED
