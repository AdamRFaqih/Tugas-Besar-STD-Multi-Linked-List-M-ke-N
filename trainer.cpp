#include "trainer.h"

void createListTrainer(ListTrainer &L){
    first(L) = NULL;
}

adrTrainer createNodeTrainer(string idTrainer, string namaTrainer){
    adrTrainer newTrainer = new nodeTrainer;
    bool pokedex[151] = {[1 ... 151]} = false};
    info(newTrainer).idTrainer = idTrainer;
    info(newTrainer).namaTrainer = namaTrainer;
    info(newTrainer).pokedex[151] = pokedex;
    next(newTrainer) = NULL;
    return newTrainer;
}
