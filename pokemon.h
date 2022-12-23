#ifndef POKEMON_H_INCLUDED
#define POKEMON_H_INCLUDED
#include <iostream>

using namespace std;
#define info(p) (p)->info
#define next(p) (p)->next
#define first(L) ((L).first)

struct pokemon{
    string idPokemon;
    string namaPokemon;
    string type1;
    string type2;
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
