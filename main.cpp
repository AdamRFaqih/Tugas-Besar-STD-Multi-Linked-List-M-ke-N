#include "trainer.h"

int main()
{
    //DataPokemon
    string p[4][152] = {
    /*ID POKEMON */     {"", "1","2","3","4","5","6","7","8","9","10","11","12","13","14","15","16","17","18","19","20","21","22","23","24","25","26","27","28","29","30","31","32","33","34","35","36","37","38","39","40","41","42","43","44","45","46","47","48","49","50","51","52","53","54","55","56","57","58","59","60","61","62","63","64","65","66","67","68","69","70","71","72","73","74","75","76","77","78","79","80","81","82","83","84","85","86","87","88","89","90","91","92","93","94","95","96","97","98","99","100","101","102","103","104","105","106","107","108","109","110","111","112","113","114","115","116","117","118","119","120","121","122","123","124","125","126","127","128","129","130","131","132","133","134","135","136","137","138","139","140","141","142","143","144","145","146","147","148","149","150","151"},
    /*NAMA POKEMON */   {"", "Bulbasaur","Ivysaur","Venusaur","Charmander","Charmeleon","Charizard","Squirtle","Wartortle","Blastoise","Caterpie","Metapod","Butterfree","Weedle","Kakuna","Beedrill","Pidgey","Pidgeotto","Pidgeot","Rattata","Raticate","Spearow","Fearow","Ekans","Arbok","Pikachu","Raichu","Sandshrew","Sandslash","Nidoran(F)","Nidorina","Nidoqueen","Nidoran(M)","Nidorino","Nidoking","Clefairy","Clefable","Vulpix","Ninetales","Jigglypuff","Wigglytuff","Zubat","Golbat","Oddish","Gloom","Vileplume","Paras","Parasect","Venonat","Venomoth","Diglett","Dugtrio","Meowth","Persian","Psyduck","Golduck","Mankey","Primeape","Growlithe","Arcanine","Poliwag","Poliwhirl","Poliwrath","Abra","Kadabra","Alakazam","Machop","Machoke","Machamp","Bellsprout","Weepinbell","Victreebel","Tentacool","Tentacruel","Geodude","Graveler","Golem","Ponyta","Rapidash","Slowpoke","Slowbro","Magnemite","Magneton","Farfetch'd","Doduo","Dodrio","Seel","Dewgong","Grimer","Muk","Shellder","Cloyster","Gastly","Haunter","Gengar","Onix","Drowzee","Hypno","Krabby","Kingler","Voltorb","Electrode","Exeggcute","Exeggutor","Cubone","Marowak","Hitmonlee","Hitmonchan","Lickitung","Koffing","Weezing","Rhyhorn","Rhydon","Chansey","Tangela","Kangaskhan","Horsea","Seadra","Goldeen","Seaking","Staryu","Starmie","Mr. Mime","Scyther","Jynx","Electabuzz","Magmar","Pinsir","Tauros","Magikarp","Magikarp","Lapras","Ditto","Eevee","Vaporeon","Jolteon","Flareon","Porygon","Omanyte","Omastar","Kabuto","Kabutops","Aerodactyl","Snorlax","Articuno","Zapdos","Moltres","Dratini","Dragonair","Dragonite","Mewtwo","Mew"},
    /*TIPE 1 */         {"", "GRASS","GRASS","GRASS","FIRE","FIRE","FIRE","WATER","WATER","WATER","BUG","BUG","BUG","BUG","BUG","BUG","NORMAL","NORMAL","NORMAL","NORMAL","NORMAL","NORMAL","NORMAL","POISON","POISON","ELECTRIC","ELECTRIC","GROUND","GROUND","POISON","POISON","POISON","POISON","POISON","POISON","FAIRY","FAIRY","FIRE","FIRE","NORMAL","NORMAL","POISON","POISON","GRASS","GRASS","GRASS","BUG","BUG","BUG","BUG","GROUND","GROUND","NORMAL","NORMAL","WATER","WATER","FIGHT","FIGHT","FIRE","FIRE","WATER","WATER","WATER","PSYCHO","PSYCHO","PSYCHO","FIGHT","FIGHT","FIGHT","GRASS","GRASS","GRASS","WATER","WATER","ROCK","ROCK","ROCK","FIRE","FIRE","WATER","WATER","ELECTRIC","ELECTRIC","NORMAL","NORMAL","NORMAL","WATER","WATER","POISON","POISON","WATER","WATER","GHOST","GHOST","GHOST","ROCK","PSYCHO","PSYCHO","WATER","WATER","ELECTRIC","ELECTRIC","GRASS","GRASS","GROUND","GROUND","FIGHT","FIGHT","NORMAL","POISON","POISON","GROUND","GROUND","NORMAL","GRASS","NORMAL","WATER","WATER","WATER","WATER","WATER","WATER","PSYCHO","BUG","ICE","ELECTIC","FIRE","BUG","NORMAL","WATER","WATER","WATER","NORMAL","NORMAL","WATER","ELECTRIC","FIRE","NORMAL","ROCK","ROCK","ROCK","ROCK","ROCK","NORMAL","ICE","ELECTRIC","FIRE","DRAGON","DRAGON","DRAGON","PSYCHO","PSYCHO"},
    /*TIPE 2 */         {"", "POISON","POISON","POISON","","","FLYING","","","","","","FLYING","POISON","POISON","POISON","FLYING","FLYING","FLYING","","","FLYING","FLYING","","","","","","","","","GROUND","","","GROUND","","","","","FAIRY","FAIRY","FLYING","FLYING","POISON","POISON","POISON","GRASS","GRASS","POISON","POISON","","","","","","","","","","","","","FIGHT","","","","","","","POISON","POISON","POISON","POISON","POISON","GROUND","GROUND","GROUND","","","PSYCHO","PSYCHO","STEEL","STEEL","FLYING","FLYING","FLYING","","ICE","","","","ICE","POISON","POISON","POISON","GROUND","","","","","","","PSYCHO","PSYCHO","","","","","","","","ROCK","ROCK","","","","","","","","","PSYCHO","FAIRY","FLYING","PSYCHO","","","","","","FLYING","ICE","","","","","","","WATER","WATER","WATER","WATER","FLYING","","FLYING","FLYING","FLYING","","","FLYING","",""}
    };

    int numMenu = 1;
    string id, nama;
    adrTrainer r;
    adrPocket q;
    adrPokemon s;
    /*
    (Metode pengubahan string ke int)
    int r;
    string id = "1";
    stringstream obj;
    obj << id;
    obj >> r;
    cout << id;
    cout << r + 1;
    */
    ListPokemon L;
    ListTrainer T;
    first(T) = NULL;
    addPokemon(L, p);
    while(numMenu != 0){
        //Spek Menu
        cout <<"---------------------MENU-----------------------------" << endl;
        cout <<"1. Add Trainer" << endl;
        cout <<"2. Show Trainer" << endl;
        cout <<"3. Select Trainer" << endl;
        cout <<"4. Show Trainer Detail" << endl;
        cout <<"5. Catch Pokemon" << endl;
        cout <<"6. Trade Pokemon" << endl;
        cout <<"7. Show All Pokemon" << endl;
        cout <<"0. Exit" << endl;
        cout <<"------------------------------------------------------" << endl;
        cout <<"Masukan Nomor Menu: ";
        cin >> numMenu;
        switch(numMenu){
        case 1:
            cout << "Masukan ID: ";
            cin >> id;
            cout <<"Masukan nama: ";
            cin >> nama;
            r = createNodeTrainer(id,nama);
            insertLastTrainer(T, r);
            break;
        case 2:
            showAllTrainer(T,L);
            break;
        case 3:
            cout << "Masukan id: ";
            cin >> id;
            r = selectTrainer(T, id);
            break;
        case 4:
            break;
        case 5:
            break;
        case 6:
            break;
        case 7:
            break;
        }
    }
    cout <<"Game Ended" << endl;
}
