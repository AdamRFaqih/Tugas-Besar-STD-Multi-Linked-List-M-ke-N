#include "pokemon.h"

void createListPokemon(ListPokemon &L){
    first(L) = NULL;
}

adrPokemon createNodePokemon(string p[3][151], int baris, int kolom){
    adrPokemon newPokemon = new nodePokemon;
    info(newPokemon).idPokemon = stoi(p[baris][kolom]);
    info(newPokemon).namaPokemon = p[baris][kolom+1];
    info(newPokemon).type1 = p[baris][kolom+2];
    info(newPokemon).type2 = p[baris][kolom+3];
    next(newPokemon) = NULL;
    return newPokemon;
}

void insertLastPokemon(ListPokemon &L, adrPokemon newPokemon){
    if (first(L) == NULL){
        first(L) = newPokemon;
    }else{
        adrPokemon P = first(L);
        while(next(P) != NULL){
            P = next(P);
        }
        next(P) = newPokemon;
    }
}

void showPokemon(ListPokemon &L){
    adrPokemon P = first(L);
    while(P != NULL){
        cout << "ID Pokemon: " << info(P).idPokemon << "; " ;
        cout << "Nama Pokemon: " << info(P).namaPokemon << "; " ;
        cout << "Type 1: " << info(P).type1 << "; " ;
        cout << "Type 2: " << info(P).type2 << endl;
    }
}
