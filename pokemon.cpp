#include "pokemon.h"

void createListPokemon(ListPokemon &L){
    L.first = NULL;
}

adrPokemon createNodePokemon(string p[4][152], int kolom, int baris){
    adrPokemon newPokemon = new nodePokemon;
    info(newPokemon).idPokemon = p[kolom][baris];
    info(newPokemon).namaPokemon = p[kolom + 1][baris];
    info(newPokemon).type1 = p[kolom + 2][baris];
    info(newPokemon).type2 = p[kolom + 3][baris];
    next(newPokemon) = NULL;
    return newPokemon;

}

void insertLastPokemon(ListPokemon &L, adrPokemon newPokemon){
    if(first(L) == NULL){
        first(L) = newPokemon;
    }else{
        adrPokemon P = first(L);
        while(next(P) != NULL){
            P = next(P);
        }
        next(P) = newPokemon;
    }
}
void showPokemon(ListPokemon L){
    adrPokemon P = first(L);
    while(P != NULL){
        cout << "ID Pokemon: " << info(P).idPokemon << "; ";
        cout << "Nama Pokemon: " << info(P).namaPokemon << "; ";
        cout << "Type1: " << info(P).type1 << "; ";
        cout << "Type2: " << info(P).type2 << endl;
        P = next(P);
    }
}

void addPokemon(ListPokemon &L, string p[4][152]){
    createListPokemon(L);
    adrPokemon P;
    int kolom = 0, baris = 1;
    while(baris <= 151){
        P = createNodePokemon(p, kolom, baris);
        insertLastPokemon(L,P);
        baris++;
    }
}
