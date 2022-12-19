#ifndef POKEMON_H_INCLUDED
#define POKEMON_H_INCLUDED
#include <iostream>
#include <string>
#define next(P) (P)->next
#define info(P) (P)->info
#define first(L) ((L).first)

using namespace std;

struct pokemon{
    int idPokemon;
    string namaPokemon, type1, type2;
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
adrPokemon createNodePokemon(string p[3][151], int baris, int kolom);
void insertLastPokemon(ListPokemon &L, adrPokemon newPokemon);
void showPokemon(ListPokemon &L);


#endif // POKEMON_H_INCLUDED
