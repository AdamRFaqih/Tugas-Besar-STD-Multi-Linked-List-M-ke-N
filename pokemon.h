#ifndef POKEMON_H_INCLUDED
#define POKEMON_H_INCLUDED
#include <iostream>

using namespace std;

struct pokemon{
    string idPokemon, namaPokemon, type1, type2;
};

typedef pokemon infoPokemon;
typedef struct nodePokemon *adrPokemon;

struct nodePokemon{
    infoPokemon info;
    adrPokemon next;
};

struct ListPokemon{
    adrPokemon first;
};

void createListPokemon(ListPokemon &L);
adrPokemon createNodePokemon(string p[3][151]);
void insertFirstPokemon(ListPokemon &L, adrPokemon newPokemon);
void showPokemon(ListPokemon &L);


#endif // POKEMON_H_INCLUDED
