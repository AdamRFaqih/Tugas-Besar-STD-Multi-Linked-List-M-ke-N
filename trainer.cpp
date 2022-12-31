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
    int s = 1;
    adrPocket p = pocket(pointTrainer);
    while(p != NULL){
        s++;
        p = next(p);
    }
    if(s == 6){
        return true;
    }else{
        return false;
    }
}
void deleteFirstPocket(ListTrainer &L, adrTrainer pointTrainer){
    if(checkPointTrainer(pointTrainer) == false && checkPocket(pointTrainer) == true){
        if(next(pocket(pointTrainer)) == NULL){
            pocket(pointTrainer) = NULL;
        }else{
            adrPocket p;
            p = pocket(pointTrainer);
            pocket(pointTrainer) = next(p);
            next(p) = NULL;
        }
    }
}
//Mencari input idpokemon yang sama di idpokemon yang di trainer
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
    int r = 0;
    if(checkDupe(pointTrainer, idPokemon) == false){
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
        stringstream chng(idPokemon);
        chng >> r;
        info(pointTrainer).pokedex[r] = true;
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
                    cout << " {" << info(s).namaPokemon << "} ";
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
            cout << " {" << info(s).namaPokemon << "} ";
            q = next(q);
        }
        //print pokedex punya trainer
        cout << endl;
        showTrainerPokedex(p);
    }
}
// show trainer pokedex masih bingung
void showTrainerPokedex(adrTrainer pilihanTrainer){
    int i,r;
    i = 1;
    r = 0;
    while(i <= 151){
        if(info(pilihanTrainer).pokedex[i] == true){
            r++;
        }
        i++;
    }
    cout <<"Pokemon Completion: " << r << endl;
}

//Pengecekan idpokemon di pocket milik trainer
bool checkPokemonInTrainer(adrTrainer pointTrainer, string idPokemon){
    return checkDupe(pointTrainer, idPokemon);
}
//trade pokemon butuh penjelasan
void tradePokemonInPocket(ListTrainer &L, ListPokemon &M, string idTrainer, string idPokemon){
    adrTrainer p,q;
    adrPokemon s,a;
    bool z,x;
    string r,rr;
    //adrTrainer 1
    p = selectTrainer(L, idTrainer);
    cout <<"Masukan id Trainer yang akan menjadi target trade: ";
    cin >> r;
    //adrTrainer 2
    q = selectTrainer(L, r);
    if(p != NULL && q != NULL){
        cout <<"Masukan id pokemon yang akan menjadi target trade: ";
        cin >> rr;
        //Pengecekan pokemon trainer 1 ada di pocket
        z = checkDupe(p,idPokemon);
        //Pengecekan pokemon trainer 2 ada di pocket
        x = checkDupe(q, rr);
        if(z == true && x == true){
        //Pengecekan duplikasi pokemon trainer 1 di trainer 2
            z = checkPokemonInTrainer(p, rr);
        //Pengecekan duplikasi pokemon trainer 2 di trainer 1
            x = checkPokemonInTrainer(q, idPokemon);
            if(z == false && x == false){
                s = cariPokemon(M, idPokemon);
                a = cariPokemon(M, rr);
                adrPocket g,h;
                g = pocket(p);
                h = pocket(q);
                //trainer 1
                while(g != NULL){
                    if(pocketPokemon(g) == s){
                        pocketPokemon(g) = a;
                        break;
                    }
                    g = next(g);
                }
                while(h != NULL){
                    if(pocketPokemon(h) == a){
                        pocketPokemon(h) = s;
                        break;
                    }
                    h = next(h);
                }
                cout <<"Trade Berhasil\n";
            }else{
                cout <<"Salah satu Pokemon duplikat!\n";
            }
        }else{
            cout <<"Salah satu Pokemon Tidak ada di pocket!\n";
        }
    }else{
        cout <<"Salah satu trainer tidak ditemukan!\n";
    }
}

string RNGpokemon(ListPokemon M){
    int i,randomNum;
    srand (time(NULL));
    randomNum = rand() % 151;
    adrPokemon p = first(M);
    i = 1;
    while(i <= randomNum){
        p = next(p);
        i++;
    }
    return info(p).idPokemon;
}

string selectedTrainer(adrTrainer selectedS){
    if(selectedS == NULL){
        return "";
    }else{
        return info(selectedS).namaTrainer;
    }
}

void deleteFirstTrainer(ListTrainer &L){
    adrTrainer P = first(L);
    first(L) = next(first(L));
    next(P) = NULL;
}

void deleteLastTrainer(ListTrainer &L){
    adrTrainer P = first(L), Q = first(L);
    while (next(P) != NULL){
        Q = P;
        P = next(P);
    }
    next(Q) = NULL;
}

void deleteAfterTrainer(ListTrainer &L, string idTrainer){
    adrTrainer P = first(L), Q = first(L);
    while (info(P).idTrainer != idTrainer){
        Q = P;
        P = next(P);
    }
    next(Q) = next(next(P));
    next(P) = NULL;
}

void deleteTrainer(ListTrainer &L, string idTrainer){
    adrTrainer P = first(L);
    while (next(P) != NULL){
        P = next(P);
    }
    if (info(first(L)).idTrainer == idTrainer){
        deleteFirstTrainer(L);
    }else if (info(P).idTrainer == idTrainer){
        deleteLastTrainer(L);
    }else{
        deleteAfterTrainer(L, idTrainer);
    }
}
