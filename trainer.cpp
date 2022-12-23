#include "trainer.h"

void createListTrainer(ListTrainer &L){
    first(L) = NULL;
}
adrTrainer createNodeTrainer(string idTrainer, string namaTrainer){
    adrTrainer p;
    infoTrainer q;
    q.idTrainer = idTrainer;
    q.namaTrainer = namaTrainer;
    q.pokedex[152] = {false};

    p = new nodeTrainer;
    info(p) = q;
    next(p) = NULL;
    pocket(p) = NULL;

    return p;
}
void insertLastTrainer(ListTrainer &L, adrTrainer newTrainer){
    if(first(L) == NULL){
        first(L) = newTrainer;
    }else{
        adrTrainer p = first(L);
        while(next(p) != NULL){
            p = next(p);
        }
        next(p) = newTrainer;
    }
}
adrTrainer selectTrainer(ListTrainer L, string idTrainer){
    adrTrainer p = first(L);
    while(p != NULL){
        if(info(p).idTrainer == idTrainer){
            return p;
            break;
        }
        p = next(p);
    }
    return NULL;
}
bool checkPointTrainer(adrTrainer pointTrainer){
    return pointTrainer != NULL;
}
bool checkPocket(adrTrainer pointTrainer){
    return pointTrainer != NULL;
}
