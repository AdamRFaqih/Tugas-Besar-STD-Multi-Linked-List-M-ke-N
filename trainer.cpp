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
// Memilih trainer
adrTrainer selectTrainer(ListTrainer L, string idTrainer){
    adrTrainer p = first(L);
    adrTrainer q = NULL;
    while(p != NULL){
        if(info(p).idTrainer == idTrainer){
            q = p;
            break;
        }
        p = next(p);
    }
    return q;
}
bool checkPointTrainer(adrTrainer pointTrainer){
    return pointTrainer != NULL;
}
bool checkPocket(adrTrainer pointTrainer){
    int s = 0;
    adrPocket p = pocket(pointTrainer);
    while(p != NULL){
        s++;
        next(p);
    }
    if(s < 6){
        return true;
    }
    return false;
}
void deleteFirstPocket(ListTrainer &L, adrTrainer pointTrainer){
    if(checkPointTrainer(pointTrainer) != false && checkPocket(pointTrainer) != false){
        if(next(pocket(pointTrainer)) == NULL){
            pocket(pointTrainer) = NULL;
        }else{
            adrPocket p;
            p = pocket(pointTrainer);
            pocket(pointTrainer) = next(p);
            next(p) = NULL;
        }
    }else{
        cout <<"Pointer atau pocket false\n";
    }
}
bool checkDupe(adrTrainer pointTrainer, string idPokemon){
    adrPocket q = pocket(pointTrainer);
    adrPokemon s;
    bool r = false;
    while(q != NULL){
        s = pocketPokemon(q);
        if(info(s).idPokemon == idPokemon){
            r = true;
            break;
        }
        q = next(q);
    }
    return r;
}
adrPocket createNodePocket(ListPokemon L, string idPokemon){
    adrPokemon p = cariPokemon(L, idPokemon);
    adrPocket q = new nodePocket;
    pocketPokemon(q) = p;
    next(q) = NULL;

    return q;

}
// untuk cari pokemon di list pokemon berdasarkan id
adrPokemon cariPokemon(ListPokemon L, string idPokemon){
    adrPokemon p = first(L);
    adrPokemon q = NULL;
    while(p != NULL){
        if(info(p).idPokemon == idPokemon){
            q = p;
            break;
        }
        p = next(p);
    //butuh return yang jelas
    }
    return q;
}
void insertLastPocket(ListTrainer &L, ListPokemon S,adrTrainer pointTrainer,string idPokemon){
    if(!checkDupe(pointTrainer, idPokemon)){
        adrPocket q = createNodePocket(S, idPokemon);
        if(pocket(pointTrainer) == NULL){
            pocket(pointTrainer) = q;
        }else{
            adrPocket p = pocket(pointTrainer);
            while(next(p) != NULL){
                p = next(p);
            }
            next(p) = q;
        }
    }else{
        cout <<"Pokemon Duplikat\n";
    }
}
void showAllTrainer(ListTrainer L, ListPokemon M){
    if(first(L) == NULL){
        cout <<"List Trainer Kosong!\n";
    }else{
        adrTrainer p = first(L);
        adrPocket q;
        adrPokemon s;
        while(p != NULL){
            cout << info(p).idTrainer << " " << info(p).namaTrainer<<"\nPokemon: ";
                q = pocket(p);
                while(q != NULL){
                    s = pocketPokemon(q);
                    cout << info(s).namaPokemon << " / ";
                    q = next(q);
                }
            cout << endl;
            p = next(p);
        }
    }
}
void showTrainerDetail(ListTrainer L, ListPokemon M, string idTrainer){
    adrTrainer p = selectTrainer(L, idTrainer);
    if(p == NULL){
        cout << "Trainer Tak ada!\n";
    }else{
        adrPocket q;
        adrPokemon s;
        cout << info(p).idTrainer << " " << info(p).namaTrainer<<"\nPokemon: ";
        q = pocket(p);
        while(q != NULL){
            s = pocketPokemon(q);
            cout << info(s).namaPokemon << " / ";
            q = next(q);
        }
        //print pokedex punya trainer
        int i,n;
        i = 1;
        while(i <= 152){
            cout << info(p).pokedex[i] << " ";
            n = i;
            if(n % 30 == 0){
                cout << endl;
            }
            i++;
        }
    }
}
// show trainer pokedex masih bingung
void showTrainerPokedex(ListTrainer L, string idTrainer, string p[4][152]);


bool checkPokemonInTrainer(adrTrainer pointTrainer, string idPokemon){
    return checkDupe(pointTrainer, idPokemon);
}
//trade pokemon butuh penjelasan
void tradePokemonInPocket(ListTrainer &L, ListPokemon &M, string idTrainer, string idPokemon);


